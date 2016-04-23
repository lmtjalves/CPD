#include "clauses.h"
#include "assignment.h"
#include "assert.h"
#include "debug.h"

#include <omp.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

/*calculated_clauses_filter:
 * Array that keep track of the state of a clause value.
 * A value of 0 represents that the clause's value could still be positive
 * A value >0 represents the FIRST variable that makes the clause positive
 * A value <0 represents the LAST variable such that after it being set,
 *  all the variables in the clause have a value, and they're all negative.*/
struct clauses {
    const struct crepr* crepr;
    struct assignment assignment;
    uint8_t last_assigned_var;
    int8_t *calculated_clauses_filter;
    uint16_t num_true_clauses;
    uint16_t num_false_clauses;
    uint16_t num_unknown_clauses;
};



/*Ancillary macros for initing and allocing struct clauses in the stack*/
/*Not insied do{}while(0) because that'd release the array memory*/
#define ALLOC_LOCAL_CLAUSES(CLAUSES, CREPR) \
int8_t calculated_clauses_filter_ ## CLAUSES [crepr_num_clauses(CREPR)];\
CLAUSES.calculated_clauses_filter = calculated_clauses_filter_ ## CLAUSES

#define INIT_LOCAL_CLAUSES(CLAUSES, CREPR, ASSIGNMENT, LAST_ASSIGNED_VAR) \
do { \
    CLAUSES.crepr = CREPR; \
    CLAUSES.assignment = ASSIGNMENT; \
    CLAUSES.last_assigned_var = LAST_ASSIGNED_VAR; \
    memset(CLAUSES.calculated_clauses_filter, 0 , crepr_num_clauses(CREPR) * sizeof(int8_t)); \
    CLAUSES.num_true_clauses = 0; \
    CLAUSES.num_false_clauses = 0; \
    CLAUSES.num_unknown_clauses = crepr_num_clauses(CREPR); \
} while(0)

/*private functions*/
uint8_t num_bit_len(int num);
void maxsat_prob_division(const struct crepr *crepr,
                          size_t *num_problems,
                          uint8_t *num_initialized_vars);
void partial_maxsat(struct clauses *clauses, struct result *result);
void do_partial_maxsat(struct clauses *clauses, struct result *result, uint8_t var);
bool should_prune(struct clauses *clauses, struct result *result);
void rollback_assignment_to_var(struct clauses *clauses, uint8_t var);
void eval_var_clauses(struct clauses *clauses, uint8_t var);
void eval_clause(struct clauses *clauses, uint16_t clause_id);




/* Public functions */

/* Calculate the maxsat result for the crepr. 
 * schedule(dynamic) guarantees that all threads keep running for the
 * same approximate ammount of time, because they keep getting 
 * new problems if they finish early(vs static schedule).
 *nowait is used to measure the time difference between first and last
 * thread finishing. Without nowait there'd be a barrier before 
 * measuring the time*/ 
struct result maxsat(const struct crepr *crepr) {
    ASSERT_NON_NULL(crepr);

    struct result result = new_stack_result();

    const double start_time = omp_get_wtime();
    double first_finish_time = -1;
    double last_finish_time = 0;

