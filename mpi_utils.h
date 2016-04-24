#ifndef MPI_UTILS_H
#define MPI_UTILS_H

#include <stdbool.h>
#include <stddef.h>

// Utilitary functions to make the code more readable.
bool is_mpi_master();
bool is_mpi_slave();

size_t mpi_rank();
size_t mpi_size();
size_t mpi_master();

#endif
