#include "clauses_repr.h"

#include <stdio.h>
#include "assert.h"
#include "project_specific.h"
#include "parse_long.h"
#include "debug.h"

/*These fixme just mark the spot where "project specific" cosntraints are abused to optimized space
 *FIXME: var_clauses_index depends on MAX_NUM_VARS_CLAUSE MAX_NUM_CLAUSES
 *FIXME: var_clauses_index_clauses depends on MAX_NUM_CLAUSES
 *FIXME: clause_num_index depends on MAX_NUM_VARS_CLAUSE MAX_NUM_CLAUSES
 *FIXME: clause_num_index_clauses depends on MAX_NUM_VAR
 *FIXME: num_clauses depends on MAX_NUM_CLAUSES
 *FIXME: num_vars depends on MAX_VAR*/
struct clauses_repr {
    /*saves which clauses a variable is in*/
    uint32_t *var_clauses_index; /*max 20 vars/clause, max 65535 clauses. 20*65536 can be index with uint32_t*/
    uint16_t *var_clauses_index_clauses; /*max 65535 clause, can be indexed with uint16_t*/

    /*saves all clauses, by number*/
    uint32_t *clause_num_index; /*see var_clauses_index*/
    int8_t *clause_num_index_clauses; /*max 127 vars, negative is represented with 8th bit, so int8_t */

    uint16_t num_clauses;
    uint8_t num_vars;
};

/*Structs for internal functions*/
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
static uint8_t var_index_from_var(int8_t var);

/*
 * Implementation of public functions
 */

struct new_clauses_repr_from_file new_clauses_repr_from_file(const char *file_path) {
    /* We read the file two times.
     * The first time we find out the total number of varibles, clauses, etc
     * Then we alloc the memory, 
     * The second time we fill the data structures*/
    FILE * file = NULL; 

    struct new_clauses_repr_from_file ret = {.success = true, .clauses_repr = NULL};
    ASSERT_MALLOC(struct clauses_repr, ret.clauses_repr, 1);

    ret.clauses_repr->var_clauses_index = NULL;

    file = fopen(file_path, "r");
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
        ret.clauses_repr->clause_num_index = parse_maxsat_ret.clause_num_index;
        ret.clauses_repr->clause_num_index_clauses = parse_maxsat_ret.clause_num_index_clauses;

        fclose(file);
        file = NULL;

        struct var_clauses_index var_clauses_index_ret = var_clauses_index(var_clause_count_ret, ret.clauses_repr->clause_num_index, ret.clauses_repr->clause_num_index_clauses, var_count);
        if(!var_clauses_index_ret.success) {
            ASSERT_FREE(ret.clauses_repr->clause_num_index);
            ASSERT_FREE(ret.clauses_repr->clause_num_index_clauses);
            ASSERT_ERROR("Failed to build the var_clause_index.");
        }
        ret.clauses_repr->var_clauses_index = var_clauses_index_ret.var_clauses_index;
        ret.clauses_repr->var_clauses_index_clauses = var_clauses_index_ret.var_clauses_index_clauses;
    }

    ret.clauses_repr->num_vars = var_clause_count_ret.num_vars;
    ret.clauses_repr->num_clauses = var_clause_count_ret.num_clauses;

    
    return ret;

on_error:
    if (file) {
        fclose(file);
    }
    if (ret.clauses_repr != NULL) {
        free(ret.clauses_repr); /*not using free_clauses_repr because we're inside constructor, and on_error some fieldsmight not be initilized*/
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
    ASSERT_FREE(clauses_repr->var_clauses_index);
    ASSERT_FREE(clauses_repr->var_clauses_index_clauses);
    ASSERT_FREE(clauses_repr->clause_num_index);
    ASSERT_FREE(clauses_repr->clause_num_index_clauses);
    ASSERT_FREE(clauses_repr);

    return;
on_error:
    ASSERT_EXIT();
}

uint8_t clauses_repr_num_vars(const struct clauses_repr *clauses_repr) {
    ASSERT_NON_NULL(clauses_repr);
    return clauses_repr->num_vars;

on_error:
    ASSERT_EXIT();
}

