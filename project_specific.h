#include "omp.h"

#define MAX_VAR 127
/* = MAX_VAR because we start at var 1*/
#define MAX_NUM_VARS MAX_VAR
#define MAX_NUM_CLAUSES 65536
#define MAX_NUM_VARS_CLAUSE 20
/* 4 because MAX_VAR is 127 and could be -127*/
#define MAX_VAR_STR_SIZE 4
#define NUM_INITIALIZED_VARS(num_vars) 8
