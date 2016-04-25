#include "crepr.h"
#include "assert.h"
#include "parse_long.h"
#include "debug.h"
#include "mpi_utils.h"

#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

#define MAX_VAR 127
/* == MAX_VAR because vars start at 1*/
#define MAX_NUM_VARS MAX_VAR
#define MAX_NUM_VARS_CLAUSE 20
/* 4 because MAX_VAR is 127 and could be -127*/
#define MAX_VAR_STR_SIZE 4
#define MAX_NUM_CLAUSES 65535

/*These fixme just mark the spot where "project specific" cosntraints are abused to optimized space
 *FIXME: var_clauses_index depends on MAX_NUM_VARS_CLAUSE MAX_NUM_CLAUSES
 *FIXME: var_clauses depends on MAX_NUM_CLAUSES
 *FIXME: clauses_index depends on MAX_NUM_VARS_CLAUSE MAX_NUM_CLAUSES
 *FIXME: clauses depends on MAX_NUM_VAR
 *FIXME: num_clauses depends on MAX_NUM_CLAUSES
 *FIXME: num_vars depends on MAX_VAR*/
struct crepr {
    /*saves which clauses a variable is in*/
    uint32_t *var_clauses_index; /*max 20 vars/clause, max 65535 clauses. 20*65536 can be index with uint32_t*/
    uint16_t *var_clauses; /*max 65535 clause, can be indexed with uint16_t*/

    /*saves all clauses, by number*/
    uint32_t *clauses_index; /*see var_clauses_index*/
    int8_t *clauses; /*max 127 vars, negative is represented with 8th bit, so int8_t */

    uint16_t num_clauses;
    uint8_t num_vars;
};

/*Structs for internal functions*/

struct var_count {
    uint8_t num_vars;
    size_t *var_uses; /*size because we don't send over openmpi*/
    uint64_t total_num_vars;
    uint16_t num_clauses;
    bool success;
};


static char *file_to_string(const char *file_path);
static struct var_count var_count(const char *file_text);
static bool allocate_crepr_arrays(struct crepr *crepr, struct var_count var_count);
static void parse_clauses(const char *file_text,
                          uint32_t *clauses_index,
                          int8_t *clauses);
static void fill_var_clauses_index(struct var_count var_count,
                                   const uint32_t *clauses_index,
                                   const int8_t *clauses,
                                   uint32_t *var_clauses_index,
                                   uint16_t *var_clauses);

/*
 * Implementation of public functions
 */

struct new_crepr new_crepr (const char *file_path) {
    /* We read the file two times.
     * The first time we find out the total number of varibles, clauses, etc
     * Then we alloc the memory,
     * The second time we fill the data structures*/
    struct new_crepr ret = {.success = true, .crepr = NULL};
    char *file_text = NULL;
    struct var_count var_count_ret = {.var_uses = NULL};
    int mpi_ret;

    /*This is done by everyone*/
    ret.crepr = malloc(sizeof(*(ret.crepr)) * 1);
    ASSERT_NON_NULL(ret.crepr);

    if(is_mpi_master()) {
        file_text = file_to_string(file_path);
        ASSERT_NON_NULL(file_text);

        var_count_ret = var_count(file_text);
        ASSERT_MSG(var_count_ret.success, "");

    }

    mpi_ret = MPI_Bcast(&(var_count_ret.num_vars), 1, MPI_UINT8_T, 0, MPI_COMM_WORLD);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed to broadcast num_vars");

    MPI_Bcast(&(var_count_ret.num_clauses), 1, MPI_UINT16_T, 0, MPI_COMM_WORLD);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed to broadcast num_clauses");

    MPI_Bcast(&(var_count_ret.total_num_vars), 1, MPI_UINT64_T, 0, MPI_COMM_WORLD);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed to broadcast total_num_vars");

