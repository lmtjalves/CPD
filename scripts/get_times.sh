#!/bin/bash

# $1 is number of threads
# $2 is number of repetitions

set -e
set -u
set -o pipefail

function echo_error() {
    echo $@ 1>&2
}

#different from echo_error :p
function log() {
    echo $@ 1>&2
}

function arg_error() {
    echo_error "Error: Failed to parse arguments!"
    echo_error "get_times num_threads num_repetitions"
    exit 1
}

if [[ -z ${1+set} ]]; then
    arg_error
else
    num_threads="$1"
fi

if [[ -z ${2+set} ]]; then
    arg_error
else
    num_reps="$2"
fi

base="$(dirname "$0")"
prog="$base/../build/maxsat-omp"
#TEST_FILES=( "$base/../test/ex3.in" "$base/../test/ex4.in" "$base/../test/ex5.in")
TEST_FILES=( "$base/../test/ex1.in")

#csv head
echo -n "file,num_threads,avg,std"
for rep in $(seq 1 $num_reps); do
    echo -n ",data${rep}"
done

for test_file in ${TEST_FILES[@]}; do
    for thread in $(seq 1 $num_threads); do
        
        log "doing $test_file with $thread threads"
        declare -a times
        times[0]=0
        for rep in $(seq 1 $num_reps); do
            times[$rep]=0
        done

        for rep in $(seq 1 $num_reps); do
            times[$rep]="$(OMP_NUM_THREADS="$thread" "$prog" "$test_file" 2>&1 | egrep "maxsat time" | egrep -o "[[:digit:]]+\.[[:digit:]]+")"
        done

        #print 
        echo -n "$test_file,$thread"

        python_list="["
        for rep in $(seq 1 $(($num_reps - 1))); do
            python_list="${python_list}${times[$rep]},"
        done 
        python_list="${python_list}${times[$num_reps]}]"
        avg_std="$(python3 -c "import statistics,sys; sys.stdout.write(',{},{}'.format(statistics.mean(${python_list}), statistics.stdev(${python_list})))")"
        echo -n "$avg_std"

        for rep in $(seq 1 $num_reps); do
            echo -n ",${times[$rep]}"
        done

        echo "" #newline

        log "finished $test_file with $thread threads"
    done
done


