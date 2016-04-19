#include "assert.h"
#include "assignment.h"
#include "crepr.h"
#include "clauses.h"
#include "result.h"
#include "debug.h"

#include <omp.h>
#include <mpi.h>
#include <stdlib.h>

static struct parse_args parse_args(int argc, char **argv);
static void set_debug_level(struct parse_args args);
static void print_result(struct crepr *crepr, struct result result);


struct parse_args {
    bool debug, info, parse_only, success;
    const char *filename;
};

/* Public functions*/

int main(int argc, char **argv) {
    int mpi_ret;

    mpi_ret = MPI_Init(&argc, &argv);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed to init OpenMPI.");

    struct parse_args args = parse_args(argc, argv);
    ASSERT_MSG(args.success, "");

    set_debug_level(args);


    /*Parse file*/
    double start_time = omp_get_wtime();
    struct new_crepr new_crepr_result = new_crepr(args.filename);
    LOG_INFO("parse time: %fs", omp_get_wtime() - start_time);
    ASSERT_MSG(new_crepr_result.success, "Couldn't parse given filename");
    struct crepr *crepr = new_crepr_result.crepr;

    if (args.parse_only) {
        free_crepr(crepr);
        return 0;
    }


    /*Calculate maxsat*/
    start_time = omp_get_wtime();
    struct result result = maxsat(crepr);
    LOG_INFO("maxsat time: %fs", omp_get_wtime() - start_time);

    print_result(crepr, result);


    /*Finalization*/
    free_crepr(crepr);

    MPI_Finalize();

    return 0;

on_error:
    return 1;
}



/* Private functions*/

static struct parse_args parse_args(int argc, char **argv) {
    struct parse_args ret = {.parse_only = false,
                             .debug = false,
                             .info = false,
                             .filename = NULL};
    
    ASSERT_MSG(argc <= 4 && argc >= 2, "Invalid number of arguments!\n prog_name [--parse-only] [--debug|--info] filename");
    for (int i = 1; i < argc; ++i) {
        if ((strcmp(argv[i], "--parse-only") == 0) && !ret.parse_only) {
            ret.parse_only = true;
        } else if ( (strcmp(argv[i], "--debug") == 0) && !ret.debug && !ret.info) {
            ret.debug = true;
        } else if ( (strcmp(argv[i], "--info") == 0) && !ret.debug && !ret.info) {
            ret.info = true;
        } else if (ret.filename == NULL) {
            ret.filename = argv[i];
        } else {
            ASSERT_ERROR("Failed to parse arguments. You could have duplicate flags, miss a filename, or mispelled the flags.");
        }
    }
    ASSERT_MSG(ret.filename != NULL, "No filename given.");

    ret.success = true;
    return ret;

on_error:
    ret.success = false;
    return ret;
}

static void set_debug_level(struct parse_args args) {
    if(args.debug) {
        DEBUG_SET_LEVEL(DEBUG_LEVEL_DEBUG);
    } else if(args.info) {
        DEBUG_SET_LEVEL(DEBUG_LEVEL_INFO);
    }
}

static void print_result(struct crepr *crepr, struct result result) { 
    printf("%" PRIu16 " %" PRIu64 "\n", result.maxsat_value, result.na);

    uint8_t num_vars = crepr_num_vars(crepr);

    for(int i = 1; i <= num_vars; i++) { 
        if(assignment_get_var(result.sample, i)) {
            printf("%d ", i);
        } else {
            printf("-%d ", i);
        }
    }
}
