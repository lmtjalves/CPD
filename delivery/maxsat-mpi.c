/*This file was automatically merged that's why it might look weird.*/
/*********************************Start of main.c**********************************/

/********************************Start of assert.h*********************************/
#ifndef ASSERT_H__
#define ASSERT_H__


/*********************************Start of debug.h*********************************/
#ifndef DEBUG_H__
#define DEBUG_H__
/* Inspired in c.learncodethehardway.org/book/ex20.html */

#include <stdio.h>
#include <errno.h>
#include <string.h>

/*Implementation*/

#define DEBUG_LEVEL_NO_DEBUG -10
#define DEBUG_LEVEL_ERROR 0
#define DEBUG_LEVEL_WARN 10
#define DEBUG_LEVEL_INFO 20
#define DEBUG_LEVEL_DEBUG 30


/*if DEBUG_LOG_LEVEL is not defined at compile time we assume runtime debug option.*/
#ifndef DEBUG_LOG_LEVEL
extern int debug_log_level;
#define DEBUG_LOG_LEVEL debug_log_level
/*maybe we should do some checking*/
#define DEBUG_SET_LEVEL(LEVEL) \
do { \
    debug_log_level = LEVEL; \
} while(0)

#else 
/*no need to define DEBUG_LOG_LEVEL because it's already defined*/
#define DEBUG_SET_LEVEL(LEVEL) LOG_ERROR("Trying to set debug level when debug is compile time set.%s", "")
#endif

#define DEBUG_CLEAN_ERRNO() (errno == 0 ? "None" : strerror(errno))

#define DEBUG_REAL_LOG_GENERIC(LOG_TYPE, MESSAGE, ...) \
    do {\
        if (errno == 0) { \
            fprintf(stderr, LOG_TYPE " (%s:%5d) " MESSAGE "\n", __FILE__, __LINE__,  __VA_ARGS__);\
        } else { \
            fprintf(stderr, LOG_TYPE " (%s:%5d: errno: %s) " MESSAGE "\n", __FILE__, __LINE__, DEBUG_CLEAN_ERRNO(), __VA_ARGS__);\
            errno = 0; \
        } \
    } while(0)


/*Defined so we don't have to put "" at the end of every LOG*. It's used to allow for no arguments*/
#define DEBUG_LOG_GENERIC(LOG_TYPE, LEVEL, MESSAGE, ...) \
    do { \
        if ( LEVEL <= DEBUG_LOG_LEVEL) { \
            DEBUG_REAL_LOG_GENERIC(LOG_TYPE, MESSAGE "%s", __VA_ARGS__, " "); \
        } \
    } while(0)





/* Public interface */
#define LOG_ERROR(MESSAGE, ...) DEBUG_LOG_GENERIC("[ERROR]", DEBUG_LEVEL_ERROR, MESSAGE, __VA_ARGS__)
#define LOG_WARN(MESSAGE, ...) DEBUG_LOG_GENERIC("[WARN]", DEBUG_LEVEL_WARN, MESSAGE, __VA_ARGS__)
#define LOG_INFO(MESSAGE, ...) DEBUG_LOG_GENERIC("[INFO]", DEBUG_LEVEL_INFO, MESSAGE, __VA_ARGS__)
#define LOG_DEBUG(MESSAGE, ...) DEBUG_LOG_GENERIC("[DEBUG]", DEBUG_LEVEL_DEBUG, MESSAGE, __VA_ARGS__)

#endif /*DEBUG_H__*/

/**********************************End of debug.h**********************************/

/*********************************Start of debug.c*********************************/

int debug_log_level = DEBUG_LEVEL_NO_DEBUG;

/**********************************End of debug.c**********************************/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


