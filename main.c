#include "assert.h"
#include "assignment.h"
#include "clauses_repr.h"
#include "clauses.h"
#include "project_specific.h"
#include "result.h"
#include "debug.h"
#include <stdlib.h>

void print_result(struct clauses_repr *clauses_repr, struct result result) { 
    printf("%" PRIu16 " %" PRIu64 "\n", result.maxsat_value, result.na);

    uint8_t num_vars = clauses_repr_num_vars(clauses_repr);

    for(int i = 1; i <= num_vars; i++) { 
        if(assignment_get_var(result.sample, i)) {
            printf("%d ", i);
        } else {
            printf("-%d ", i);
        }
    }
}

int main(int argc, const char * argv[]){

    /*Used to free on_error. We must do it like this so we know what to free while doing on_error*/
    struct new_clauses_repr_from_file *clauses_repr_from_filep = NULL;

    //number of arguments given is 2: program name and input file path.
    ASSERT_MSG(argc == 2, "Invalid number of arguments! We only accept a filename");

    double start_time = omp_get_wtime();
    struct new_clauses_repr_from_file clauses_repr_from_file = new_clauses_repr_from_file(argv[1]);
    LOG_DEBUG("parse time: %fs", omp_get_wtime() - start_time);
    clauses_repr_from_filep = &clauses_repr_from_file;
    
    ASSERT_MSG(clauses_repr_from_file.success, "Couldn't parse given filename");

    //clauses_repr_from_file created successfully
    struct clauses_repr * clauses_repr = clauses_repr_from_file.clauses_repr;
		
    start_time = omp_get_wtime();
    struct result result = maxsat(clauses_repr);
    LOG_DEBUG("maxsat time: %fs", omp_get_wtime() - start_time);
		
    print_result(clauses_repr, result);

    free_clauses_repr(clauses_repr_from_filep->clauses_repr);

    return 0;

on_error:
    if(clauses_repr_from_filep) {
        free_clauses_repr(clauses_repr_from_filep->clauses_repr);
    }

    return 1;

}
