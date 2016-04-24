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
void maxsat_slave(const struct crepr *crepr, struct result *result);

/*master/slave communication*/
/*problem step*/
void maxsat_problem_send(uint64_t *msg, int dest);
void maxsat_problem_recv(uint64_t *msg, int source);
void slave_request_problem(struct result *result,
                           uint64_t *prob,
                           size_t *num_initialized_vars);
void master_give_problem(struct result *result,
                         uint64_t prob,
                         uint64_t num_initialized_vars,
                         uint64_t *best_maxsat_mpi_rank);
/*sync maxsat step*/
void slave_sync_maxsat(struct result *result);
void master_sync_maxsat(struct result *result, uint64_t best_maxsat_mpi_rank);


/*problem splitting*/
uint8_t num_bit_len(int num);
void maxsat_prob_division(const struct crepr *crepr,
                          uint64_t *num_problems,
                          uint64_t *num_initialized_vars);

/*ancillary*/
void sync_result(struct result *result, struct result *sync_result);
void count_thread_time(double start_time,
                        double *first_finish_time,
                        double *last_finish_time);

/*maxsat solving functions*/
void do_maxsat(const struct crepr *crepr, struct result *result, uint8_t num_initialized_vars, uint64_t prob);
void partial_maxsat(struct clauses *clauses, struct result *result);
void do_partial_maxsat(struct clauses *clauses, struct result *result, uint8_t var);
bool should_prune(struct clauses *clauses, struct result *result);
void rollback_assignment_to_var(struct clauses *clauses, uint8_t var);
void eval_var_clauses(struct clauses *clauses, uint8_t var);
void eval_clause(struct clauses *clauses, uint16_t clause_id);

const int PROBLEM_REQUEST_LEN = 3; /* |rank|maxsat|na| or |prob|vars|maxsat|*/
const int PROBLEM_REQUEST_TAG = 1000;
const int MAXSAT_SYNC_LEN = 3; /* |maxsat|na|best_rank|*/
const int MAXSAT_SYNC_TAG = 2000;



/* Public function */

struct result maxsat(const struct crepr *crepr) {
    ASSERT_NON_NULL(crepr);
    struct result result = new_stack_result();

    if (mpi_size() == 1) {
        maxsat_single(crepr, &result);
    } else if (is_mpi_master()) {
        maxsat_master(crepr, &result);
    } else {
        maxsat_slave(crepr, &result);
    }

    return result;

on_error:
    ASSERT_EXIT();
}


/*Private functions*/

/*Solves the maxsat withotu using mpi*/
void maxsat_single(const struct crepr *crepr, struct result *result) {
    do_maxsat(crepr, result, 0, 0);
}

/* The protocol is the following:
 * 
 * A slave sends a request to master, in the format: |maxsat|na|mpi_rank|
 *  maxsat is it's current best maxsat,
 *  na is the number of assignments it for that maxsat it got in the last problem.
 *  mpi_rank is it's mpi_rank, so the master know who to send the problem to.
 *
 * The master answers a request in the format: |prob|num_initialized_vars|maxsat|
 *  prob is the problem the slave must solve
 *  num_initialized_vars is self explanatory
 *  maxsat is the value of the best maxsat it has seen until now.
 *
 * Master uses sync_result to sync the the maxsat and na given by the slave
 *  with it's result.
 * Slave registers the maxsat if it's better than the one it has.
 * The master takes note of who was the last slave to improve the maxsat.
 *
 * When there are no more problems, the master answers with UINT_MAX64.
 * This signals the slave to stop solving problems.
 * After being signaled the slaves go to maxsat synchronization step.
 *
 * When all slaves are signaled, the master goes to the maxsat synchronization
 *  step.
 *
 * When on the maxsat sync step, the master broadcasts: |maxsat|na|mpi_rank|
 *  maxsat is the best maxsat obtained
 *  na is the total number of assignments for that maxsat
 *  mpi_rank is the rank of the slave that improved maxsat to that value
 *
 * Finally the slave with mpi_rank of the last broadcast send: |assignment|
 *  assignment an assignment that has maxsat true clasuses.
 * 
 * Now everyone has a valid result.
 * */