#define ASSERT_MSG_VA(EXPR, MSG, ...) \
    do {\
        if (!(EXPR)) {\
            LOG_ERROR("Evaluation of '" #EXPR "' failed. ||| "  MSG, __VA_ARGS__);\
            goto on_error; /*Error handling*/\
        } \
    } while (0)

#define ASSERT_MSG(EXPR, MSG) ASSERT_MSG_VA(EXPR, MSG "%s", "")

#define ASSERT(EXPR) ASSERT_MSG(EXPR, "")

#define ASSERT_NON_NULL(EXPR) ASSERT_MSG(EXPR, "A null pointer was passed as argument.")

#define ASSERT_EXIT() \
    do { \
        LOG_ERROR("Reached point of no return. Exiting.%s", ""); \
        exit(1); \
    } while(0)

#define ASSERT_ERROR(MSG) \
    do { \
        ASSERT_MSG(false, MSG); \
    } while(0)


#endif /*ASSERT_H__*/

/*********************************End of assert.h**********************************/

/******************************Start of assignment.h*******************************/
#ifndef ASSIGNMENT_H__
#define ASSIGNMENT_H__

#include <inttypes.h>
#include <stdbool.h>

/* We want 128 bits because there are at most 128 variables.
 * We save the state of a variable in a bit.*/
struct assignment {
    uint64_t vars[2];
};

struct assignment new_stack_assignment(void);
struct assignment new_stack_assignment_from_num(uint64_t num[2]); /*num[0] has the highest bits, num[1] has the lowest bits read from right to left */
bool assignment_get_var(struct assignment assignment, uint8_t var);
void assignment_set_var(struct assignment *assignment, uint8_t var, bool value);

#endif /*ASSIGNMENT_H__*/

/*******************************End of assignment.h********************************/

/******************************Start of assignment.c*******************************/

#define GET_BIT(VALUE, BIT_NUM) (((VALUE) >> (BIT_NUM)) & 1)
#define UINT8_MASK(VALUE) ((VALUE) & 0x3F)
#define MAX_BIT 127

/* We want 128 bits because there are at most 128 variables.
 * We save the state of a variable in a bit.*/

struct assignment new_stack_assignment(void) {
    struct assignment ret = { .vars = {0,0}};
    return ret;
}

/* Assumes big_num = num[0] num[1], so v0 = num[1][0], v1 = num[1][1], ... v63=num[1][63]*/
struct assignment new_stack_assignment_from_num(uint64_t num[2]) {
    struct assignment ret = new_stack_assignment();

    size_t var = 0;
    int num_i; /*int :'(*/
    for(num_i = 1; num_i >= 0; --num_i) { 
        size_t bit_i;
        for(bit_i = 0; bit_i < 64; ++bit_i) {
            assignment_set_var(&ret, var, GET_BIT(num[num_i], bit_i));
            ++var;
        }
    }

    return ret;
}

bool assignment_get_var(struct assignment assignment, uint8_t var) {
    ASSERT(var <= MAX_BIT);

    /*We want 0 if var < 64, and 1 if var >= 64, so we extract the 6th bit since 64 = 0100 0000 */
    size_t index = GET_BIT(var, 6);

    return GET_BIT(assignment.vars[index], UINT8_MASK(var)) == 1;

on_error:
    ASSERT_EXIT();
}

void assignment_set_var(struct assignment *assignment, uint8_t var, bool bool_value) {
    ASSERT_NON_NULL(assignment);
    ASSERT(var <= MAX_BIT);

    uint64_t value = bool_value ? 1 : 0;
    /*We want 0 if var < 64, and 1 if var >= 64, so we extract the 6th bit since 64 = 0100 0000 */
    size_t index = GET_BIT(var, 6);
    assignment->vars[index] = ((~( ((uint64_t) 1) << UINT8_MASK(var))) & assignment->vars[index]) | (value << UINT8_MASK(var));

    return;

on_error:
    ASSERT_EXIT();
}

#undef GET_BIT
#undef UINT8_MASK
#undef MAX_BIT

/*******************************End of assignment.c********************************/

/*********************************Start of crepr.h*********************************/
#ifndef CREPR_H__
#define CREPR_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct crepr;

struct new_crepr {
    struct crepr *crepr;
    bool success;
};

/*Representation for the return of crepr_clauses_of. Represents a list of clauses_num to be fetch by crepr_clause */
struct crepr_clauses_of {
    size_t len;
    const uint16_t *first;
};

/*Representation for the return of crepr_clause. Represents a list of vars of a clause*/
struct crepr_clause {
    size_t len;
    const int8_t *first;
};

struct new_crepr new_crepr(const char *file_path);
void free_crepr(struct crepr *crepr);
struct crepr_clauses_of crepr_clauses_of(const struct crepr *crepr, uint8_t var);
struct crepr_clause crepr_clause(const struct crepr *crepr, uint16_t clause);
uint8_t crepr_num_vars(const struct crepr *crepr);
uint16_t crepr_num_clauses(const struct crepr *crepr);

#endif

/**********************************End of crepr.h**********************************/

/*********************************Start of crepr.c*********************************/

/******************************Start of parse_long.h*******************************/
#ifndef PARSE_LONG_H__
#define PARSE_LONG_H__

#include <stdbool.h>

struct parse_long {
    const char *str_next_pos;
    long int value;
    bool success;
};

struct parse_long parse_long(const char *str);

#endif

/*******************************End of parse_long.h********************************/

/******************************Start of parse_long.c*******************************/

#include <stdlib.h>
#include <errno.h>
#include <limits.h>

struct parse_long parse_long(const char *str) {
    char *end_str;
    long int value;

    /*FIXME: check if errno was previously not 0*/
    errno = 0;

    value = strtol(str, &end_str, 0);

    /*If there were no digits at all, strtoul() stores the original value of nptr in *endptr (and returns 0)*/
    /*unless the original (nonnegated)  value would overflow; in the latter case, strtoul() returns ULONG_MAX and sets errno to ERANGE */
    if ( (value == 0 && str == end_str) || ( (value == LONG_MAX || value == LONG_MIN) && errno == ERANGE)) {
        struct parse_long ret = { .str_next_pos = NULL, .value = 0, .success = false };
        return  ret;
    }

    struct parse_long ret = {.str_next_pos = end_str, .value = value, .success = true};
    return ret;
}

/*******************************End of parse_long.c********************************/

/*******************************Start of mpi_utils.h*******************************/
#ifndef MPI_UTILS_H
#define MPI_UTILS_H

#include <stdbool.h>
#include <stddef.h>

// Utilitary functions to make the code more readable.
bool is_mpi_master();
bool is_mpi_slave();

size_t mpi_rank();
size_t mpi_size();
size_t mpi_master();

#endif

/********************************End of mpi_utils.h********************************/

/*******************************Start of mpi_utils.c*******************************/

#include <mpi.h>

bool is_mpi_master() {
  return mpi_rank() == 0;
}

bool is_mpi_slave() {
  return mpi_rank() != 0;
}

size_t mpi_rank() {
    int mpi_ret, mpi_rank;

    mpi_ret = MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS && mpi_rank >= 0, "Failed to get mpi_rank.");

    return mpi_rank;

on_error:
    ASSERT_EXIT();
}

