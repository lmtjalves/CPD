cmake_minimum_required(VERSION 3.3)
project(cpd)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(WARNING_FLAGS "-Wall -Wextra  -Wshadow -Wstrict-aliasing -Wundef -Wpointer-arith -Wcast-align -Wwrite-strings \
                   -Winit-self -Wuninitialized -Wunknown-pragmas")
set (OMP_FLAGS "-fopenmp")
set(COMMON_FLAGS "${WARNING_FLAGS} ${OMP_FLAGS} -std=c11 -Werror -pedantic")


set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${COMMON_FLAGS}")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${COMMON_FLAGS} -DDEBUG_LOG_LEVEL=DEBUG_LEVEL_DEBUG -O0 -g -fno-inline -fsanitize=address,undefined")

add_executable(test_assignment test_assignment.c assignment.c)
add_executable(test_result assignment.c test_result.c result.c)
add_executable(test_clauses_repr test_clauses_repr.c clauses_repr.c parse_long.c)
add_executable(test_clauses test_clauses.c clauses.c clauses_repr.c parse_long.c assignment.c result.c)
add_executable(main main.c clauses.c clauses_repr.c parse_long.c assignment.c result.c)
