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

int main(int argc, char * argv[]){


    bool parse_only = false;
    bool debug = false;
    char * filename = NULL;
    ASSERT_MSG(argc <= 4 && argc >= 2, "Invalid number of arguments!\n prog_name [--parse-only] [--debug] filename");
    for (int i = 1; i < argc; ++i) {
        if ((strcmp(argv[i], "--parse-only") == 0) && !parse_only) {
            parse_only = true;
        } else if ( (strcmp(argv[i], "--debug") == 0) && !debug) {
            debug = true;
        } else if (filename == NULL) {
            filename = argv[i];
        } else {
            ASSERT_ERROR("Failed to parse arguments. You could have duplicate flags, miss a filename, or mispelled the flags.");
        }
    }
    ASSERT_MSG(filename != NULL, "No filename given.");

    if(debug) {
        DEBUG_SET_LEVEL(DEBUG_LEVEL_DEBUG);
    }

    double start_time = omp_get_wtime();
    struct new_clauses_repr_from_file clauses_repr_from_file = new_clauses_repr_from_file(filename);
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