size_t mpi_size() {
    int mpi_ret, mpi_size;
    mpi_ret = MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS && mpi_size > 0, "Failed to get mpi_size.");

    return mpi_size;

on_error:
    ASSERT_EXIT();
}

size_t mpi_master() {
    return 0;
}

/********************************End of mpi_utils.c********************************/

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

/**********************************End of crepr.c**********************************/

/********************************Start of clauses.h********************************/
#ifndef CLAUSES_H__
#define CLAUSES_H__


/********************************Start of result.h*********************************/
#ifndef RESULT_H__
#define RESULT_H__


#include <stdio.h>
#include <string.h>

struct result {
	uint16_t maxsat_value; //FIXME depends on MAX_NUM_CLAUSES. see clauses_repr.c
	uint64_t na; //number of complete variable assignments that achieve MAXSAT
	struct assignment sample; //one sample of the assignments that achieve MAXSAT
};

struct result new_stack_result(void);

uint16_t result_maxsat (struct result *result);
void result_set_maxsat (struct result *result, uint16_t new_maxsat_value);

uint64_t result_na (struct result *result);
void result_set_na (struct result *result, uint64_t number_assignments);

struct assignment result_assignment(struct result *result);
void result_set_assignment(struct result *result, struct assignment new_sample);

void result_update(struct result *result, uint16_t new_maxsat_value, struct assignment new_sample);

#endif /*RESULT_H__*/

/*********************************End of result.h**********************************/

/********************************Start of result.c*********************************/

struct result new_stack_result(void){

  struct result res = { .maxsat_value = 0,
                        .na = 0,
                        res.sample = new_stack_assignment()
                      };
  return res;
}

uint16_t result_maxsat (struct result *result){
  ASSERT_NON_NULL(result);
	
	return result->maxsat_value;

  on_error:
  ASSERT_EXIT();
}

void result_set_maxsat (struct result *result, uint16_t new_maxsat_value){
  ASSERT_NON_NULL(result);

  result->maxsat_value = new_maxsat_value;

  return;

  on_error:
  ASSERT_EXIT();
}

uint64_t result_na (struct result *result){
  ASSERT_NON_NULL(result);

  return result->na;

  on_error:
  ASSERT_EXIT();
}

void result_set_na (struct result *result, uint64_t number_assignments){
  ASSERT_NON_NULL(result);

  result->na = number_assignments;

  return;

  on_error:
  ASSERT_EXIT();
}

struct assignment result_assignment(struct result *result){
  ASSERT_NON_NULL(result);

  return result->sample;

  on_error:
  ASSERT_EXIT();
}

void result_set_assignment(struct result *result, struct assignment new_sample){
  ASSERT_NON_NULL(result);

  result->sample = new_sample;

  return;

  on_error:
  ASSERT_EXIT();
}

void result_update(struct result *result, uint16_t new_maxsat_value, struct assignment new_sample){
  ASSERT_NON_NULL(result);
	
  if (new_maxsat_value == result->maxsat_value){
      (result->na)++;
  } else if (new_maxsat_value > result->maxsat_value){
      {
      	  result->maxsat_value = new_maxsat_value;
      	  result->sample = new_sample;
      	  result->na = 1;
      }
  }

  return;
  on_error:
  	ASSERT_EXIT();
}

/*********************************End of result.c**********************************/

/* Returns the maxsat of the given group of clauses.
*/
struct result maxsat(const struct crepr *crepr);

#endif /*CLAUSES_H__*/

/*********************************End of clauses.h*********************************/

/********************************Start of clauses.c********************************/

#include <mpi.h>
#include <omp.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

