
#include "parse_long.h"

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
