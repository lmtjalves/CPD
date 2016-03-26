#ifndef CLAUSES_H__
#define CLAUSES_H__

#include <stdint.h>
#include <stdbool.h>

#include "assignment.h"
#include "result.h"
#include "clauses_repr.h"


// Struct used to represent an instance of clauses_repr
struct clauses {
	// The clauses representation
	struct clauses_repr* clauses_repr;

	// An assignment to the variables in the clause
	struct assignment assignment;

	// Index of the last assigned var that can't be changed
	uint8_t last_assigned_var;

	// Array with the same size as the number of clauses that is used
	// to keep tracking of the variable that is responsible by maintaining that
	// clause value true.
	int8_t *calculated_clauses_filter;

	// Amount of clauses evaluated to true
	uint16_t num_true_clauses;

	// Amount of clauses evaluated to false
	uint16_t num_false_clauses;

	// Amount of clauses who's value is unknown yet
	uint16_t num_unknown_clauses;
};

/* Returns the maxsat of the given group of clauses.
 */
struct result maxsat(struct clauses_repr *clauses_repr);

void partial_maxsat(struct clauses *clauses, struct result *result, uint8_t var_to_test);
bool should_prune(struct clauses *clauses, struct result *result);
void rollback_assignment_to_var(struct clauses *clauses, uint8_t var);
void eval_var_clauses(struct clauses *clauses, uint8_t var);
void eval_clause(struct clauses *clauses, uint16_t clause_id);

struct clauses *new_stack_clauses(struct clauses_repr *clauses_repr, struct assignment assignment, uint8_t last_assigned_var);

#endif /*CLAUSES_H__*/
