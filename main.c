#include "assert.h"
#include "assignment.h"
#include "clauses_repr.h"
#include "clauses.h"
#include "result.h"
#include "debug.h"

#include <omp.h>
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


    bool parse_only = false;
    if (argc == 3 && strcmp(argv[1], "--parse-only") == 0) {
        parse_only = true;
        argc--; argv++; /*could be cleaner...*/
    }

    //number of arguments given is 2: program name and input file path.
    ASSERT_MSG(argc == 2, "Invalid number of arguments! We only accept a filename or --parse-only");

    double start_time = omp_get_wtime();
    struct new_clauses_repr_from_file clauses_repr_from_file = new_clauses_repr_from_file(argv[1]);
    LOG_INFO("parse time: %fs", omp_get_wtime() - start_time);
    ASSERT_MSG(clauses_repr_from_file.success, "Couldn't parse given filename");

    if (parse_only) {
        free_clauses_repr(clauses_repr_from_file.clauses_repr);
        return 0;
    }

    //clauses_repr_from_file created successfully
    struct clauses_repr *clauses_repr = clauses_repr_from_file.clauses_repr;

    start_time = omp_get_wtime();
    struct result result = maxsat(clauses_repr);
    LOG_INFO("maxsat time: %fs", omp_get_wtime() - start_time);

    print_result(clauses_repr, result);

    free_clauses_repr(clauses_repr_from_file.clauses_repr);

    return 0;

on_error:
    return 1;
}
