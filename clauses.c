#include "clauses.h"
#include "assignment.h"
#include "assert.h"
#include "debug.h"
#include "mpi_utils.h"

#include <mpi.h>
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

/*ways to solve maxsat*/
void maxsat_single(const struct crepr *crepr, struct result *result);
void maxsat_master(const struct crepr *crepr, struct result *result);
void maxsat_slave(const struct crepr *crepr);

/*master/slave communication*/
/*problem step*/
void maxsat_problem_send(uint64_t *msg, int dest);
void maxsat_problem_recv(uint64_t *msg, int source);
void slave_request_problem(struct result *result,
                           uint64_t *prob,
                           size_t *num_init_vars);
void master_give_problem(struct result *result,
                         uint64_t prob,
                         uint64_t num_init_vars);

/*problem splitting*/
uint8_t num_bit_len(int num);

void maxsat_prob_division(const uint8_t num_vars,
                          const size_t num_workers,
                          uint64_t *num_problems,
                          uint64_t *num_init_vars);

/*ancillary*/
void sync_result(struct result *result, struct result *sync_result);
void count_thread_time(double start_time,
                        double *first_finish_time,
                        double *last_finish_time);

/*maxsat solving functions*/
void do_maxsat(const struct crepr *crepr, struct result *result, uint8_t num_init_vars, uint64_t prob);
void partial_maxsat(struct clauses *clauses, struct result *result);
void do_partial_maxsat(struct clauses *clauses, struct result *result, uint8_t var);
bool should_prune(struct clauses *clauses, struct result *result);
void rollback_assignment_to_var(struct clauses *clauses, uint8_t var);
void eval_var_clauses(struct clauses *clauses, uint8_t var);
void eval_clause(struct clauses *clauses, uint16_t clause_id);





/* Public function */

struct result maxsat(const struct crepr *crepr) {
    ASSERT_NON_NULL(crepr);
    struct result result = new_stack_result();

    if (mpi_size() == 1) {
        maxsat_single(crepr, &result);
    } else if (is_mpi_master()) {
        maxsat_master(crepr, &result);
    } else {
        maxsat_slave(crepr);
    }

    LOG_DEBUG("mpi:%zu finished maxsat. maxsat:%"PRIu16" na:%"PRIu64" assignment:%.16"PRIx64" %.16"PRIx64,
              mpi_rank(),
              result_maxsat(&result),
              result_na(&result),
              result_assignment(&result).vars[1], /*FIXME?*/
              result_assignment(&result).vars[0]);

    return result;

on_error:
    ASSERT_EXIT();
}


/*
 *
 * Private functions
 *
 */



/*
 *
 * ways to solve maxsat
 *
 */

/*Solves the maxsat withotu using mpi*/
void maxsat_single(const struct crepr *crepr, struct result *result) {
    do_maxsat(crepr, result, 0, 0);
}

/* The protocol is the following:
 *
 * A slave sends a request to master, in the format: |mpi_rank|maxsat|na|a[0]|a[1]|
 *  mpi_rank is it's mpi_rank, so the master know who to send the problem to.
 *  maxsat is it's current best maxsat,
 *  na is the number of assignments it for that maxsat it got in the last problem.
 *  a is a maxsat assignment
 *
 * The master answers a request in the format: |prob|num_init_vars|maxsat|0|0|
 *  prob is the problem the slave must solve
 *  num_init_vars is self explanatory
 *  maxsat is the value of the best maxsat it has seen until now.
 *
 * Master uses sync_result to sync the maxsat, na and assignment given by
 *  the slave with it's result.
 * Slave registers the maxsat if it's better than the one it has.
 *
 * When there are no more problems, the master answers with UINT_MAX64.
 * This signals the slave to stop solving problems.
 * Then the master moves on and the slaves stopped eventually.
 * */

/* slave:  |rank|maxsat|na|assignment[0]|assignment[1]|
 * master: |prob|vars|maxsat|0|0| the 0s are so that we use the same len*/
