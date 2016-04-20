#ifndef MPI_UTILS__
#define MPI_UTILS__

#include "assert.h"
#include "debug.h"

#include <mpi.h>

// Utilitary functions to make the code more readable.
bool is_master();
bool is_slave();

// Just some utilitary functions that wrap MPI functions with asserts.
int get_rank();
int get_size();

#endif