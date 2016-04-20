#include "mpi_utils.h"

bool is_master() {
  return !get_rank();
}

bool is_slave() {
  return get_rank();
}

int get_rank() {
  int mpi_rank;
  int mpi_ret = MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);

  ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed to get mpi_rank.");
  LOG_DEBUG("mpi_rank:%d", mpi_rank);

  return mpi_rank;
}

int get_size() {
  int mpi_size;
  int mpi_ret = MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);

  ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Failed to get mpi_size.");
  LOG_DEBUG("mpi_size:%d", mpi_size);

  return mpi_size;
}