    (ret.crepr)->num_vars = var_count_ret.num_vars;
    (ret.crepr)->num_clauses = var_count_ret.num_clauses;
    LOG_DEBUG("after bcast num_vars:%" PRIu8 " num_clauses:%" PRIu16 " total_num_vars:%" PRIu64,
              (ret.crepr)->num_vars,
              (ret.crepr)->num_clauses,
              var_count_ret.total_num_vars);

    ASSERT_MSG(allocate_crepr_arrays(ret.crepr, var_count_ret), "");


    if (is_mpi_master()) {
        parse_clauses(file_text, ret.crepr->clauses_index, ret.crepr->clauses);
        fill_var_clauses_index(var_count_ret,
                               ret.crepr->clauses_index,
                               ret.crepr->clauses,
                               ret.crepr->var_clauses_index,
                               ret.crepr->var_clauses);
    }

    MPI_Bcast((ret.crepr)->clauses, var_count_ret.total_num_vars, MPI_INT8_T, 0, MPI_COMM_WORLD);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed to broadcast clauses");

    MPI_Bcast((ret.crepr)->clauses_index, var_count_ret.num_clauses + 1, MPI_UINT32_T, 0, MPI_COMM_WORLD);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed to broadcast clauses_index");

    MPI_Bcast((ret.crepr)->var_clauses, var_count_ret.total_num_vars, MPI_UINT16_T, 0, MPI_COMM_WORLD);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed to broadcast clauses");

    MPI_Bcast((ret.crepr)->var_clauses_index, var_count_ret.num_vars + 2, MPI_UINT32_T, 0, MPI_COMM_WORLD);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed to broadcast clauses_index");


    if (is_mpi_master()) {
        free(file_text);
        free(var_count_ret.var_uses);
    }

    return ret;

on_error:
    if (ret.crepr != NULL) {
        free_crepr(ret.crepr);
    }
    if (file_text != NULL) {
        free(file_text);
    }
    if (var_count_ret.var_uses != NULL) {
        free(var_count_ret.var_uses);
    }
    ret.success = false;
    return ret;
}

struct crepr_clauses_of crepr_clauses_of(const struct crepr *crepr, uint8_t var) {
    struct crepr_clauses_of ret;

    ret.len = crepr->var_clauses_index[var + 1] - crepr->var_clauses_index[var];
    if (ret.len > 0) {
        ret.first = &(crepr->var_clauses[crepr->var_clauses_index[var]]);
    } else {
        ret.first = NULL;
    }

    return ret;
}

struct crepr_clause crepr_clause(const struct crepr *crepr, uint16_t clause) {
    struct crepr_clause ret;

    ret.len = crepr->clauses_index[clause + 1] - crepr->clauses_index[clause];
    if (ret.len > 0) {
        ret.first = &(crepr->clauses[crepr->clauses_index[clause]]);
    } else {
        ret.first = NULL;
    }

    return ret;
}

void free_crepr(struct crepr *crepr) {
    ASSERT_NON_NULL(crepr);

    /*Doing with checks because constructor might call this with half built stuff*/
    if(crepr->clauses != NULL) {
        free(crepr->clauses);
    }
    if(crepr->clauses_index != NULL) {
        free(crepr->clauses_index);
    }
    if(crepr->var_clauses != NULL) {
        free(crepr->var_clauses);
    }
    if(crepr->var_clauses_index != NULL) {
        free(crepr->var_clauses_index);
    }

    free(crepr);

    return;
on_error:
    ASSERT_EXIT();
}

uint8_t crepr_num_vars(const struct crepr *crepr) {
    ASSERT_NON_NULL(crepr);
    return crepr->num_vars;

on_error:
    ASSERT_EXIT();
}

uint16_t crepr_num_clauses(const struct crepr *crepr) {
    ASSERT_NON_NULL(crepr);
    return crepr->num_clauses;

on_error:
    ASSERT_EXIT();
}

/*
 * private functions
 */

