#include "clauses_repr.h"

#include <stdio.h>
#include "assert.h"
#include "project_specific.h"
#include "parse_long.h"
#include "debug.h"


struct file_read {
    size_t num_read;
    bool success;
    bool eof;
    bool error;
};

struct var_clause_count {
    size_t num_vars;
    size_t total_num_vars;
    size_t num_clauses;
    size_t expected_num_clauses;
    bool success;
};

struct parse_maxsat {
    uint32_t *clause_num_index;
    int8_t *clause_num_index_clauses;
    bool success;
};

struct var_clauses_index {
    uint32_t *var_clauses_index;
    uint16_t *var_clauses_index_clauses;
    bool success;
};

static struct file_read file_read(FILE *file, char *buf, size_t buf_size);
static struct var_clause_count var_clause_count(FILE *file);
static struct parse_maxsat parse_maxsat(FILE *file, struct var_clause_count var_clause_count, size_t *var_count);
static struct var_clauses_index var_clauses_index(struct var_clause_count var_clause_count, const uint32_t *clause_num_index, const int8_t *clause_num_index_clauses, const size_t *var_count);
static int8_t var_index_from_var(int8_t var);

/*
 * Implementation of public functions
 */

struct new_stack_clauses_repr_from_file new_stack_clauses_repr_from_file(const char *file_path) {
    /* We read the file two times.
     * The first time we find out the total number of varibles, clauses, etc
     * Then we alloc the memory, 
     * The second time we fill the data structures*/
    struct new_stack_clauses_repr_from_file ret = {.success = true};


    FILE *file = fopen(file_path, "r");
    ASSERT_MSG(file != NULL, "Failed to open file.");

    struct var_clause_count var_clause_count_ret = var_clause_count(file);
    ASSERT_MSG(var_clause_count_ret.success, "Failed to count total number of variables");
    ASSERT_MSG_VA(var_clause_count_ret.num_vars >= 1 && var_clause_count_ret.num_vars <= MAX_NUM_VARS, \
            "Number of variables not within bounds: num_vars '%zu'", var_clause_count_ret.num_vars);
    ASSERT_MSG_VA(var_clause_count_ret.expected_num_clauses >= 1 && var_clause_count_ret.expected_num_clauses <= MAX_NUM_CLAUSES, \
            "Number of clauses not within bounds: expected_num_clauses '%zu'", var_clause_count_ret.expected_num_clauses);
    ASSERT_MSG_VA(var_clause_count_ret.expected_num_clauses == var_clause_count_ret.num_clauses, \
            "Number of clauses differs from number in first line. expected_num_clauses '%zu', num_clauses '%zu'", \
            var_clause_count_ret.expected_num_clauses, var_clause_count_ret.num_clauses);
    ASSERT_MSG_VA(var_clause_count_ret.num_clauses <= MAX_NUM_CLAUSES, \
            "Counted more than the number of maximum clauses. num_clauses '%zu'", var_clause_count_ret.num_clauses);

    /*Now we start from the begining, read it all again an fill the data structures*/
    rewind(file);

    { /*error: jump into scope of identifier with variably modified type*/
        /*parse_maxsat will count each var so we can build var_clause_index with arrays. +1 because var 0 doesn't exist*/
        size_t var_count[var_clause_count_ret.num_vars + 1];
        memset(var_count, 0, sizeof(var_count)); /*error: variable-sized object may not be initialized :(*/ 
        struct parse_maxsat parse_maxsat_ret = parse_maxsat(file, var_clause_count_ret, var_count);
        ASSERT_MSG(parse_maxsat_ret.success, "Failed parsing clauses from file.");

        ret.clauses_repr.clause_num_index = parse_maxsat_ret.clause_num_index;
        ret.clauses_repr.clause_num_index_clauses = parse_maxsat_ret.clause_num_index_clauses;
        struct var_clauses_index var_clauses_index_ret = var_clauses_index(var_clause_count_ret, ret.clauses_repr.clause_num_index, ret.clauses_repr.clause_num_index_clauses, var_count);
        ASSERT_MSG(var_clauses_index_ret.success, "Failed to build the var_clause_index.");
        ret.clauses_repr.var_clauses_index = var_clauses_index_ret.var_clauses_index;
        ret.clauses_repr.var_clauses_index_clauses = var_clauses_index_ret.var_clauses_index_clauses;
    }
    