uint16_t clauses_repr_num_clauses(const struct clauses_repr *clauses_repr) {
    ASSERT_NON_NULL(clauses_repr);
    return clauses_repr->num_clauses;

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
    size_t back_count = 0;

    ret.num_read = fread(buf, 1, buf_size, file);
    if (ret.num_read != 0 && ret.num_read == buf_size) { /*we read something, and it's the end? so we just return backing up until last whitespace*/
        buf[ret.num_read] = '\0';

        const char *cur_buf_pos = buf + ret.num_read - 1;
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

    LOG_DEBUG("file_read: success:%d read:%zu buf_size:%zu back_count:%zu", ret.success, ret.num_read, buf_size, back_count);

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
    struct parse_maxsat ret = {.success = true, .clause_num_index = NULL, .clause_num_index_clauses = NULL};

    /*Alloc clauses_repr memory*/
    ASSERT_MALLOC_CREATE_VAR(uint32_t, cur_clause_num_index, var_clause_count.num_clauses + 1); /* +1 because we index with clause_num_index[i] and [i+1] */
    ret.clause_num_index = cur_clause_num_index;
    *cur_clause_num_index = 0;
    ++cur_clause_num_index;

    ASSERT_MALLOC_CREATE_VAR(int8_t, cur_clause_num_index_clauses, var_clause_count.total_num_vars);
    ret.clause_num_index_clauses = cur_clause_num_index_clauses;

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
    size_t num_vars_clause = 0;
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
        if(!parse_long_ret.success) {
            /*We always read until a space or a newline. It could be the case that after reading the last number
             * in the buffer, we're at a space or newline and can't read any more numbers, but we're not at an \0 yet.
             *In this situation parse_long_ret.success is false, but we aren't in an error condition if the 
             * remainin read size is smaller than a number*/
            size_t num_chars_remaining = file_read_ret.num_read - (cur_buf_pos - buf);
            if (num_chars_remaining >= MAX_VAR_STR_SIZE) {
                ASSERT_ERROR("Couldn't parse a number and there are too many chars remaining!");
            }
            LOG_DEBUG("Failed to read number, but near buf end, so skipping '%zu' chars", num_chars_remaining);
            cur_buf_pos += num_chars_remaining; /*skip to \0*/
            continue;

        }
        ASSERT_MSG(parse_long_ret.value <= INT8_MAX && parse_long_ret.value >= INT8_MIN, \
                "Parsed variable too big. Doesn't fit in byte");

        cur_buf_pos = parse_long_ret.str_next_pos;
        if (parse_long_ret.value != 0) { /*Same clause*/
            ASSERT_MSG(var_clause_count.total_num_vars > 0, "Read more vars than expected.");
            ASSERT_MSG(var_index_from_var(parse_long_ret.value) >= 1
                    && var_index_from_var(parse_long_ret.value) <= var_clause_count.num_vars, "Variable bigger than num_vars");
            ++num_vars_clause;
            ASSERT_MSG(num_vars_clause <= MAX_NUM_VARS_CLAUSE, "Too many vars in clause");
            --(var_clause_count.total_num_vars);

            *cur_clause_num_index_clauses = parse_long_ret.value;
            ++cur_clause_num_index_clauses;
            ++var_count[var_index_from_var(parse_long_ret.value)];

        } else { /*Changing clauses*/
            ASSERT_MSG(var_clause_count.num_clauses > 0, "Read more clauses than expected.");
            num_vars_clause = 0;
            --(var_clause_count.num_clauses);

            /*clause start index in clause_num_index_clauses*/
            *cur_clause_num_index = (cur_clause_num_index_clauses - ret.clause_num_index_clauses); 
            ++cur_clause_num_index;
            if(var_clause_count.num_clauses == 0) {
                LOG_DEBUG("Found number of expected clauses, exiting. %s", "");
                break;
            }
        }
    }

    return ret;
on_error:
    ret.success = false;
    if(ret.clause_num_index != NULL) {
        free(ret.clause_num_index);
    }
    if(ret.clause_num_index_clauses != NULL) {
        free(ret.clause_num_index_clauses);
    }
    return ret;
}


/*Builds the var_clauses_index. Conceptually it's an associative array of var -> list of clauses....
 *We implement as a pair of arrays like clause_num_index.
 */
static struct var_clauses_index var_clauses_index(struct var_clause_count var_clause_count, const uint32_t *clause_num_index, const int8_t *clause_num_index_clauses, const size_t *var_count) {
    struct var_clauses_index ret = {.success = true, .var_clauses_index = NULL, .var_clauses_index_clauses = NULL};

    /* +1 because we don't use var 0 and +1 reason above . Not name cur_ because we don't change it.*/
    ASSERT_MALLOC_CREATE_VAR(uint32_t, var_clauses_index, var_clause_count.num_vars + 2); 
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
    ASSERT_MALLOC_CREATE_VAR(uint16_t, var_clauses_index_clauses, var_clause_count.total_num_vars);
    ret.var_clauses_index_clauses = var_clauses_index_clauses;

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
    if(ret.var_clauses_index != NULL) {
        free(ret.var_clauses_index);
    }
    if(ret.var_clauses_index_clauses != NULL) {
        free(ret.var_clauses_index_clauses);
    }
    return ret;
}

static uint8_t var_index_from_var(int8_t var) {
    if (var < 0) {
        var = -1 * var;
    }
    return var;
}




