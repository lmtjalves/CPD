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
