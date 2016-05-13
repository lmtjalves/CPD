CFLAGS=--std=c11 -fopenmp -Wall -Wextra  -Wshadow -Wstrict-aliasing -Wundef -Wpointer-arith -Wcast-align -Wwrite-strings -Winit-self -Wuninitialized -Wunknown-pragmas -Werror -pedantic
CC=cc
maxsat-mpi-omp: CC=mpicc
maxsat-mpi: CC=mpicc

all: maxsat-omp maxsat-serial maxsat-mpi maxsat-mpi-omp



clean:
	rm maxsat-omp maxsat-serial maxsat-mpi maxsat-mpi-omp