static char *file_to_string(const char *file_path) {
    char *file_text = NULL;
    size_t file_size = 0;

    FILE *file = fopen(file_path, "r");
    ASSERT_MSG(file != NULL, "Failed to open file.");

    fseek(file, 0L, SEEK_END);
    long int ftell_size = ftell(file);
    ASSERT_MSG(ftell_size > 0, "");
    file_size = ftell_size;

    rewind(file);
    /*In the worst case we'll allocate ~6MB*/
    file_text = malloc(sizeof(*file_text) * (file_size + 1));
    ASSERT_NON_NULL(file_text);
    size_t num_read = fread(file_text, sizeof(*file_text), file_size, file);
    ASSERT_MSG(num_read == file_size, "Couldn't read whole file.");
    file_text[file_size] = '\0';
    LOG_DEBUG("file_size: %zu", file_size);

    fclose(file);

    return file_text;

on_error:
    if(file != NULL) {
        fclose(file);
    }
    if(file_text != NULL) {
        free(file_text);
    }
    return NULL;
}

static struct var_count var_count(const char *file_text) {
    struct var_count ret = { .num_vars = 0,
                             .var_uses = NULL,
                             .total_num_vars = 0,
                             .num_clauses = 0,
                             .success = true};
    struct parse_long parsed_long;
    size_t seen_num_clauses = 0;

    parsed_long = parse_long(file_text);
    ASSERT_MSG(parsed_long.success, "Failed to parse num vars");
    ASSERT_MSG_VA(parsed_long.value >= 1
                  && parsed_long.value <= MAX_NUM_VARS,
                  "Number of variables not within bounds: num_vars '%zu'",
                  parsed_long.value);
    ret.num_vars = parsed_long.value;
    LOG_DEBUG("read num_vars: %"PRIu8, ret.num_vars);

    parsed_long = parse_long(parsed_long.str_next_pos);
    ASSERT_MSG(parsed_long.success, "Failed to parse num clauses");
    ASSERT_MSG_VA(parsed_long.value >= 1
                  && parsed_long.value <= MAX_NUM_CLAUSES,
                  "Number of clauses not within bounds: expected_num_clauses '%zu'",
                  parsed_long.value);
    ret.num_clauses = parsed_long.value;
    LOG_DEBUG("read num_clauses: %"PRIu16, ret.num_clauses);

    ret.var_uses = calloc(ret.num_vars + 1, sizeof(*(ret.var_uses)));
    ASSERT_NON_NULL(ret.var_uses);

    size_t num_vars_clause = 0;
    const char *last_str = NULL;
    while(true) {
        last_str = parsed_long.str_next_pos;
        parsed_long = parse_long(parsed_long.str_next_pos);

        if(!parsed_long.success && strlen(last_str) < MAX_VAR_STR_SIZE) {
            break;
        }

        ASSERT_MSG_VA(parsed_long.success, "Failed to parse clauses. Missing strlen: '%zu'", strlen(last_str));
        ASSERT_MSG(parsed_long.value <= INT8_MAX
                   && parsed_long.value >= INT8_MIN,
                   "Parsed variable too big. Doesn't fit in byte");
        if(parsed_long.value == 0) {
            ++seen_num_clauses;

            num_vars_clause = 0;
        } else {
            ASSERT_MSG(labs(parsed_long.value) >= 1
                    && labs(parsed_long.value) <= (long int) ret.num_vars, /*FIXME*/
                    "Variable bigger than num_vars");
            ++((ret.var_uses)[labs(parsed_long.value)]);
            ++(ret.total_num_vars);
            ++num_vars_clause;
            ASSERT_MSG(num_vars_clause <= MAX_NUM_VARS_CLAUSE,
                       "Too many vars in clause");
        }
    }


    ASSERT_MSG_VA(ret.num_clauses == seen_num_clauses,
                  "Counted num clauses differs from read. counted:'%zu' read:'%" PRIu16 "'",
                  seen_num_clauses,
                  ret.num_clauses);

    return ret;

on_error:
    if (ret.var_uses != NULL) {
        free(ret.var_uses);
    }
    ret.success = false;
    return ret;
}