/*calculated_clauses_filter:
 * Array that keep track of the state of a clause value.
 * A value of 0 represents that the clause's value could still be positive
 * A value >0 represents the FIRST variable that makes the clause positive
 * A value <0 represents the LAST variable such that after it being set,
 *  all the variables in the clause have a value, and they're all negative.*/
struct clauses {
    const struct crepr* crepr;
    struct assignment assignment;
    uint8_t last_assigned_var;
    int8_t *calculated_clauses_filter;
    uint16_t num_true_clauses;
    uint16_t num_false_clauses;
    uint16_t num_unknown_clauses;
};



/*Ancillary macros for initing and allocing struct clauses in the stack*/
/*Not insied do{}while(0) because that'd release the array memory*/
#define ALLOC_LOCAL_CLAUSES(CLAUSES, CREPR) \
int8_t calculated_clauses_filter_ ## CLAUSES [crepr_num_clauses(CREPR)];\
CLAUSES.calculated_clauses_filter = calculated_clauses_filter_ ## CLAUSES

#define INIT_LOCAL_CLAUSES(CLAUSES, CREPR, ASSIGNMENT, LAST_ASSIGNED_VAR) \
do { \
    CLAUSES.crepr = CREPR; \
    CLAUSES.assignment = ASSIGNMENT; \
    CLAUSES.last_assigned_var = LAST_ASSIGNED_VAR; \
    memset(CLAUSES.calculated_clauses_filter, 0 , crepr_num_clauses(CREPR) * sizeof(int8_t)); \
    CLAUSES.num_true_clauses = 0; \
    CLAUSES.num_false_clauses = 0; \
    CLAUSES.num_unknown_clauses = crepr_num_clauses(CREPR); \
} while(0)



/*private functions*/

/*ways to solve maxsat*/
void maxsat_single(const struct crepr *crepr, struct result *result);
void maxsat_master(const struct crepr *crepr, struct result *result);
void maxsat_slave(const struct crepr *crepr);

/*master/slave communication*/
/*problem step*/
void maxsat_problem_send(uint64_t *msg, int dest);
void maxsat_problem_recv(uint64_t *msg, int source);
void slave_request_problem(struct result *result,
                           uint64_t *prob,
                           size_t *num_init_vars);
void master_give_problem(struct result *result,
                         uint64_t prob,
                         uint64_t num_init_vars);

/*problem splitting*/
uint8_t num_bit_len(int num);

void maxsat_prob_division(const uint8_t num_vars,
                          const size_t num_workers,
                          uint64_t *num_problems,
                          uint64_t *num_init_vars);

/*ancillary*/
void sync_result(struct result *result, struct result *sync_result);

/*maxsat solving functions*/
void do_maxsat(const struct crepr *crepr, struct result *result, uint8_t num_init_vars, uint64_t prob);
void partial_maxsat(struct clauses *clauses, struct result *result);
void do_partial_maxsat(struct clauses *clauses, struct result *result, uint8_t var);
bool should_prune(struct clauses *clauses, struct result *result);
void rollback_assignment_to_var(struct clauses *clauses, uint8_t var);
void eval_var_clauses(struct clauses *clauses, uint8_t var);
void eval_clause(struct clauses *clauses, uint16_t clause_id);





/* Public function */

struct result maxsat(const struct crepr *crepr) {
    ASSERT_NON_NULL(crepr);
    struct result result = new_stack_result();

    if (mpi_size() == 1) {
        maxsat_single(crepr, &result);
    } else if (is_mpi_master()) {
        maxsat_master(crepr, &result);
    } else {
        maxsat_slave(crepr);
    }

    LOG_DEBUG("mpi:%zu finished maxsat. maxsat:%"PRIu16" na:%"PRIu64" assignment:%.16"PRIx64" %.16"PRIx64,
              mpi_rank(),
              result_maxsat(&result),
              result_na(&result),
              result_assignment(&result).vars[1], /*FIXME?*/
              result_assignment(&result).vars[0]);

    return result;

on_error:
    ASSERT_EXIT();
}


/*
 *
 * Private functions
 *
 */



/*
 *
 * ways to solve maxsat
 *
 */

/*Solves the maxsat withotu using mpi*/
void maxsat_single(const struct crepr *crepr, struct result *result) {
    do_maxsat(crepr, result, 0, 0);
}

/* The protocol is the following:
 *
 * A slave sends a request to master, in the format: |mpi_rank|maxsat|na|a[0]|a[1]|
 *  mpi_rank is it's mpi_rank, so the master know who to send the problem to.
 *  maxsat is it's current best maxsat,
 *  na is the number of assignments it for that maxsat it got in the last problem.
 *  a is a maxsat assignment
 *
 * The master answers a request in the format: |prob|num_init_vars|maxsat|0|0|
 *  prob is the problem the slave must solve
 *  num_init_vars is self explanatory
 *  maxsat is the value of the best maxsat it has seen until now.
 *
 * Master uses sync_result to sync the maxsat, na and assignment given by
 *  the slave with it's result.
 * Slave registers the maxsat if it's better than the one it has.
 *
 * When there are no more problems, the master answers with UINT_MAX64.
 * This signals the slave to stop solving problems.
 * Then the master moves on and the slaves stopped eventually.
 * */

