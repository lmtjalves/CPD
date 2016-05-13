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
        fprintf(stderr, LOG_TYPE " (%s:%d: errno: %s) " MESSAGE "\n", __FILE__, __LINE__, DEBUG_CLEAN_ERRNO(), __VA_ARGS__);\
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
        ASSERT_MSG(false, "Reached point of no return. Exiting."); \
        exit(1); \
    } while(0)


#define ASSERT_MALLOC(TYPE, VAR, COUNT) \
    do { \
        VAR = (TYPE *) malloc(sizeof(TYPE) * (COUNT)); \
        ASSERT_NON_NULL(VAR); \
    } while(0)

#define ASSERT_MALLOC_CREATE_VAR(TYPE, VAR, COUNT) \
    TYPE *VAR; \
    ASSERT_MALLOC(TYPE, VAR, COUNT)

#define ASSERT_FREE(p) \
    do { \
        ASSERT_NON_NULL(p); \
        free(p); \
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

/*****************************Start of clauses_repr.h******************************/
#ifndef CLAUSES_REPR_H__
#define CLAUSES_REPR_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct clauses_repr;

struct new_clauses_repr_from_file {
    struct clauses_repr *clauses_repr;
    bool success;
};

/*Representation for the return of clauses_repr_clauses_of. Represents a list of clauses_num to be fetch by clauses_repr_clause */
struct clauses_repr_clauses_of {
    size_t len;
    const uint16_t *first;
};

/*Representation for the return of clauses_repr_clause. Represents a list of vars of a clause*/
struct clauses_repr_clause {
    size_t len;
    const int8_t *first;
};

struct new_clauses_repr_from_file new_clauses_repr_from_file(const char *file_path);
void free_clauses_repr(struct clauses_repr *clauses_repr);
struct clauses_repr_clauses_of clauses_repr_clauses_of(const struct clauses_repr *clauses_repr, uint8_t var);
struct clauses_repr_clause clauses_repr_clause(const struct clauses_repr *clauses_repr, uint16_t clause);
uint8_t clauses_repr_num_vars(const struct clauses_repr *clauses_repr);
uint16_t clauses_repr_num_clauses(const struct clauses_repr *clauses_repr);

#endif

/******************************End of clauses_repr.h*******************************/

/*****************************Start of clauses_repr.c******************************/

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

#include <stdio.h>

#define MAX_VAR 127
/* == MAX_VAR because vars start at 1*/
#define MAX_NUM_VARS MAX_VAR
#define MAX_NUM_VARS_CLAUSE 20
/* 4 because MAX_VAR is 127 and could be -127*/
#define MAX_VAR_STR_SIZE 4
#define MAX_NUM_CLAUSES 65535

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

#undef MAX_VAR
#undef MAX_NUM_VARS
#undef MAX_NUM_VARS_CLAUSE
#undef MAX_VAR_STR_SIZE
#undef MAX_NUM_CLAUSES


/******************************End of clauses_repr.c*******************************/

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

uint16_t result_get_maxsat_value (struct result *result);
void result_set_maxsat_value (struct result *result, uint16_t new_maxsat_value);

uint64_t result_get_na (struct result *result);
void result_set_na (struct result *result, uint64_t number_assignments);

struct assignment result_get_assignment_sample(struct result *result);
void result_set_assignment_sample(struct result *result, struct assignment new_sample);

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

uint16_t result_get_maxsat_value (struct result *result){
  ASSERT_NON_NULL(result);
	
	return result->maxsat_value;

  on_error:
  ASSERT_EXIT();
}

void result_set_maxsat_value (struct result *result, uint16_t new_maxsat_value){
  ASSERT_NON_NULL(result);

  result->maxsat_value = new_maxsat_value;

  return;

  on_error:
  ASSERT_EXIT();
}

uint64_t result_get_na (struct result *result){
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

struct assignment result_get_assignment_sample(struct result *result){
  ASSERT_NON_NULL(result);

  return result->sample;

  on_error:
  ASSERT_EXIT();
}

void result_set_assignment_sample(struct result *result, struct assignment new_sample){
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
struct result maxsat(const struct clauses_repr *clauses_repr);

#endif /*CLAUSES_H__*/

/*********************************End of clauses.h*********************************/

/********************************Start of clauses.c********************************/

#include <omp.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

// Struct used to represent an instance of clauses_repr
struct clauses {
    // The clauses representation
    const struct clauses_repr* clauses_repr;

    // An assignment to the variables in the clause
    // Note: the assignment may not be complete
    struct assignment assignment;

    // Index of the last assigned var
    uint8_t last_assigned_var;

    // Array with the same size as the number of clauses that is used
    // to keep tracking of the variable that is responsible by maintaining that
    // clause value.
    // If the value is 0, then we don't know the value of the clause, wether because we haven't calculated
    // it yet, or because none of the variables in the clause that have an assigned value contribute for the
    // clause to be evaluated as true, but there's still variables with a non assigned value.
    // If the value is > 0, then the value indicates what is the variable that makes this clause true. Notice
    // that all the other variables may be unknown, do not contribute for the clause to be true, or may contribute
    // but since this was the first variable, this is the decisive one.
    // If the value is < 0, then the value indicates that all the clause variables have an assigned value, but this is
    // the last variable that was unknow and now has a value.
    int8_t *calculated_clauses_filter;

    // Amount of clauses evaluated to true
    uint16_t num_true_clauses;

    // Amount of clauses evaluated to false
    uint16_t num_false_clauses;

    // Amount of clauses whos value is unknown yet
    uint16_t num_unknown_clauses;
};

struct maxsat_prob_division {
    size_t num_problems;
    uint8_t num_initialized_vars;
};

uint8_t num_bit_len(int num);
struct maxsat_prob_division maxsat_prob_division(const struct clauses_repr *clauses_repr);
void partial_maxsat(struct clauses *clauses, struct result *result, uint8_t var_to_test);
bool should_prune(struct clauses *clauses, struct result *result);
void rollback_assignment_to_var(struct clauses *clauses, uint8_t var);
void eval_var_clauses(struct clauses *clauses, uint8_t var);
void eval_clause(struct clauses *clauses, uint16_t clause_id);

/*Initing/allocing clauses like this so we don't have to care about malloc/free*/
/*Not insied do{}while(0) because that'd release the array memory*/
#define ALLOC_LOCAL_CLAUSES(CLAUSES, CLAUSES_REPR) \
int8_t calculated_clauses_filter_ ## CLAUSES [clauses_repr_num_clauses(CLAUSES_REPR)];\
CLAUSES.calculated_clauses_filter = calculated_clauses_filter_ ## CLAUSES

#define INIT_LOCAL_CLAUSES(CLAUSES, CLAUSES_REPR, ASSIGNMENT, LAST_ASSIGNED_VAR) \
do { \
    CLAUSES.clauses_repr = CLAUSES_REPR; \
    CLAUSES.assignment = ASSIGNMENT; \
    CLAUSES.last_assigned_var = LAST_ASSIGNED_VAR; \
    memset(CLAUSES.calculated_clauses_filter, 0 , clauses_repr_num_clauses(CLAUSES_REPR) * sizeof(int8_t)); \
    CLAUSES.num_true_clauses = 0; \
    CLAUSES.num_false_clauses = 0; \
    CLAUSES.num_unknown_clauses = clauses_repr_num_clauses(CLAUSES_REPR); \
} while(0)



uint8_t num_bit_len(int num) {
    uint8_t cur_bit = 0;
    while(num) {
        num >>= 1;
        ++cur_bit;
    }
    return cur_bit;
}

struct maxsat_prob_division maxsat_prob_division(const struct clauses_repr *clauses_repr) {
    ASSERT_NON_NULL(clauses_repr);

    struct maxsat_prob_division ret;

    const uint8_t num_vars_per_thread = 6; /*We would like that each thread have 64 problems*/
    const uint8_t min_num_vars_per_thread = 4; /*We want that each thread has at least 16 problems*/
    const uint8_t num_vars = clauses_repr_num_vars(clauses_repr);

    /* 6 so we approximately 2^6 problems per thread. num_bit_len() - 1 just multiplies by the binary length of the number of threads when we << below*/
    ret.num_initialized_vars = num_vars_per_thread + num_bit_len(omp_get_num_threads()) - 1;

#pragma omp master
    {
        LOG_DEBUG("maxsat: %d threads, num_initialized_vars %" PRIu8 " of %"PRIu8 , omp_get_num_threads(), ret.num_initialized_vars, num_vars);
    } 

    if ( num_vars - ret.num_initialized_vars < min_num_vars_per_thread) { /*too few vars in problem*/
        if (num_vars >= min_num_vars_per_thread) { /* problems size too small*/
            ret.num_initialized_vars = num_vars - min_num_vars_per_thread;
        } else { /*problem really small*/
            ret.num_initialized_vars = 1;
        }
#pragma omp master
        {
            LOG_DEBUG("Reducing num_initialized_vars to %" PRIu8, ret.num_initialized_vars);
        }
    }

    // For each variable it can have 2 values, therefore with num_initialized_vars we can have 2^num_initialized_vars possible combinations.
    ret.num_problems= 1 << (ret.num_initialized_vars);

    return ret;

on_error:
    ASSERT_EXIT();
}

/* Calculate the maxsat result for the clauses_repr.
*/
struct result maxsat(const struct clauses_repr *clauses_repr) {
    ASSERT_NON_NULL(clauses_repr);

    // The maxsat result. This is shared by all threads
    struct result result = new_stack_result();

    const double start_time = omp_get_wtime();
    double first_finish_time = -1;
    double last_finish_time = 0;
    /*We don't declare any variable private because they're already private by being in a new block.
     * Only result is shared.*/
#pragma omp parallel 
    {
        struct result local_result = new_stack_result();
        struct clauses clauses;
        ALLOC_LOCAL_CLAUSES(clauses, clauses_repr);
        const struct maxsat_prob_division prob_division = maxsat_prob_division(clauses_repr);


        /*schedule(dynamic) guarantees that all threads keep running for the same approximate ammount of time, because they keep getting 
         * new problems if they finish earlt.
         *nowait is useful so the log_debugs after the loop have meaning, otherwise there'd be and implicit barrier after the loop, and the
         * debug information would say that all the threads finished at the same time*/
#pragma omp for schedule(dynamic) nowait
        for(uint64_t i = 0; i < prob_division.num_problems; i++) {
            // Note that i in binary are the initial assignments for the fixed variables.
            struct assignment assignment = new_stack_assignment_from_num( (uint64_t [2]){0, i<<1});
            result_set_na(&local_result, 0);

            INIT_LOCAL_CLAUSES(clauses, clauses_repr, assignment, prob_division.num_initialized_vars);


            // Solve the maxsat for this chunk
            // Note that the first variable to test is the first one
            // At this point we know that all the variables between 1 and clauses->last_assigned_var
            // have a fixed value. So we could calculate the impact of their assignment in the clauses here.
            // Instead we calculate it in the partial_maxsat, but the logic remains the same.
            partial_maxsat(&clauses, &local_result, 1);

            LOG_DEBUG("thread: %d assignment:%"PRIu64 "/%zu maxsat:%" PRIu16 " na:%"PRIu64, omp_get_thread_num(), i, prob_division.num_problems, result_get_maxsat_value(&local_result), result_get_na(&local_result));

#pragma omp critical 
            {
                if (result_get_maxsat_value(&result) == result_get_maxsat_value(&local_result)) {
                    result_set_na(&result, result_get_na(&result) + result_get_na(&local_result));
                } else if (result_get_maxsat_value(&result) < result_get_maxsat_value(&local_result)) {
                    result_set_maxsat_value(&result, result_get_maxsat_value(&local_result));
                    result_set_assignment_sample(&result, result_get_assignment_sample(&local_result));
                    result_set_na(&result, result_get_na(&local_result));
                } else {
                    result_set_maxsat_value(&local_result, result_get_maxsat_value(&result));
                }
            }
        }

        const double thread_finish_time = omp_get_wtime() - start_time;
#pragma omp critical
        {
            if (first_finish_time < 0) {
                first_finish_time = thread_finish_time;
            }
            last_finish_time = thread_finish_time;
        }
        LOG_DEBUG("thread: %d finished after %f", omp_get_thread_num(), thread_finish_time);
    }

    LOG_DEBUG("first_finish_time:%f last_finish_time:%f delta:%f", first_finish_time, last_finish_time, last_finish_time - first_finish_time);

    return result;

on_error:
    ASSERT_EXIT();
}


/* Calculate the maxsat for the partial assigment to the variables in the clauses_repr.
*/
void partial_maxsat(struct clauses *clauses, struct result *result, uint8_t var_to_test) {
    ASSERT_NON_NULL(clauses);
    ASSERT_NON_NULL(result);

    if(var_to_test > clauses_repr_num_vars(clauses->clauses_repr)) {
        // Trivial case were all the variables are assigned
        // Just try to update the maxsat value (or increment the number of occurences if it's the same)
        result_update(result, clauses->num_true_clauses, clauses->assignment);
    } else if(var_to_test <= clauses->last_assigned_var) {
        // Notice the var_to_test must be between 1 and clauses->last_assigned_var, in this case
        // it's one of the variables that have the assigned value fixed (we can't test other assignments).
        // No need to branch, just evaluate the assignment impact in the clauses and test the next variable.
        eval_var_clauses(clauses, var_to_test);

        // Stop if there's already a better result otherwise keep testing
        if(!should_prune(clauses, result)) {
            partial_maxsat(clauses, result, var_to_test + 1);
        }

        // No need to perform the rollback/compensate in this case, since all the previous variables also
        // have a fixed value no other combination will be tested it's just going back in the recursivity.

        // Notice I could merge this else if with the following else, just keep it like this to be more readable.
    } else {
        // We can assign to the variable two values, false/0 or true/1
        for(int i = 0; i <= 1; i++) {
            assignment_set_var(&(clauses->assignment), var_to_test, i);
            // Keep tracking of the varaibles with assigned values
            clauses->last_assigned_var++;

            eval_var_clauses(clauses, var_to_test);

            // Don't follow this assignment if there's a better result already
            if(!should_prune(clauses, result)){
                partial_maxsat(clauses, result, var_to_test + 1);
            }

            // Undo all the changes to the clauses internal state by performing the assignment
            rollback_assignment_to_var(clauses, var_to_test);
            clauses->last_assigned_var--;
        }
    }

    return;

on_error:
    ASSERT_EXIT();
}


/* Helper function that returns true if we should prune the current branch.
*/
bool should_prune(struct clauses *clauses, struct result *result) {
    ASSERT_NON_NULL(clauses);
    ASSERT_NON_NULL(result);

    uint16_t max_possible_true_clauses = clauses->num_true_clauses + clauses->num_unknown_clauses;
    return result_get_maxsat_value(result) > max_possible_true_clauses;

on_error:
    ASSERT_EXIT();
}


/* Helper function that compensates the changes in the state performed by assigning a value to a variable.
 * It will update the counters and the calculated_clauses_filter accordingly.
 */
void rollback_assignment_to_var(struct clauses *clauses, uint8_t var) {
    ASSERT_NON_NULL(clauses);

    // All the clauses who's values may be determined by var
    struct clauses_repr_clauses_of var_clauses = clauses_repr_clauses_of(clauses->clauses_repr, var);

    for(uint16_t i = 0; i < var_clauses.len; i++) {
        uint16_t clause_id = var_clauses.first[i];
        int8_t clause_filter_value = clauses->calculated_clauses_filter[clause_id];

        if(abs(clause_filter_value) == var) {
            // The variable is the one that is determining the value of the clause
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

on_error:
    ASSERT_EXIT();
}


/* Evaluates all the clauses where the var appears. Updates the internal counter and
 * the filter accordingly.
 */
void eval_var_clauses(struct clauses *clauses, uint8_t var) {
    ASSERT_NON_NULL(clauses);

    struct clauses_repr_clauses_of var_clauses = clauses_repr_clauses_of(clauses->clauses_repr, var);

    for(size_t i = 0; i < var_clauses.len; i++) {
        eval_clause(clauses, var_clauses.first[i]);
    }

    return;

on_error:
    ASSERT_EXIT();
}


// Use this enum just to make the code more readable when we refer to the third state
enum clause_value {
    TRUE,
    FALSE,
    UNKNOWN
};

/* Evaluates a clause based on the variables assignments and on whether the
 * clause was already true or not (this should not happen, but it's just for safety).
 * Updates the clauses internal counters and updates the calculated_clauses_filter
 * accordingly.
 */
void eval_clause(struct clauses *clauses, uint16_t clause_id) {
    ASSERT_NON_NULL(clauses);
    // If the clause is already true or false, due to another variable, do nothing
    // Note: it can only be false if this variable has already an assigned value (this won't happen)
    if(clauses->calculated_clauses_filter[clause_id] !=  0) return;

    // Get the clause we want to evaluate
    struct clauses_repr_clause clause = clauses_repr_clause(clauses->clauses_repr, clause_id);

    // Assume it's value is false
    enum clause_value ret = FALSE;
    for(size_t i = 0; i < clause.len; i++) {
        int8_t var = clause.first[i]; // may be > 0 or < 0 if should be negated (~)
        int8_t var_id = abs(var);

        if(var_id > clauses->last_assigned_var) {
            // If the variable has no value assigned yet, then the clause value
            // can no longer be FALSE, only TRUE or UNKNOWN
            ret = UNKNOWN;
        } else if(assignment_get_var(clauses->assignment, var_id) != (var < 0)) {
            // We are using != operator as a xor
            // var < 0 means that the value should be negated (~ operator on the variable value)
            // This means, if the variable has value true and it should not be negated, then we have 1 != 0 therefore true
            // If the variable has value false and it should be negated, then we have 0 != 1 therefore true
            // Notice that we are relying on the C defined behaviour that:
            // "The result is one if the operands are in the given relation to one another. The result is zero otherwise."

            // Another observation, the only variable that can perform this is the clauses->last_assigned_var

            // If the value is true, then the clause is true, we therefore need
            // to update the filter of calculated clauses meaning that the variable
            // contributes to the clause to be evaluated as true
            clauses->calculated_clauses_filter[clause_id] = var_id;
            // Update the counters
            clauses->num_true_clauses++;
            clauses->num_unknown_clauses--;

            return;
        }
    }

    if(ret == FALSE) {
        // Update the filter, it is usefull to compensate the counters once we want to undo the assignment
        // Store with the negative value
        // The last variable that was evaluated in this clause was the clauses->last_assigned_var
        // therefore it's the one responsible by setting the clause value to false
        int8_t decisive_variable = clauses->last_assigned_var;
        clauses->calculated_clauses_filter[clause_id] = -decisive_variable;

        // Update the counters
        clauses->num_false_clauses++;
        clauses->num_unknown_clauses--;
    }

    return;

on_error:
    ASSERT_EXIT();
}

/*********************************End of clauses.c*********************************/

#include <omp.h>
#include <stdlib.h>

void print_result(struct clauses_repr *clauses_repr, struct result result) { 
    printf("%" PRIu16 " %" PRIu64 "\n", result.maxsat_value, result.na);

    uint8_t num_vars = clauses_repr_num_vars(clauses_repr);

    for(int i = 1; i <= num_vars; i++) { 
        if(assignment_get_var(result.sample, i)) {
            printf("%d ", i);
        } else {
            printf("-%d ", i);
        }
    }
}

int main(int argc, char * argv[]){


    bool parse_only = false;
    bool debug = false;
    bool info = false;
    char * filename = NULL;
    ASSERT_MSG(argc <= 4 && argc >= 2, "Invalid number of arguments!\n prog_name [--parse-only] [--debug|--info] filename");
    for (int i = 1; i < argc; ++i) {
        if ((strcmp(argv[i], "--parse-only") == 0) && !parse_only) {
            parse_only = true;
        } else if ( (strcmp(argv[i], "--debug") == 0) && !debug && !info) {
            debug = true;
        } else if ( (strcmp(argv[i], "--info") == 0) && !debug && !info) {
            info = true;
        } else if (filename == NULL) {
            filename = argv[i];
        } else {
            ASSERT_ERROR("Failed to parse arguments. You could have duplicate flags, miss a filename, or mispelled the flags.");
        }
    }
    ASSERT_MSG(filename != NULL, "No filename given.");

    if(debug) {
        DEBUG_SET_LEVEL(DEBUG_LEVEL_DEBUG);
    } else if (info) {
        DEBUG_SET_LEVEL(DEBUG_LEVEL_INFO);
    }

    double start_time = omp_get_wtime();
    struct new_clauses_repr_from_file clauses_repr_from_file = new_clauses_repr_from_file(filename);
    LOG_INFO("parse time: %fs", omp_get_wtime() - start_time);
    ASSERT_MSG(clauses_repr_from_file.success, "Couldn't parse given filename");

    if (parse_only) {
        free_clauses_repr(clauses_repr_from_file.clauses_repr);
        return 0;
    }

    //clauses_repr_from_file created successfully
    struct clauses_repr *clauses_repr = clauses_repr_from_file.clauses_repr;

    start_time = omp_get_wtime();
    struct result result = maxsat(clauses_repr);
    LOG_INFO("maxsat time: %fs", omp_get_wtime() - start_time);

    print_result(clauses_repr, result);

    free_clauses_repr(clauses_repr_from_file.clauses_repr);

    return 0;

on_error:
    return 1;
}

/**********************************End of main.c***********************************/

