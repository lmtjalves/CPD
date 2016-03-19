cmake_minimum_required(VERSION 3.3)
project(cpd)

set(CC "clang")

set(WARNING_FLAGS "-Wall -Wextra  -Wshadow -Wstrict-aliasing -Wundef -Wpointer-arith -Wcast-align -Wwrite-strings \
                   -Winit-self -Wuninitialized")
set(COMMON_FLAGS "${WARNING_FLAGS} -std=c11 -Werror -pedantic")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE} ${COMMON_FLAGS} -DNDEBUG")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${COMMON_FLAGS} -O0 -g -fno-inline -fsanitize=address,undefined")

add_executable(test_assignment test_assignment.c assignment.c)
add_executable(test_result assignment.c test_result.c result.c)