/* slave:  |rank|maxsat|na|assignment[0]|assignment[1]|
 * master: |prob|vars|maxsat|0|0| the 0s are so that we use the same len*/
const int PROBLEM_REQUEST_LEN = 5;
const int PROBLEM_REQUEST_TAG = 1000;

/* no tag needed since it's a broadcast
 * |maxsat|na|assignment[0]|assignment[1]*/
const int MAXSAT_SYNC_LEN = 4;

void maxsat_master(const struct crepr *crepr, struct result *result) {
    uint64_t num_problems, num_init_vars;

    maxsat_prob_division(crepr_num_vars(crepr),
                         mpi_size() - 1, /*-1 because the master isn't a worker*/
                         &num_problems,
                         &num_init_vars);

    LOG_DEBUG("Distributing %"PRIu64 " problems with %"PRIu64" initialized vars.",
              num_problems,
              num_init_vars);

    uint64_t cur_problem = 0;
    while(cur_problem < num_problems) {
        master_give_problem(result, cur_problem, num_init_vars);
        ++cur_problem;
    }

    double sync_start_time = omp_get_wtime();

    uint64_t num_shutdown_sent = 0;
    while(num_shutdown_sent < (mpi_size() - 1)) {
        master_give_problem(result, UINT64_MAX, 0);
        ++num_shutdown_sent;
    }

    LOG_DEBUG("mpi:%zu took %fs to sync.", mpi_rank(), omp_get_wtime() - sync_start_time);

    return;

}


void maxsat_slave(const struct crepr *crepr) {
    struct result slave_result = new_stack_result();
    LOG_DEBUG("mpi:%zu Solving maxsat!", mpi_rank());

    /*Only accessed by omp master*/
    double total_req_time = 0, total_computation_time = 0, total_thread_wait_time = 0;
    double start_computation_time;

    /*These are accessed by all threads at the end of each loop.
     * They're initialized by the master in the beginning*/
    double start_time;

    /*these variables are shared, but written only my omp master when the other
     *  threads are waiting, so no synchronization is used to access them*/
    uint64_t prob, num_init_vars;
    while (true) {
        start_time = omp_get_wtime();

        double req_time = start_time;
        slave_request_problem(&slave_result, &prob, &num_init_vars);
        total_req_time += omp_get_wtime() - req_time;

        LOG_DEBUG("mpi:%zu received problem:%"PRIu64, mpi_rank(), prob);

        /*The na sent is for the problem solved, so we have to clean it*/
        result_set_na(&slave_result, 0);

        start_computation_time = omp_get_wtime();

        if(prob == UINT64_MAX) {
            break;
        }

        do_maxsat(crepr, &slave_result, num_init_vars, prob);

        total_computation_time += omp_get_wtime() - start_computation_time;
    }

    start_time = omp_get_wtime();

    LOG_DEBUG("mpi:%zu total_req_time:%fs total_computation_time:%fs total_thread_wait_time:%fs sync_time:%fs",
              mpi_rank(),
              total_req_time,
              total_computation_time,
              total_thread_wait_time,
              omp_get_wtime() - start_time);
}


/*
 * master/slave communication
 */

/*
 *
 * problem step
 *
 */
void maxsat_problem_send(uint64_t *msg, int dest) {
    int mpi_ret = MPI_Send(msg,
                       PROBLEM_REQUEST_LEN,
                       MPI_UINT64_T,
                       dest,
                       PROBLEM_REQUEST_TAG,
                       MPI_COMM_WORLD);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed mpi send");
    return;

on_error:
    ASSERT_EXIT();
}

void maxsat_problem_recv(uint64_t *msg, int source) {
    int mpi_ret = MPI_Recv(msg,
                       PROBLEM_REQUEST_LEN,
                       MPI_UINT64_T,
                       source,
                       PROBLEM_REQUEST_TAG,
                       MPI_COMM_WORLD,
                       MPI_STATUS_IGNORE);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed mpi recv.");
    return;

on_error:
    ASSERT_EXIT();
}


void slave_request_problem(struct result *result, uint64_t *prob, size_t *num_init_vars) {
    uint64_t msg_buf[PROBLEM_REQUEST_LEN];

    msg_buf[0] = mpi_rank();
    msg_buf[1] = result_maxsat(result);
    msg_buf[2] = result_na(result);
    msg_buf[3] = result_assignment(result).vars[0]; /*FIXME?*/
    msg_buf[4] = result_assignment(result).vars[1]; /*FIXME?*/;

    maxsat_problem_send(msg_buf, mpi_master());
    maxsat_problem_recv(msg_buf, mpi_master());

    *prob = msg_buf[0];
    *num_init_vars = msg_buf[1];
    uint64_t master_maxsat = msg_buf[2];

    if(master_maxsat > result_maxsat(result)) {
        result_set_maxsat(result, master_maxsat);
    }
}