    /*result is shared, other variables are declared inside block -> private*/
#pragma omp parallel 
    {
        struct result local_result = new_stack_result();
        struct clauses clauses;
        ALLOC_LOCAL_CLAUSES(clauses, crepr);

        size_t num_problems;
        uint8_t num_initialized_vars;
        maxsat_prob_division(crepr, &num_problems, &num_initialized_vars);

#pragma omp for schedule(dynamic) nowait
        for(uint64_t i = 0; i < num_problems; i++) {
            /*the least num_initialized_vars least significant bits of i
             * have the assignments for the num_initialized_vars least sig bits*/
            struct assignment assignment = new_stack_assignment_from_num((uint64_t [2]){0, i<<1});
            result_set_na(&local_result, 0);

            INIT_LOCAL_CLAUSES(clauses, crepr, assignment, num_initialized_vars);

            /*Solve the partial problem starting with num_initialized_vars
             * assigned*/
            partial_maxsat(&clauses, &local_result);

            LOG_DEBUG("thread: %d assignment:%"PRIu64"/%zu maxsat:%"PRIu16" na:%"PRIu64,
                      omp_get_thread_num(),
                      i,
                      num_problems,
                      result_get_maxsat_value(&local_result),
                      result_get_na(&local_result));

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



/*Private functions*/

/*counts the number of bits in the representation of num.
 * e.g. num_bit_len(3) = 2
 *      num_bit_len(15) = 4*/
uint8_t num_bit_len(int num) {
    uint8_t cur_bit = 0;
    while(num) {
        num >>= 1;
        ++cur_bit;
    }
    return cur_bit;
}

/* Chooses how many num_initialized_vars there should be in function of the
 *  number of omp threads.
 *
 * num_problems is the value of the number of problems,
 * num_initialized variables is the number of bits in num_problems
 * that's why we use we add values to num_initiliazed variables, because
 * when we use << to assign num_problems, all the + are turned in * */
void maxsat_prob_division(const struct crepr *crepr,
                          size_t *num_problems,
                          uint8_t *num_initialized_vars) {

    /*We would like that each thread have 64(log2(64)=6) problems.*/
    const uint8_t num_vars_per_thread = 6; 
    /*We want that each thread has at least 16 problems*/
    const uint8_t min_num_vars_per_thread = 4; 
    const uint8_t num_vars = crepr_num_vars(crepr);

    /* num_bit_len() - 1 because we don't want num_threads to contribute, when
     *  there is only 1 thread.*/
    *num_initialized_vars = num_vars_per_thread + num_bit_len(omp_get_num_threads()) - 1;

#pragma omp master
    {
        LOG_DEBUG("maxsat: %d threads, num_initialized_vars %" PRIu8 " of %"PRIu8 ,
                  omp_get_num_threads(),
                  *num_initialized_vars,
                  num_vars);
    } 

    if ( num_vars - *num_initialized_vars < min_num_vars_per_thread) {
        /*too few vars in problem*/
        if (num_vars >= min_num_vars_per_thread) {
            /* problems size too small*/
            *num_initialized_vars = num_vars - min_num_vars_per_thread;
        } else {
            /*problem really small*/
            *num_initialized_vars = 1;
        }
#pragma omp master
        {
            LOG_DEBUG("Reducing num_initialized_vars to %" PRIu8, *num_initialized_vars);
        }
    }

    *num_problems= 1 << (*num_initialized_vars);
    return;
}




/* Calculate the maxsat for the partial assigment to the variables in the crepr.*/
void partial_maxsat(struct clauses *clauses, struct result *result) {
    size_t var;

    /*We're initializing(filling filter) the subproblems variables here instead
     * of in the constructor of clauses.*/
    for(var=1; var <= clauses->last_assigned_var; ++var) {
        eval_var_clauses(clauses, var);
        if(should_prune(clauses, result)) {
            return;
        }
    }
    do_partial_maxsat(clauses, result, clauses->last_assigned_var + 1);


    return;
}

void do_partial_maxsat(struct clauses *clauses, struct result *result, uint8_t var) {
    if(var > crepr_num_vars(clauses->crepr)) {
        /*Reached leaf node, update result(noop if not better)
         * and start going back. Condition must be >. when ==, it's the leaf node*/
        result_update(result, clauses->num_true_clauses, clauses->assignment);
        return;
    }

    // We can assign to the variable two values, false/0 or true/1
    for(int i = 0; i <= 1; i++) {
        assignment_set_var(&(clauses->assignment), var, i);
        ++(clauses->last_assigned_var);

        eval_var_clauses(clauses, var);

        if(!should_prune(clauses, result)){
            do_partial_maxsat(clauses, result, var + 1);
        }

        rollback_assignment_to_var(clauses, var);
        --(clauses->last_assigned_var);
    }
}


/*Returns true if we should prune the current branch,
 *  because it can't improve maxsat*/
bool should_prune(struct clauses *clauses, struct result *result) {
    uint16_t max_possible_true_clauses = clauses->num_true_clauses + clauses->num_unknown_clauses;

    return result_get_maxsat_value(result) > max_possible_true_clauses;
}


/* Reverts the changes in the state performed by assigning a value to a variable.
 * It will update the counters and the calculated_clauses_filter accordingly.*/
void rollback_assignment_to_var(struct clauses *clauses, uint8_t var) {
    struct crepr_clauses_of var_clauses = crepr_clauses_of(clauses->crepr, var);

    for(uint16_t i = 0; i < var_clauses.len; i++) {
        uint16_t clause_id = var_clauses.first[i];
        int8_t clause_filter_value = clauses->calculated_clauses_filter[clause_id];

        if(abs(clause_filter_value) == var) {
            //The variable is the one that is determining the value of the clause
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
}


/* Evaluates all the clauses where the var appears.
 * Updates the internal counter and the filter accordingly.*/
void eval_var_clauses(struct clauses *clauses, uint8_t var) {
    struct crepr_clauses_of var_clauses = crepr_clauses_of(clauses->crepr, var);

    for(size_t i = 0; i < var_clauses.len; i++) {
        eval_clause(clauses, var_clauses.first[i]);
    }

    return;
}


// Use this enum just to make the code more readable when we refer to the third state
enum clause_value {
    TRUE,
    FALSE,
    UNKNOWN
};

/* Evaluates a clause based on the variables assignments and on the filter, and
 *  updates clauses accordingly.*/
void eval_clause(struct clauses *clauses, uint16_t clause_id) {
    if(clauses->calculated_clauses_filter[clause_id] !=  0) {
        /*clause's value already determined*/
        return;
    }

    struct crepr_clause clause = crepr_clause(clauses->crepr, clause_id);

    // Assume it's value is false
    enum clause_value ret = FALSE;
    for(size_t i = 0; i < clause.len; i++) {
        // may be > 0 or < 0 if should be negated (~)
        int8_t var = clause.first[i]; 
        int8_t var_id = abs(var);

        if(var_id > clauses->last_assigned_var) {
            /*var is unassinged. clauses can only be TRUE or UNKNOWN now*/
            ret = UNKNOWN;
            continue;
        }

        bool var_value =  assignment_get_var(clauses->assignment, var_id);
        if( (var_value && (var > 0)) || (!var_value && (var < 0))) {
            /* clause is true, because:
             * var is assigned true and var is positive in clause 
             * OR var is assigned false and var is negative in clause*/

            /*var_id sets the clause to true, so we write it in the filter*/
            clauses->calculated_clauses_filter[clause_id] = var_id;
            ++(clauses->num_true_clauses);
            --(clauses->num_unknown_clauses);
            return;
        }
    }

    if(ret == FALSE) {
        /*We write in the filter that last_assigned_var is responsible for the
         *  clause being false. When we rollback last_assigned_var the clause
         *  is set to unknown again.*/
        int8_t decisive_variable = clauses->last_assigned_var;
        clauses->calculated_clauses_filter[clause_id] = -decisive_variable;
        clauses->num_false_clauses++;
        clauses->num_unknown_clauses--;
    }

    return;
}
#undef ALLOC_LOCAL_CLAUSES
#undef INIT_LOCAL_CLAUSES
