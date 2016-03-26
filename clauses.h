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

#endif /*CLAUSES_H__*/
