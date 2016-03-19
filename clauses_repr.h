

#ifndef CLAUSES_REPR_H__
#define CLAUSES_REPR_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*These fixme just mark the spot where "project specific" cosntraints are abused to optimized space*/
struct clauses_repr {
    uint32_t *var_clauses_index; /*FIXME: at most 20 vars/clause, 65535 clauses. 20*65536 can be index with 32 bits unsigned interger*/
    uint16_t *var_clauses_index_clauses; /*FIXME: at most 65535 clause, so we can represent with 16 bits*/

    uint32_t *clause_num_index; /*FIXME: same reason as var_clauses_index*/
    int8_t *clause_num_index_clauses; /*FIXME: at most 127 vars, and negative is represented with 8th bit, so 8 bits per var is enough */ 
};

struct new_stack_clauses_repr_from_file {
    struct clauses_repr clauses_repr;
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

struct new_stack_clauses_repr_from_file new_stack_clauses_repr_from_file(const char *file_path);
void free_clauses_repr(struct clauses_repr *clauses_repr);
struct clauses_repr_clauses_of clauses_repr_clauses_of(const struct clauses_repr *clauses_repr, uint8_t var);
struct clauses_repr_clause clauses_repr_clause(const struct clauses_repr *clauses_repr, uint16_t clause);

#endif
