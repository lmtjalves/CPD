#include "mpi_utils.h"
#include "assert.h"

#include <mpi.h>

bool is_mpi_master() {
  return mpi_rank() == 0;
}

bool is_mpi_slave() {
  return mpi_rank() != 0;
}

size_t mpi_rank() {
    int mpi_ret, mpi_rank;

    mpi_ret = MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS && mpi_rank >= 0, "Failed to get mpi_rank.");

    return mpi_rank;

on_error:
    ASSERT_EXIT();
}

size_t mpi_size() {
    int mpi_ret, mpi_size;
    mpi_ret = MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);
    ASSERT_MSG(mpi_ret == MPI_SUCCESS && mpi_size > 0, "Failed to get mpi_size.");

    return mpi_size;

on_error:
    ASSERT_EXIT();
}

size_t mpi_master() {
    return 0;
}