void maxsat_master(const struct crepr *crepr, struct result *result) {
    uint64_t best_maxsat_mpi_rank = UINT64_MAX;
    uint64_t num_problems, num_initialized_vars;

    maxsat_prob_division(crepr, &num_problems, &num_initialized_vars);

    LOG_DEBUG("Distributing %"PRIu64 " problems with %"PRIu64" initialized vars.",
              num_problems,
              num_initialized_vars);

    uint64_t cur_problem = 0;
    while(cur_problem < num_problems) {
        master_give_problem(result, cur_problem, num_initialized_vars, &best_maxsat_mpi_rank);
        ++cur_problem;
    }

    double sync_start_time = omp_get_wtime();

    uint64_t num_shutdown_sent = 0;
    while(num_shutdown_sent < (mpi_size() - 1)) {
        master_give_problem(result, UINT64_MAX, 0, &best_maxsat_mpi_rank);
        ++num_shutdown_sent;
    }

    ASSERT_MSG(best_maxsat_mpi_rank != UINT64_MAX,
               "Didn't register mpi rank with best maxsat.");
    master_sync_maxsat(result, best_maxsat_mpi_rank);

    LOG_DEBUG("mpi:%zu took %fs to sync.", mpi_rank(), omp_get_wtime() - sync_start_time);

    return;

on_error:
    ASSERT_EXIT();
}
void maxsat_slave(const struct crepr *crepr, struct result *result) {
    struct result slave_result = new_stack_result();
    LOG_DEBUG("mpi:%zu Solving maxsat!", mpi_rank());

    double total_req_time = 0, total_computation_time = 0, total_thread_wait_time = 0;

    /*#pragma omp parallel*/
    while (true) {
        const double start_time = omp_get_wtime();
        double first_finish_time = -1, last_finish_time = 0;
        uint64_t prob, num_initialized_vars;

        /*#pragma omp master
        {*/
        double req_time = omp_get_wtime();
        slave_request_problem(&slave_result, &prob, &num_initialized_vars);
        total_req_time += omp_get_wtime() - req_time;

        /*We only want to keep track of a single problem na, so we clean it after
         * sending it.*/
        result_set_na(&slave_result, 0);
        /*}*/

        /*#pragma omp barrier*/

        if(prob == UINT64_MAX) {
            break;
        }

        double start_computation_time = omp_get_wtime();
        /*#pragma omp master
          {*/
        do_maxsat(crepr, &slave_result, num_initialized_vars, prob);

        /*#pragma omp critical*/
        count_thread_time(start_time, &first_finish_time, &last_finish_time);
        /*}*/
        total_computation_time += omp_get_wtime() - start_computation_time;
        total_thread_wait_time += (last_finish_time - first_finish_time);
    }

    LOG_DEBUG("mpi:%zu total_req_time:%fs total_computation_time:%fs total_thread_wait_time:%fs",
              mpi_rank(),
              total_req_time,
              total_computation_time,
              total_thread_wait_time);

    slave_sync_maxsat(result);
}


/*master/slave communication*/
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


void slave_request_problem(struct result *result, uint64_t *prob, size_t *num_initialized_vars) {
    uint64_t msg_buf[PROBLEM_REQUEST_LEN];

    msg_buf[0] = result_maxsat(result);
    msg_buf[1] = result_na(result);
    msg_buf[2] = mpi_rank();

    maxsat_problem_send(msg_buf, mpi_master());
    maxsat_problem_recv(msg_buf, mpi_master());

    *prob = msg_buf[0];
    *num_initialized_vars = msg_buf[1];
    uint64_t master_maxsat = msg_buf[2];

    if(master_maxsat > result_maxsat(result)) {
        result_set_maxsat(result, master_maxsat);
    }
}

void master_give_problem(struct result *result,
                         uint64_t prob,
                         uint64_t num_initialized_vars,
                         uint64_t *best_maxsat_mpi_rank) {
    uint64_t msg_buf[PROBLEM_REQUEST_LEN];

    maxsat_problem_recv(msg_buf, MPI_ANY_SOURCE);

    uint64_t slave_maxsat = msg_buf[0];
    uint64_t slave_na = msg_buf[1];
    uint64_t requester = msg_buf[2];

    if(slave_maxsat > result_maxsat(result)) {
        *best_maxsat_mpi_rank = requester;
    }

    struct result slave_result = new_stack_result();
    result_set_maxsat(&slave_result, slave_maxsat);
    result_set_na(&slave_result, slave_na);
    sync_result(result, &slave_result);

    msg_buf[0] = prob;
    msg_buf[1] = num_initialized_vars;
    msg_buf[2] = result_maxsat(result);

    maxsat_problem_send(msg_buf, requester);
}