const int PROBLEM_REQUEST_LEN = 5;
const int PROBLEM_REQUEST_TAG = 1000;

/* no tag needed since it's a broadcast
 * |maxsat|na|assignment[0]|assignment[1]*/
const int MAXSAT_SYNC_LEN = 4;

void maxsat_master(const struct crepr *crepr, struct result *result) {
    uint64_t num_problems, num_init_vars;

    maxsat_prob_division(crepr_num_vars(crepr),
                         mpi_size() - 1, /*-1 because the master isn't a worker*/
                         &num_problems,
                         &num_init_vars);

    LOG_DEBUG("Distributing %"PRIu64 " problems with %"PRIu64" initialized vars.",
              num_problems,
              num_init_vars);

    uint64_t cur_problem = 0;
    while(cur_problem < num_problems) {
        master_give_problem(result, cur_problem, num_init_vars);
        ++cur_problem;
    }

    double sync_start_time = omp_get_wtime();

    uint64_t num_shutdown_sent = 0;
    while(num_shutdown_sent < (mpi_size() - 1)) {
        master_give_problem(result, UINT64_MAX, 0);
        ++num_shutdown_sent;
    }

    LOG_DEBUG("mpi:%zu took %fs to sync.", mpi_rank(), omp_get_wtime() - sync_start_time);

    return;

}


void maxsat_slave(const struct crepr *crepr) {
    struct result slave_result = new_stack_result();
    LOG_DEBUG("mpi:%zu Solving maxsat!", mpi_rank());

    /*Only accessed by omp master*/
    double total_req_time = 0, total_computation_time = 0, total_thread_wait_time = 0;
    double start_computation_time;

    /*These are accessed by all threads at the end of each loop.
     * They're initialized by the master in the beginning*/
    double start_time;
    double first_finish_time = -1, last_finish_time = 0;

    /*these variables are shared, but written only my omp master when the other
     *  threads are waiting, so no synchronization is used to access them*/
    uint64_t prob, num_init_vars;
    #pragma omp parallel
    while (true) {
        #pragma omp master
        {
            start_time = omp_get_wtime();
            first_finish_time = -1;
            last_finish_time = 0;

            double req_time = start_time;
            slave_request_problem(&slave_result, &prob, &num_init_vars);
            total_req_time += omp_get_wtime() - req_time;

            LOG_DEBUG("mpi:%zu received problem:%"PRIu64, mpi_rank(), prob);

            /*The na sent is for the problem solved, so we have to clean it*/
            result_set_na(&slave_result, 0);

            start_computation_time = omp_get_wtime();
        }

        /*Every thread must wait for master to reach here with a valid prob*/
        #pragma omp barrier

        if(prob == UINT64_MAX) {
            break;
        }

        do_maxsat(crepr, &slave_result, num_init_vars, prob);

        #pragma omp critical
        count_thread_time(start_time, &first_finish_time, &last_finish_time);


        #pragma omp master
        {
            total_computation_time += omp_get_wtime() - start_computation_time;
            total_thread_wait_time += (last_finish_time - first_finish_time);
        }

        /*We must synchronize all threads at the beginning or at the end of
         * each problem cycle, otherwise a thread that only starts running
         * from the other barrier in the next cycle, after the master thread
         * got the order to stop exists without going to the barrier again
         * and the other threads wait there indefinetely*/
        #pragma omp barrier

    }

    start_time = omp_get_wtime();

    LOG_DEBUG("mpi:%zu total_req_time:%fs total_computation_time:%fs total_thread_wait_time:%fs sync_time:%fs",
              mpi_rank(),
              total_req_time,
              total_computation_time,
              total_thread_wait_time,
              omp_get_wtime() - start_time);
}


/*
 * master/slave communication
 */

/*
 *
 * problem step
 *
 */
