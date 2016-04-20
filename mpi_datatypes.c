#include "mpi_datatypes.h"
#include "assert.h"
#include "assignment.h"
#include "result.h"

static MPI_Datatype assignment_datatype = NULL;
static MPI_Datatype result_datatype = NULL;

/*
 * Returns a mpi datatype for the this structure. Since the size is always the same, there's no
 * need to create a datatype everytime.
 */
MPI_Datatype mpi_datatypes_get_assignment_datatype() {
    // Since all the structures will always have the same size, there's no need to
    // create a datatype everytime we need it (use always the same)
    if(assignment_datatype == NULL) {
        int count = 1;
        int blocklengths[] = { 2 };
        MPI_Aint displacements[] = { offset(struct assignment, vars) };
        MPI_Datatype types[] = { MPI_UINT64_T };

        int mpi_ret;
        mpi_ret = MPI_Type_create_struct(count, blocklengths, displacements, types, &assignment_datatype);
        ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Fail creating a datatype for struct assignment.");

        mpi_ret = MPI_Type_commit(&assignment_datatype);
        ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Fail commiting the datatype for struct assignment.");
    }

    return assignment_datatype;

on_error:
    mpi_datatypes_free();
    ASSERT_EXIT();
}

/*
 * Returns a mpi datatype for the this structure. Since the size is always the same, there's no
 * need to create a datatype everytime.
 */
MPI_Datatype mpi_datatypes_get_result_datatype() {
    // Since all the structures will always have the same size, there's no need to
    // create a datatype everytime we need it (use always the same)
    if(result_datatype == NULL) {
        int count = 3;
        int blocklengths[] = { 1, 1, 1 };
        MPI_Aint displacements[] = { offset(struct result, maxsat_value),
                                     offset(struct result, na),
                                     offset(struct result, sample)};
        MPI_Datatype types[] = { MPI_UINT16_T, MPI_UINT64_T, mpi_datatypes_get_assignment_datatype };

        int mpi_ret;
        mpi_ret = MPI_Type_create_struct(count, blocklengths, displacements, types, &result_datatype);
        ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Fail creating a datatype for struct result.");

        mpi_ret = MPI_Type_commit(&result_datatype);
        ASSERT_MSG(mpi_ret == MPI_SUCCESS, "Fail commiting the datatype for struct result.");
    }

    return result_datatype;

on_error:
    mpi_datatypes_free();
    ASSERT_EXIT();
}

/*
 * Free all the created datatypes. Call this when you no longer need the created datatypes.
 */
void mpi_datatypes_free() {
    if(assignment_datatype != NULL) MPI_Type_free(&assignment_datatype);
    if(result_datatype != NULL)     MPI_Type_free(&result_datatype);
}