    return ret;

on_error:
    if (file) {
        fclose(file);
    }
    ret.success = false;
    return ret;
}

struct clauses_repr_clauses_of clauses_repr_clauses_of(const struct clauses_repr *clauses_repr, uint8_t var) {
    struct clauses_repr_clauses_of ret;

    ret.len = clauses_repr->var_clauses_index[var + 1] - clauses_repr->var_clauses_index[var];
    if (ret.len > 0) {
        ret.first = &(clauses_repr->var_clauses_index_clauses[clauses_repr->var_clauses_index[var]]);
    } else {
        ret.first = NULL;
    }

    return ret;
}

struct clauses_repr_clause clauses_repr_clause(const struct clauses_repr *clauses_repr, uint16_t clause) {
    struct clauses_repr_clause ret;

    ret.len = clauses_repr->clause_num_index[clause + 1] - clauses_repr->clause_num_index[clause];
    if (ret.len > 0) {
        ret.first = &(clauses_repr->clause_num_index_clauses[clauses_repr->clause_num_index[clause]]);
    } else {
        ret.first = NULL;
    }

    return ret;
}

void free_clauses_repr(struct clauses_repr *clauses_repr) {
    ASSERT_NON_NULL(clauses_repr);
#define CHECKED_FREE(p) ASSERT_NON_NULL(p); free(p)
    CHECKED_FREE(clauses_repr->var_clauses_index);
    CHECKED_FREE(clauses_repr->var_clauses_index_clauses);
    CHECKED_FREE(clauses_repr->clause_num_index);
    CHECKED_FREE(clauses_repr->clause_num_index_clauses);
#undef CHECKED_FREE

    return;
on_error:
    ASSERT_EXIT();
}


/*
 * private functions
 */

/*We go back up to the whitespace so a number isn't cut in two buffers.
 *We need this on the second file parse, so we just do it for both to avoid wrting another function
 */
static struct file_read file_read(FILE *file, char *buf, size_t buf_size) {
    struct file_read ret = {.num_read = 0, .success = true, .eof = false, .error = false };

    ret.num_read = fread(buf, 1, buf_size, file);
    LOG_DEBUG("file_read: read %zu buf_size %zu", ret.num_read, buf_size);
    if (ret.num_read != 0 && ret.num_read == buf_size) { /*we read something, and it's the end? so we just return backing up until last whitespace*/
        buf[ret.num_read] = '\0';

        const char *cur_buf_pos = buf + ret.num_read - 1;
        size_t back_count = 0;
        while ( ret.num_read > 0 && (*cur_buf_pos != ' ' && *cur_buf_pos != '\n')) {
            --cur_buf_pos;
            --(ret.num_read);
            ++back_count;
        }
        if (ret.num_read == 0) {
            ret.success = false;
            ret.error = true;
        } else {
            fseek(file, -1 * back_count ,SEEK_CUR);
            buf[ret.num_read] = '\0';
        }
    } else if (ret.num_read != 0 && ret.num_read != buf_size) {
        buf[ret.num_read] = '\0';
    }else { /*error*/
        ret.success = false;
        if(ferror(file)) {
            ret.error = true;
        }
        if (feof(file)) {
            ret.eof = true;
        }
    }

    return ret;
}



/*First pass on the input file to count the total number of variables used,
 * so we can allocate clause_num_index and clause_num_index_clauses with the exact size
 *The number of total variables used are counted by counting whitespace and not by parsing the numbers.
 * We also parse the first line (number of variables and number of clauses)
 * */
static struct var_clause_count var_clause_count(FILE *file) {
    const size_t buf_size = 4096;
    char buf[buf_size + 1];
    const char *cur_buf_pos;
    struct file_read file_read_ret;
    struct var_clause_count ret = { .num_vars = 0, .total_num_vars = 0, .num_clauses = 0, .expected_num_clauses = 0, .success = true};

    file_read_ret = file_read(file, buf, buf_size);
    ASSERT_MSG_VA(file_read_ret.success, "Failed read. error '%d' eof '%d'", file_read_ret.error, file_read_ret.eof);
    cur_buf_pos = buf;

    /*Assuming buffer is big enough to read the first line without having to read again, otherwise we error out*/
    struct parse_long parsed_long = parse_long(buf);
    ASSERT_MSG(parsed_long.success, "Failed parsing number of variables.");
    ret.num_vars = parsed_long.value;