void master_give_problem(struct result *result,
                         uint64_t prob,
                         uint64_t num_init_vars) {
    uint64_t msg_buf[PROBLEM_REQUEST_LEN];

    maxsat_problem_recv(msg_buf, MPI_ANY_SOURCE);

    uint64_t requester = msg_buf[0];
    uint64_t slave_maxsat = msg_buf[1];
    uint64_t slave_na = msg_buf[2];
    struct assignment slave_assignment = new_stack_assignment_from_num(msg_buf + 3);

    struct result slave_result = new_stack_result();
    result_set_maxsat(&slave_result, slave_maxsat);
    result_set_na(&slave_result, slave_na);
    result_set_assignment(&slave_result, slave_assignment);
    sync_result(result, &slave_result);

    msg_buf[0] = prob;
    msg_buf[1] = num_init_vars;
    msg_buf[2] = result_maxsat(result);
    msg_buf[3] = 0;
    msg_buf[4] = 0;

    maxsat_problem_send(msg_buf, requester);

}


/* Calculate the maxsat result for the crepr.
 * schedule(dynamic) guarantees that all threads keep running for the
 * same approximate ammount of time, because they keep getting
 * new problems if they finish early(vs static schedule).
 *nowait is used to measure the time difference between first and last
 * thread finishing. Without nowait there'd be a barrier before
 * measuring the time*/
void do_maxsat(const struct crepr *crepr, struct result *result, uint8_t num_init_vars, uint64_t prob) {

    uint64_t num_subprob_init_threads, num_subprobs;
    maxsat_prob_division(crepr_num_vars(crepr) - num_init_vars,
                         omp_get_num_threads(),
                         &num_subprobs,
                         &num_subprob_init_threads);

    struct clauses clauses;
    ALLOC_LOCAL_CLAUSES(clauses, crepr);

    /*the least num_init_vars least significant bits of prob
     * have the assignments for the num_init_vars least sig bits*/
    uint64_t assignment_num[2] = {0, (prob << 1)};
    struct assignment assignment = new_stack_assignment_from_num(assignment_num);

    INIT_LOCAL_CLAUSES(clauses, crepr, assignment, num_init_vars);

    /*Solve the partial problem starting with num_init_vars
     * assigned*/
    partial_maxsat(&clauses, result);

    LOG_DEBUG("prov:%"PRIu64"/%zu maxsat:%"PRIu16" na:%"PRIu64,
            prob,
            (((size_t)1 << num_init_vars)  - 1),
            result_maxsat(result),
            result_na(result));


}




/*
 *
 * problem splitting
 *
 */

/*counts the number of bits in the representation of num.
 * e.g. num_bit_len(3) = 2
 *      num_bit_len(15) = 4*/
uint8_t num_bit_len(int num) {
    uint8_t cur_bit = 0;
    while(num) {
        num >>= 1;
        ++cur_bit;
    }
    return cur_bit;
}

/* Chooses how many num_init_vars and problems in function of num_vars
 *  and num_workers
 *
 * num_problems is the value of the number of problems,
 * num_initialized variables is the number of bits in num_problems
 * that's why we use we add values to num_initiliazed variables, because
 * when we use << to assign num_problems, all the + are turned in * */
void maxsat_prob_division(const uint8_t num_vars,
                          const size_t num_workers,
                          uint64_t *num_problems,
                          uint64_t *num_init_vars) {

    /*We would like that each process have 32(log2(32)=5) problems.*/
    const uint8_t num_vars_per_worker = 5;
    /*we want each subproblem to have at least 4096 evaluations*/
    const uint8_t min_num_vars_remaining = 12;

    /* num_bit_len() - 1 because when there's only 1 worker, we don't want to
     *  add more vars.*/
    *num_init_vars = num_vars_per_worker + num_bit_len(num_workers) - 1;

    LOG_DEBUG("maxsat: %zu workers, num_init_vars %" PRIu64 " of %"PRIu8 ,
              num_workers,
              *num_init_vars,
              num_vars);

    /*too many workers for problem size,
     * would give more init_vars than there are vars*/
    if (num_vars < min_num_vars_remaining) {
        *num_init_vars = 0;
        LOG_DEBUG("Reducing num_init_vars to %" PRIu64, *num_init_vars);
    } else if(*num_init_vars > num_vars
       || ((num_vars - *num_init_vars) < min_num_vars_remaining) ) {
        *num_init_vars = num_vars - min_num_vars_remaining;
        LOG_DEBUG("Reducing num_init_vars to %" PRIu64, *num_init_vars);
    }

    *num_problems = 1 << (*num_init_vars);
    return;
}



