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