    parsed_long  = parse_long(parsed_long.str_next_pos);
    ASSERT_MSG(parsed_long.success, "Failed parsing number of clauses.");
    ret.expected_num_clauses = parsed_long.value;

    cur_buf_pos = parsed_long.str_next_pos;

    /*skip the whitespace/\n that follows the two numbers*/
    while (*cur_buf_pos != '\n') {
        ASSERT_MSG(*cur_buf_pos != '\0', "Buffer is not big enough. The first input line doesn't fit.");
        ++cur_buf_pos;
    }
    ++cur_buf_pos; /*skip newline*/

    /*now we're going to read all the clauses and count the number of variable uses + the number of clauses*/
    bool already_reading_whitespace = false;
    while(true) {
        if( *cur_buf_pos == '\0') { /*buffer ended, we need to read more*/
            file_read_ret = file_read(file, buf, buf_size);
            if(file_read_ret.success) {
                cur_buf_pos = buf;
                continue; /*we must continue to avoid incrementing cur_buf_pos below*/
            } else if (file_read_ret.eof) {
                break; /* end processing file*/
            } else {
                ASSERT_MSG(false, "Failed read due to error");
            }
        } else if ( *cur_buf_pos == '\n') {
            ++(ret.num_clauses);
        } else if (*cur_buf_pos == ' ' && !already_reading_whitespace) {
            ++(ret.total_num_vars);
            already_reading_whitespace = true;
        } else {
            already_reading_whitespace = false;
        }
        ++cur_buf_pos;
    }

    return ret;
on_error:
    ret.success = false;
    return ret;
}


/*
 * Parses the file to fill the clause_num_index and clause_num_index_clauses arrays.
 * Also counts the total occurence of all variables so we cab build the var_clause_index
 */
static struct parse_maxsat parse_maxsat(FILE *file, struct var_clause_count var_clause_count, size_t *var_count) {
    const size_t buf_size = 4096;
    char buf[buf_size + 1];
    const char *cur_buf_pos;
    struct file_read file_read_ret;
    struct parse_maxsat ret = {.success = true};

    /*Alloc clauses_repr memory*/
#define CHECKED_MALLOC(VAR, TYPE, COUNT) TYPE *VAR = (TYPE *) malloc(sizeof(TYPE) * (COUNT)); ASSERT_NON_NULL((VAR))
    CHECKED_MALLOC(cur_clause_num_index, uint32_t, var_clause_count.num_clauses + 1); /* +1 because we index with clause_num_index[i] and [i+1] */
    ret.clause_num_index = cur_clause_num_index;
    *cur_clause_num_index = 0;
    ++cur_clause_num_index;

    CHECKED_MALLOC(cur_clause_num_index_clauses, int8_t, var_clause_count.total_num_vars);
    ret.clause_num_index_clauses = cur_clause_num_index_clauses;
#undef CHECKED_MALLOC

    file_read_ret = file_read(file, buf, buf_size);
    ASSERT_MSG_VA(file_read_ret.success, "Failed read. error '%d' eof '%d'", file_read_ret.error, file_read_ret.eof);
    cur_buf_pos = buf;

    /*skip first line*/
    while (*cur_buf_pos != '\n') {
        ASSERT_MSG(*cur_buf_pos != '\0', "Buffer is not big enough. The first input line doesn't fit.");
        ++cur_buf_pos;
    }
    ++cur_buf_pos; /*skip new line*/

