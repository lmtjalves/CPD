#ifndef MPI_DATATYPES__
#define MPI_DATATYPES__

#include <mpi.h>

MPI_Datatype mpi_datatypes_get_assignment_datatype();
MPI_Datatype mpi_datatypes_get_result_datatype();
void mpi_datatypes_free();

#endif