void maxsat_problem_send(uint64_t *msg, int dest) {
    int mpi_ret = MPI_Send(msg,
                       PROBLEM_REQUEST_LEN,
                       MPI_UINT64_T,
                       dest,
                       PROBLEM_REQUEST_TAG,
                       MPI_COMM_WORLD);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed mpi send");
    return;

on_error:
    ASSERT_EXIT();
}

void maxsat_problem_recv(uint64_t *msg, int source) {
    int mpi_ret = MPI_Recv(msg,
                       PROBLEM_REQUEST_LEN,
                       MPI_UINT64_T,
                       source,
                       PROBLEM_REQUEST_TAG,
                       MPI_COMM_WORLD,
                       MPI_STATUS_IGNORE);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed mpi recv.");
    return;

on_error:
    ASSERT_EXIT();
}


void slave_request_problem(struct result *result, uint64_t *prob, size_t *num_init_vars) {
    uint64_t msg_buf[PROBLEM_REQUEST_LEN];

    msg_buf[0] = mpi_rank();
    msg_buf[1] = result_maxsat(result);
    msg_buf[2] = result_na(result);
    msg_buf[3] = result_assignment(result).vars[0]; /*FIXME?*/
    msg_buf[4] = result_assignment(result).vars[1]; /*FIXME?*/;

    maxsat_problem_send(msg_buf, mpi_master());
    maxsat_problem_recv(msg_buf, mpi_master());

    *prob = msg_buf[0];
    *num_init_vars = msg_buf[1];
    uint64_t master_maxsat = msg_buf[2];

    if(master_maxsat > result_maxsat(result)) {
        result_set_maxsat(result, master_maxsat);
    }
}

void master_give_problem(struct result *result,
                         uint64_t prob,
                         uint64_t num_init_vars) {
    uint64_t msg_buf[PROBLEM_REQUEST_LEN];

    maxsat_problem_recv(msg_buf, MPI_ANY_SOURCE);

    uint64_t requester = msg_buf[0];
    uint64_t slave_maxsat = msg_buf[1];
    uint64_t slave_na = msg_buf[2];
    struct assignment slave_assignment = new_stack_assignment_from_num(msg_buf + 3);

    struct result slave_result = new_stack_result();
    result_set_maxsat(&slave_result, slave_maxsat);
    result_set_na(&slave_result, slave_na);
    result_set_assignment(&slave_result, slave_assignment);
    sync_result(result, &slave_result);

    msg_buf[0] = prob;
    msg_buf[1] = num_init_vars;
    msg_buf[2] = result_maxsat(result);
    msg_buf[3] = 0;
    msg_buf[4] = 0;

    maxsat_problem_send(msg_buf, requester);

}


/* Calculate the maxsat result for the crepr.
 * schedule(dynamic) guarantees that all threads keep running for the
 * same approximate ammount of time, because they keep getting
 * new problems if they finish early(vs static schedule).
 *nowait is used to measure the time difference between first and last
 * thread finishing. Without nowait there'd be a barrier before
 * measuring the time*/
void do_maxsat(const struct crepr *crepr, struct result *result, uint8_t num_init_vars, uint64_t prob) {
    struct result thread_result = new_stack_result();
    #pragma omp critical
    result_set_maxsat(&thread_result, result_maxsat(result));

    uint64_t num_subprob_init_threads, num_subprobs, subprob;
    maxsat_prob_division(crepr_num_vars(crepr) - num_init_vars,
                         omp_get_num_threads(),
                         &num_subprobs,
                         &num_subprob_init_threads);
    #pragma omp for schedule(dynamic) nowait
    for(subprob = 0; subprob < num_subprobs; ++subprob) {
        struct clauses clauses;
        ALLOC_LOCAL_CLAUSES(clauses, crepr);

        /*the least num_init_vars least significant bits of prob
         * have the assignments for the num_init_vars least sig bits*/
        uint64_t assignment_num[2] = {0, (prob << 1) + (subprob << (num_init_vars + 1))};
        struct assignment assignment = new_stack_assignment_from_num(assignment_num);

        INIT_LOCAL_CLAUSES(clauses, crepr, assignment, num_init_vars + num_subprob_init_threads);

        /*Solve the partial problem starting with num_init_vars
         * assigned*/
        partial_maxsat(&clauses, &thread_result);

        LOG_DEBUG("thread:%d assignment:%zu/%"PRIu64" of %"PRIu64"/%zu maxsat:%"PRIu16" na:%"PRIu64,
                omp_get_thread_num(),
                subprob,
                num_subprobs - 1,
                prob,
                (((size_t)1 << num_init_vars)  - 1),
                result_maxsat(&thread_result),
                result_na(&thread_result));

    }


    #pragma omp critical
    sync_result(result, &thread_result);
}