    /*read clauses*/
    while (true) {
        if (*cur_buf_pos == '\0') {
            file_read_ret = file_read(file, buf, buf_size);
            if(file_read_ret.success) {
                cur_buf_pos = buf;
                continue; /*we must continue to avoid incrementing cur_buf_pos below*/
            } else if (file_read_ret.eof) {
                break; /* end processing file*/
            } else {
                ASSERT_MSG(false, "Failed read due to error");
            }
            continue; /*we must continue to avoid incrementing cur_buf_pos below*/
        }

        struct parse_long parse_long_ret = parse_long(cur_buf_pos);
        if(!parse_long_ret.success) { /*FIXME: better way to do this?*/
            if (*(cur_buf_pos + 1) == '\0') {
                ++cur_buf_pos;
                continue;
            } else if (*(cur_buf_pos + 2) == '\0') {
                cur_buf_pos += 2;
                continue;
            } else if (*(cur_buf_pos + 3) == '\0') {
                cur_buf_pos += 3;
                continue;
            } else if (*(cur_buf_pos + 4) == '\0') {
                cur_buf_pos += 4;
                continue;
            }
        }
        ASSERT_MSG(parse_long_ret.success , "Failed to parse variable in clause");
        ASSERT_MSG(parse_long_ret.value <= INT8_MAX && parse_long_ret.value >= INT8_MIN, \
                "Parsed variable not within expected project bounds");

        cur_buf_pos = parse_long_ret.str_next_pos;
        if (parse_long_ret.value != 0) { /*Same clause*/
            ASSERT_MSG(var_clause_count.total_num_vars > 0, "Read more vars than expected.");
            --(var_clause_count.total_num_vars);

            *cur_clause_num_index_clauses = parse_long_ret.value;
            ++cur_clause_num_index_clauses;
            ++var_count[var_index_from_var(parse_long_ret.value)];

        } else { /*Changing clauses*/
            ASSERT_MSG(var_clause_count.num_clauses > 0, "Read more vars than expected.");
            --(var_clause_count.num_clauses);

            /*clause start index in clause_num_index_clauses*/
            *cur_clause_num_index = (cur_clause_num_index_clauses - ret.clause_num_index_clauses); 
            ++cur_clause_num_index;
            if(var_clause_count.num_clauses == 0) { /*FIXME: maybe?*/
                break;
            }
        }
    }

    return ret;
on_error:
    ret.success = false;
    return ret;
}


/*Builds the var_clauses_index. Conceptually it's an associative array of var -> list of clauses....
 *We implement as a pair of arrays like clause_num_index.
 */
static struct var_clauses_index var_clauses_index(struct var_clause_count var_clause_count, const uint32_t *clause_num_index, const int8_t *clause_num_index_clauses, const size_t *var_count) {
    struct var_clauses_index ret = {.success = true};

#define CHECKED_MALLOC(VAR, TYPE, COUNT) TYPE *VAR = (TYPE *) malloc(sizeof(TYPE) * (COUNT)); ASSERT_NON_NULL(VAR)
    /* +1 because we don't use var 0 and +1 reason above . Not name cur_ because we don't change it.*/
    CHECKED_MALLOC(var_clauses_index, uint32_t, var_clause_count.num_vars + 2); 
    ret.var_clauses_index = var_clauses_index;
    ret.var_clauses_index[0] = 0; /*skip var 0*/
    ret.var_clauses_index[1] = 0; /*var 1 start at position 0*/
    { /*fill var_clauses_index*/
        uint8_t var;
        /*<= is not a bug, it fills the sentinel position of var_clauses_index*/
        for(var = 2; var <= (var_clause_count.num_vars + 1); ++var) {
            ret.var_clauses_index[var] = ret.var_clauses_index[var - 1] + var_count[var - 1];
        }
    }

    /*Not name cur_ because we don't change it.*/
    CHECKED_MALLOC(var_clauses_index_clauses, uint16_t, var_clause_count.total_num_vars);
    ret.var_clauses_index_clauses = var_clauses_index_clauses;
#undef CHECKED_MALLOC

    { /*error: jump into scope of identifier with variably modified type*/
        size_t clause;
        /*cur pos between clause_num_index[var] and clause_num_index[var+1]*/
        size_t cur_var_clause[var_clause_count.num_vars + 1]; /*error: variable-sized object may not be initialized :(*/ 
        memset(cur_var_clause, 0, sizeof(cur_var_clause));
        for(clause = 0; clause < var_clause_count.num_clauses; ++clause) {
            uint32_t first_var_pos = clause_num_index[clause];
            uint32_t last_var_pos = clause_num_index[clause + 1];
            size_t var_pos;
            for(var_pos = first_var_pos; var_pos < last_var_pos; ++var_pos) {
                int8_t var = var_index_from_var(clause_num_index_clauses[var_pos]);
                ret.var_clauses_index_clauses[ret.var_clauses_index[var] + cur_var_clause[var]] = clause;
                ++cur_var_clause[var];
            }
        }
    }

    return ret;

on_error:
    ret.success = false;
    return ret;
}

static int8_t var_index_from_var(int8_t var) {
    if (var < 0) {
        var = -1 * var;
    }
    return var;
}




