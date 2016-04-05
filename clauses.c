#include "clauses.h"
#include "assignment.h"
#include "assert.h"
#include "debug.h"

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

    /*We don't declare any variable private because they're already private by being in a new block.
     * Only result is shared.*/
#pragma omp parallel 
    {
        struct result local_result = new_stack_result();
        struct clauses clauses;
        ALLOC_LOCAL_CLAUSES(clauses, clauses_repr);
        const struct maxsat_prob_division prob_division = maxsat_prob_division(clauses_repr);

#pragma omp for schedule(dynamic)
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

            LOG_DEBUG("thread: %d assignment:%"PRIu64 "/%"PRIu64 " maxsat:%" PRIu16 " na:%"PRIu64, omp_get_thread_num(), i, prob_division.num_problems, result_get_maxsat_value(&local_result), result_get_na(&local_result));

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
