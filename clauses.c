#include "clauses.h"
#include "math.h"
#include "assert.h"


void partial_maxsat(struct clauses *clauses, struct result *result, uint8_t var_to_test);
bool should_prune(struct clauses *clauses, struct result *result);
void rollback_assignment_to_var(struct clauses *clauses, uint8_t var);
void eval_var_clauses(struct clauses *clauses, uint8_t var);
void eval_clause(struct clauses *clauses, uint16_t clause_id);

struct clauses *new_stack_clauses(struct clauses_repr *clauses_repr, struct assignment assignment, uint8_t last_assigned_var) {
	ASSERT_NON_NULL(clauses_repr);

	uint16_t num_clauses = clauses_repr_num_clauses(clauses_repr);
	struct clauses *ret = NULL;
	ASSERT_MALLOC(struct clauses, ret, 1);
	ret->clauses_repr = clauses_repr;
	ret->assignment = assignment;
	ret->last_assigned_var = last_assigned_var;
	ASSERT_MALLOC(int8_t, ret->calculated_clauses_filter, num_clauses);
	ret->num_true_clauses = 0;
	ret->num_false_clauses = 0;
	ret->num_unknown_clauses = num_clauses;

	return ret;

on_error:
	ASSERT_EXIT();
}


/* Free the internal components of the structure.
 * Receives the value and not the pointer for this reason.
 */
void free_clauses(struct clauses *clauses) {
	ASSERT_NON_NULL(clauses->calculated_clauses_filter);

	free(clauses->calculated_clauses_filter);
	free(clauses);

	return;

on_error:
	ASSERT_EXIT();
}


/* Calculate the maxsat result for the clauses_repr.
 */
struct result maxsat(struct clauses_repr *clauses_repr) {
	ASSERT_NON_NULL(clauses_repr);

	// The maxsat result
	struct result result = new_stack_result();

	// For now just let the number of initialized variables equal
	// to the number of threads FIXME
	uint64_t num_initialized_vars = 1;

	uint64_t num_chunks = 1 << num_initialized_vars;
	#pragma omp parallel for schedule(dybamic)
	for(uint64_t i = 0; i < num_chunks; i++) {
		uint64_t initial_assignment[2] = {0, i};
		struct assignment assignment = new_stack_assignment_from_num(initial_assignment);
		struct clauses *clauses = new_stack_clauses(clauses_repr, assignment, num_initialized_vars);

		partial_maxsat(clauses, &result, 1);
		free_clauses(clauses);
	}

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
		// Check if we achieved a maxsat value or not and update if so update the
		result_update(result, clauses->num_true_clauses, clauses->assignment);
	} else if(var_to_test < clauses->last_assigned_var) {
		// The variable as already a fixed value assigned, don't branch, just evaluate
		// and go to the next variable.
		eval_var_clauses(clauses, var_to_test);

		// Stop if there's already a better result
		if(should_prune(clauses, result)) return;

		partial_maxsat(clauses, result, var_to_test + 1);
		// No need to compensate in this case, since all the previous variables also
		// have a fixed value
	} else {
		// We can assign to the variable two values, true or false
		for(int i = 0; i < 1; i++) {
			assignment_set_var(&(clauses->assignment), var_to_test, true);
			clauses->last_assigned_var++;
			eval_var_clauses(clauses, var_to_test);

			// Don't follow this assignment if there's a better result already
			if(should_prune(clauses, result)) break;

			// Go to the next variable
			partial_maxsat(clauses, result, var_to_test + 1);

			// Rollback to undo the effects of this assignment
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

	uint16_t max_true_clauses = clauses->num_true_clauses + clauses->num_unknown_clauses;
	return result_get_maxsat_value(result) > max_true_clauses;

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
				clauses->num_false_clauses--;
			} else {
				clauses->num_true_clauses--;
			}
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

	// FIXME Possible enhancement, stop when it wont improve the maxsat (aka prunning)
	for(uint16_t i = 0; i < var_clauses.len; i++) {
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
	// Just keep it for symmetry.
	if(clauses->calculated_clauses_filter[clause_id] !=  0) return;

	// Get the clause we want to evaluate
	struct clauses_repr_clause clause = clauses_repr_clause(clauses->clauses_repr, clause_id);

	// Assume it's value is false
	enum clause_value ret = FALSE;
	int8_t var = 0;
	for(int i = 0; i < clause.len; i++) {
		var = clause.first[i];

		if(abs(var) > clauses->last_assigned_var) {
			// If the variable has no value assigned yet, then the clause value
			// can no longer be FALSE, only TRUE or UNKNOWN
			ret = UNKNOWN;
		} else if(assignment_get_var(clauses->assignment, abs(var)) != (var < 0)) {
			// var < 0 means that the value should be negated
			// If the value is true, then the clause is true, we therefore need
			// to update the filter of calculated clauses meaning that the variable
			// contributes to the clause to be evaluated as true
			clauses->calculated_clauses_filter[clause_id] = abs(var);

			// Update the counters
			clauses->num_true_clauses++;
			clauses->num_unknown_clauses--;

			return;
		}
	}

	if(ret == FALSE) {
		// Update the filter, it is usefull to compensate the counters once we want to undo the assignment
		// Store with the negative value
		clauses->calculated_clauses_filter[clause_id] = -abs(var);

		// Update the counters
		clauses->num_false_clauses++;
		clauses->num_unknown_clauses--;
	}

	return;

on_error:
	ASSERT_EXIT();
}