/*
 *
 * problem splitting
 *
 */

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

/* Chooses how many num_init_vars and problems in function of num_vars
 *  and num_workers
 *
 * num_problems is the value of the number of problems,
 * num_initialized variables is the number of bits in num_problems
 * that's why we use we add values to num_initiliazed variables, because
 * when we use << to assign num_problems, all the + are turned in * */
void maxsat_prob_division(const uint8_t num_vars,
                          const size_t num_workers,
                          uint64_t *num_problems,
                          uint64_t *num_init_vars) {

    /*We would like that each process have 32(log2(32)=5) problems.*/
    const uint8_t num_vars_per_worker = 5;
    /*we want each subproblem to have at least 4096 evaluations*/
    const uint8_t min_num_vars_remaining = 12;

    /* num_bit_len() - 1 because when there's only 1 worker, we don't want to
     *  add more vars.*/
    *num_init_vars = num_vars_per_worker + num_bit_len(num_workers) - 1;

    #pragma omp master
    LOG_DEBUG("maxsat: %zu workers, num_init_vars %" PRIu64 " of %"PRIu8 ,
            num_workers,
            *num_init_vars,
            num_vars);

    /*too many workers for problem size,
     * would give more init_vars than there are vars*/
    if (num_vars < min_num_vars_remaining) {
        *num_init_vars = 0;
        #pragma omp master
        LOG_DEBUG("Reducing num_init_vars to %" PRIu64, *num_init_vars);
    } else if(*num_init_vars > num_vars
       || ((num_vars - *num_init_vars) < min_num_vars_remaining) ) {
        *num_init_vars = num_vars - min_num_vars_remaining;
        #pragma omp master
        LOG_DEBUG("Reducing num_init_vars to %" PRIu64, *num_init_vars);
    }

    *num_problems = 1 << (*num_init_vars);
    return;
}



/*
 *
 * ancillary
 *
 */

/*If sync_result is better than result, result is set to sync_result,
 * if they have the same maxsat, sync_result na is added to result
 * if sync_result is worse than, sync_result's maxsat is to to result*/
void sync_result(struct result *result, struct result *sync_result) {
    if(result_maxsat(result) > result_maxsat(sync_result)) {
        result_set_maxsat(sync_result, result_maxsat(result));
    } else if (result_maxsat(result) < result_maxsat(sync_result)) {
        result_set_maxsat(result, result_maxsat(sync_result));
        result_set_assignment(result, result_assignment(sync_result));
        result_set_na(result, result_na(sync_result));
    } else {
        result_set_na(result, result_na(result) + result_na(sync_result));
    }
}

void count_thread_time(double start_time,
                       double *first_finish_time,
                       double *last_finish_time) {
    const double thread_finish_time = omp_get_wtime() - start_time;
    if (*first_finish_time < 0) {
        *first_finish_time = thread_finish_time;
    }

    *last_finish_time = thread_finish_time;
}



/*
 *
 * maxsat solving functions
 *
 */

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

    return result_maxsat(result) > max_possible_true_clauses;
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