/*
 *
 * ancillary
 *
 */

/*If sync_result is better than result, result is set to sync_result,
 * if they have the same maxsat, sync_result na is added to result
 * if sync_result is worse than, sync_result's maxsat is to to result*/
void sync_result(struct result *result, struct result *sync_result) {
    if(result_maxsat(result) > result_maxsat(sync_result)) {
        result_set_maxsat(sync_result, result_maxsat(result));
    } else if (result_maxsat(result) < result_maxsat(sync_result)) {
        result_set_maxsat(result, result_maxsat(sync_result));
        result_set_assignment(result, result_assignment(sync_result));
        result_set_na(result, result_na(sync_result));
    } else {
        result_set_na(result, result_na(result) + result_na(sync_result));
    }
}



/*
 *
 * maxsat solving functions
 *
 */

/* Calculate the maxsat for the partial assigment to the variables in the crepr.*/
void partial_maxsat(struct clauses *clauses, struct result *result) {
    size_t var;

    /*We're initializing(filling filter) the subproblems variables here instead
     * of in the constructor of clauses.*/
    for(var=1; var <= clauses->last_assigned_var; ++var) {
        eval_var_clauses(clauses, var);
        if(should_prune(clauses, result)) {
            return;
        }
    }
    do_partial_maxsat(clauses, result, clauses->last_assigned_var + 1);


    return;
}

void do_partial_maxsat(struct clauses *clauses, struct result *result, uint8_t var) {
    if(var > crepr_num_vars(clauses->crepr)) {
        /*Reached leaf node, update result(noop if not better)
         * and start going back. Condition must be >. when ==, it's the leaf node*/
        result_update(result, clauses->num_true_clauses, clauses->assignment);
        return;
    }

    // We can assign to the variable two values, false/0 or true/1
    for(int i = 0; i <= 1; i++) {
        assignment_set_var(&(clauses->assignment), var, i);
        ++(clauses->last_assigned_var);

        eval_var_clauses(clauses, var);

        if(!should_prune(clauses, result)){
            do_partial_maxsat(clauses, result, var + 1);
        }

        rollback_assignment_to_var(clauses, var);
        --(clauses->last_assigned_var);
    }
}


/*Returns true if we should prune the current branch,
 *  because it can't improve maxsat*/
bool should_prune(struct clauses *clauses, struct result *result) {
    uint16_t max_possible_true_clauses = clauses->num_true_clauses + clauses->num_unknown_clauses;

    return result_maxsat(result) > max_possible_true_clauses;
}


/* Reverts the changes in the state performed by assigning a value to a variable.
 * It will update the counters and the calculated_clauses_filter accordingly.*/
void rollback_assignment_to_var(struct clauses *clauses, uint8_t var) {
    struct crepr_clauses_of var_clauses = crepr_clauses_of(clauses->crepr, var);

    for(uint16_t i = 0; i < var_clauses.len; i++) {
        uint16_t clause_id = var_clauses.first[i];
        int8_t clause_filter_value = clauses->calculated_clauses_filter[clause_id];

        if(abs(clause_filter_value) == var) {
            //The variable is the one that is determining the value of the clause
            clauses->num_unknown_clauses++;

            if(clause_filter_value < 0) {
                // It sets the clause value to false
                clauses->num_false_clauses--;
            } else {
                // It sets the clause value to true
                clauses->num_true_clauses--;
            }

            // Make the clause value not calculated
            clauses->calculated_clauses_filter[clause_id] = 0;
        }
    }

    return;
}


/* Evaluates all the clauses where the var appears.
 * Updates the internal counter and the filter accordingly.*/
void eval_var_clauses(struct clauses *clauses, uint8_t var) {
    struct crepr_clauses_of var_clauses = crepr_clauses_of(clauses->crepr, var);

    for(size_t i = 0; i < var_clauses.len; i++) {
        eval_clause(clauses, var_clauses.first[i]);
    }

    return;
}


// Use this enum just to make the code more readable when we refer to the third state
enum clause_value {
    TRUE,
    FALSE,
    UNKNOWN
};

/* Evaluates a clause based on the variables assignments and on the filter, and
 *  updates clauses accordingly.*/