/*sync maxsat step*/
void slave_sync_maxsat(struct result *result) {
    uint64_t msg_buf[MAXSAT_SYNC_LEN];
    MPI_Bcast(msg_buf, MAXSAT_SYNC_LEN, MPI_UINT64_T, mpi_master(), MPI_COMM_WORLD);

    result_set_maxsat(result, msg_buf[0]);
    result_set_na(result, msg_buf[1]);
    MPI_Bcast(result->sample.vars, 2, MPI_UINT64_T, msg_buf[2], MPI_COMM_WORLD);
}

void master_sync_maxsat(struct result *result, uint64_t best_maxsat_mpi_rank) {
    uint64_t msg_buf[MAXSAT_SYNC_LEN];

    msg_buf[0] = result_maxsat(result);
    msg_buf[1] = result_na(result);
    msg_buf[2] = best_maxsat_mpi_rank;

    MPI_Bcast(msg_buf, MAXSAT_SYNC_LEN, MPI_UINT64_T, mpi_master(), MPI_COMM_WORLD);
    MPI_Bcast((result->sample).vars, 2, MPI_UINT64_T, msg_buf[2], MPI_COMM_WORLD);
}


/* Calculate the maxsat result for the crepr. 
 * schedule(dynamic) guarantees that all threads keep running for the
 * same approximate ammount of time, because they keep getting 
 * new problems if they finish early(vs static schedule).
 *nowait is used to measure the time difference between first and last
 * thread finishing. Without nowait there'd be a barrier before 
 * measuring the time*/ 
void do_maxsat(const struct crepr *crepr, struct result *result, uint8_t num_initialized_vars, uint64_t prob) {
    struct result thread_result = new_stack_result();

    #pragma omp critical
    result_set_maxsat(&thread_result, result_maxsat(result));

    struct clauses clauses;
    ALLOC_LOCAL_CLAUSES(clauses, crepr);

    /*the least num_initialized_vars least significant bits of prob
     * have the assignments for the num_initialized_vars least sig bits*/
    struct assignment assignment = new_stack_assignment_from_num((uint64_t [2]){0, prob<<1});

    INIT_LOCAL_CLAUSES(clauses, crepr, assignment, num_initialized_vars);

    /*Solve the partial problem starting with num_initialized_vars
     * assigned*/
    partial_maxsat(&clauses, &thread_result);

    LOG_DEBUG("mpi:%zu thread:%d assignment:%"PRIu64"/%zu maxsat:%"PRIu16" na:%"PRIu64,
            mpi_rank(),
            omp_get_thread_num(),
            prob,
            (((size_t)1 << num_initialized_vars)  - 1),
            result_maxsat(&thread_result),
            result_na(&thread_result));

    #pragma omp critical 
    sync_result(result, &thread_result);
}


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

/* Chooses how many num_initialized_vars and problems there should be
 *  in function of mpi_size()
 *
 * num_problems is the value of the number of problems,
 * num_initialized variables is the number of bits in num_problems
 * that's why we use we add values to num_initiliazed variables, because
 * when we use << to assign num_problems, all the + are turned in * */
void maxsat_prob_division(const struct crepr *crepr,
                          uint64_t *num_problems,
                          uint64_t *num_initialized_vars) {

    /*We would like that each process have 64(log2(64)=6) problems.*/
    const uint8_t num_vars_per_thread = 6; 
    /*We want that each thread has at least 16 problems*/
    const uint8_t min_num_vars_per_thread = 4; 
    const uint8_t num_vars = crepr_num_vars(crepr);

    /* num_bit_len() - 2 because we don't want num_threads to contribute, when
     *  there is only 1 slave (the other 1 is the master).*/
    *num_initialized_vars = num_vars_per_thread + num_bit_len(mpi_size()) - 2;

    #pragma omp master
    LOG_DEBUG("maxsat: %d threads, num_initialized_vars %" PRIu64 " of %"PRIu8 ,
            omp_get_num_threads(),
            *num_initialized_vars,
            num_vars);

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
        LOG_DEBUG("Reducing num_initialized_vars to %" PRIu64, *num_initialized_vars);
    }

    *num_problems= 1 << (*num_initialized_vars);
    return;
}


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
