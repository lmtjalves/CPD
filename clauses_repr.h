

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