static bool allocate_crepr_arrays(struct crepr *crepr, struct var_count var_count) {
    ASSERT_NON_NULL(crepr);

    crepr->clauses = malloc(sizeof(*(crepr->clauses))
                            * (var_count.total_num_vars));
    ASSERT_NON_NULL(crepr->clauses);

    /* +1 because we index with clauses_index[i] and [i+1] */
    crepr->clauses_index = malloc(sizeof(*(crepr->clauses_index))
                                  * (var_count.num_clauses + 1));
    ASSERT_NON_NULL(crepr->clauses_index);

    crepr->var_clauses = malloc(sizeof(*(crepr->var_clauses))
                                * (var_count.total_num_vars));
    ASSERT_NON_NULL(crepr->var_clauses);

    /* +2 because we don't use var 0 and +1 reason above. */
    crepr->var_clauses_index = malloc(sizeof(*(crepr->var_clauses_index))
                                      * (var_count.num_vars + 2));
    ASSERT_NON_NULL(crepr->var_clauses_index);

    return true;

on_error:
    /*Memory freed by new_crepr*/
    return false;
}


static void parse_clauses(const char *file_text,
                          uint32_t *clauses_index,
                          int8_t *clauses) {
    struct parse_long parsed_long;

    /*Not checking parsed_long.success because var_count already did */
    /*skip num_vars and num_clauses*/
    parsed_long = parse_long(file_text);
    parsed_long = parse_long(parsed_long.str_next_pos);

    int8_t *cur_clauses = clauses;
    const char *last_str = NULL;

    *clauses_index = 0;
    ++clauses_index;
    while(true) { /*FIXME*/
        last_str = parsed_long.str_next_pos;
        parsed_long = parse_long(parsed_long.str_next_pos);

        if(!parsed_long.success && strlen(last_str) < MAX_VAR_STR_SIZE) {
            break;
        }
        if(!parsed_long.success) {
            ASSERT_EXIT();
        }


        if(parsed_long.value == 0) {
            *clauses_index = (cur_clauses - clauses);
            ++clauses_index;
        } else {
            *cur_clauses = parsed_long.value;
            ++cur_clauses;
        }

    }
}

/*Builds the var_clauses_index. Conceptually it's an associative array of var -> list of clauses....
 *We implement as a pair of arrays like clauses_index.
 */
static void fill_var_clauses_index(struct var_count var_count,
                                   const uint32_t *clauses_index,
                                   const int8_t *clauses,
                                   uint32_t *var_clauses_index,
                                   uint16_t *var_clauses) {

    var_clauses_index[0] = 0; /*skip var 0*/
    var_clauses_index[1] = 0; /*var 1 start at position 0*/
    { /*fill var_clauses_index*/
        uint8_t var;
        /* '<=' is not a bug, it fills the sentinel position of var_clauses_index*/
        for(var = 2; var <= (var_count.num_vars + 1); ++var) {
            var_clauses_index[var] = var_clauses_index[var - 1] + (var_count.var_uses)[var - 1];
        }
    }

    size_t clause;
    /*cur pos between clauses_index[var] and clauses_index[var+1]*/
    size_t cur_var_clause[var_count.num_vars + 1];
    memset(cur_var_clause, 0, sizeof(cur_var_clause));

    for(clause = 0; clause < var_count.num_clauses; ++clause) {
        uint32_t first_var_pos = clauses_index[clause];
        uint32_t last_var_pos = clauses_index[clause + 1];
        //LOG_DEBUG("clause:%zu first_var_pos: %" PRIu32 " last_var_pos: %" PRIu32, clause, first_var_pos, last_var_pos);
        size_t var_pos;
        for(var_pos = first_var_pos; var_pos < last_var_pos; ++var_pos) {
            uint8_t var = labs(clauses[var_pos]);
            var_clauses[var_clauses_index[var] + cur_var_clause[var]] = clause;
            ++cur_var_clause[var];
        }
    }
    return;
}

#undef MAX_VAR
#undef MAX_NUM_VARS
#undef MAX_NUM_VARS_CLAUSE
#undef MAX_VAR_STR_SIZE
#undef MAX_NUM_CLAUSES
