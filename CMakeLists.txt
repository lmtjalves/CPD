#cmake_minimum_required(VERSION 3.3)
project(cpd)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(WARNING_FLAGS "-Wall -Wextra  -Wshadow -Wstrict-aliasing -Wundef -Wpointer-arith -Wcast-align -Wwrite-strings -Winit-self -Wuninitialized -Wunknown-pragmas")
set (OMP_FLAGS "-fopenmp")
set(COMMON_FLAGS "${WARNING_FLAGS} ${OMP_FLAGS} -std=c11 -Werror -pedantic")


set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${COMMON_FLAGS} -g")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${COMMON_FLAGS} -g -fstack-protector-all")

add_executable(test_assignment test_assignment.c assignment.c debug.c)
add_executable(test_result assignment.c test_result.c result.c debug.c)
add_executable(test_crepr test_crepr.c crepr.c parse_long.c debug.c mpi_utils.c)
add_executable(test_clauses test_clauses.c clauses.c crepr.c parse_long.c assignment.c result.c debug.c mpi_utils.c)
add_executable(main main.c clauses.c crepr.c parse_long.c assignment.c result.c debug.c mpi_utils.c)
add_executable(maxsat-omp delivery/maxsat-omp.c)
add_executable(maxsat-serial delivery/maxsat-serial.c)