void eval_clause(struct clauses *clauses, uint16_t clause_id) {
    if(clauses->calculated_clauses_filter[clause_id] !=  0) {
        /*clause's value already determined*/
        return;
    }

    struct crepr_clause clause = crepr_clause(clauses->crepr, clause_id);

    // Assume it's value is false
    enum clause_value ret = FALSE;
    for(size_t i = 0; i < clause.len; i++) {
        // may be > 0 or < 0 if should be negated (~)
        int8_t var = clause.first[i];
        int8_t var_id = abs(var);

        if(var_id > clauses->last_assigned_var) {
            /*var is unassinged. clauses can only be TRUE or UNKNOWN now*/
            ret = UNKNOWN;
            continue;
        }

        bool var_value =  assignment_get_var(clauses->assignment, var_id);
        if( (var_value && (var > 0)) || (!var_value && (var < 0))) {
            /* clause is true, because:
             * var is assigned true and var is positive in clause
             * OR var is assigned false and var is negative in clause*/

            /*var_id sets the clause to true, so we write it in the filter*/
            clauses->calculated_clauses_filter[clause_id] = var_id;
            ++(clauses->num_true_clauses);
            --(clauses->num_unknown_clauses);
            return;
        }
    }

    if(ret == FALSE) {
        /*We write in the filter that last_assigned_var is responsible for the
         *  clause being false. When we rollback last_assigned_var the clause
         *  is set to unknown again.*/
        int8_t decisive_variable = clauses->last_assigned_var;
        clauses->calculated_clauses_filter[clause_id] = -decisive_variable;
        clauses->num_false_clauses++;
        clauses->num_unknown_clauses--;
    }

    return;
}
#undef ALLOC_LOCAL_CLAUSES
#undef INIT_LOCAL_CLAUSES

/*********************************End of clauses.c*********************************/

#include <omp.h>
#include <mpi.h>
#include <stdlib.h>

static struct parse_args parse_args(int argc, char **argv);
static void set_debug_level(struct parse_args args);
static void print_result(struct crepr *crepr, struct result result);


struct parse_args {
    bool debug, info, parse_only, success;
    const char *filename;
};

/* Public functions*/

int main(int argc, char **argv) {
    int mpi_ret, mpi_provided;


    mpi_ret = MPI_Init_thread(&argc, &argv, MPI_THREAD_FUNNELED, &mpi_provided);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS && mpi_provided == MPI_THREAD_FUNNELED, "Failed to init OpenMPI.");

    struct parse_args args = parse_args(argc, argv);
    ASSERT_MSG(args.success, "");

    set_debug_level(args);


    /*Parse file*/
    double start_time = omp_get_wtime();
    struct new_crepr new_crepr_result = new_crepr(args.filename);
    LOG_INFO("parse time: %fs", omp_get_wtime() - start_time);
    ASSERT_MSG(new_crepr_result.success, "Couldn't parse given filename");
    struct crepr *crepr = new_crepr_result.crepr;

    if (args.parse_only) {
        free_crepr(crepr);
        return 0;
    }


    /*Calculate maxsat*/
    start_time = omp_get_wtime();
    struct result result = maxsat(crepr);

    if(is_mpi_master()) {
        print_result(crepr, result);
        LOG_INFO("maxsat time: %fs", omp_get_wtime() - start_time);
    }

    /*Finalization*/
    free_crepr(crepr);

    MPI_Finalize();

    return 0;

on_error:
    return 1;
}



/* Private functions*/

static struct parse_args parse_args(int argc, char **argv) {
    struct parse_args ret = {.parse_only = false,
                             .debug = false,
                             .info = false,
                             .filename = NULL};

    ASSERT_MSG(argc <= 4 && argc >= 2, "Invalid number of arguments!\n prog_name [--parse-only] [--debug|--info] filename");
    for (int i = 1; i < argc; ++i) {
        if ((strcmp(argv[i], "--parse-only") == 0) && !ret.parse_only) {
            ret.parse_only = true;
        } else if ( (strcmp(argv[i], "--debug") == 0) && !ret.debug && !ret.info) {
            ret.debug = true;
        } else if ( (strcmp(argv[i], "--info") == 0) && !ret.debug && !ret.info) {
            ret.info = true;
        } else if (ret.filename == NULL) {
            ret.filename = argv[i];
        } else {
            ASSERT_ERROR("Failed to parse arguments. You could have duplicate flags, miss a filename, or mispelled the flags.");
        }
    }
    ASSERT_MSG(ret.filename != NULL, "No filename given.");

    ret.success = true;
    return ret;

on_error:
    ret.success = false;
    return ret;
}

static void set_debug_level(struct parse_args args) {
    if(args.debug) {
        DEBUG_SET_LEVEL(DEBUG_LEVEL_DEBUG);
    } else if(args.info) {
        DEBUG_SET_LEVEL(DEBUG_LEVEL_INFO);
    }
}

static void print_result(struct crepr *crepr, struct result result) {
    printf("%" PRIu16 " %" PRIu64 "\n", result.maxsat_value, result.na);

    uint8_t num_vars = crepr_num_vars(crepr);

    for(int i = 1; i <= num_vars; i++) {
        if(assignment_get_var(result.sample, i)) {
            printf("%d ", i);
        } else {
            printf("-%d ", i);
        }
    }
}

/**********************************End of main.c***********************************/

