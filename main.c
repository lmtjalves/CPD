#include "assert.h"
#include "assignment.h"
#include "clauses_repr.h"
#include "clauses.h"
#include "project_specific.h"
#include "result.h"
#include <stdlib.h>

void print_result(struct clauses_repr *clauses_repr, struct result result) {
    //FIXME não tem espaço antes do newline
    printf("%" PRIu16 " %" PRIu64 "\n", result.maxsat_value, result.na);

    uint8_t num_vars = clauses_repr_num_vars(clauses_repr);

    //FIXME não sei se há problema de ter um espaço antes do ultimo newline
    for(int i = 1; i < num_vars; ++i) { 
        if(assignment_get_var(result.sample, i)) {
            printf("%d ", i);
        } else {
            printf("-%d ", i);
        }
    }
    
    printf("\n"); //FIXME não sei se tem /n no final da ultima linha ou não...
}

int main(int argc, const char * argv[]){

    /*Used to free on_error. We must do it like this so we know what to free while doing on_error*/
    struct new_clauses_repr_from_file *clauses_repr_from_filep = NULL;

    ASSERT_MSG(argc == 2, "Invalid number of arguments! We only accept a filename");

    //number of arguments given is 2: program name and input file path.
    struct new_clauses_repr_from_file clauses_repr_from_file = new_clauses_repr_from_file(argv[1]);
    clauses_repr_from_filep = &clauses_repr_from_file;
    
    ASSERT_MSG(clauses_repr_from_file.success, "Couldn't parse given filename");

    //clauses_repr_from_file created successfully
    struct clauses_repr * clauses_repr = clauses_repr_from_file.clauses_repr;

    struct result result = maxsat(clauses_repr);

    print_result(clauses_repr, result);

    free_clauses_repr(clauses_repr_from_filep->clauses_repr);

    return 0;

on_error:
    if(clauses_repr_from_filep) {
        free_clauses_repr(clauses_repr_from_filep->clauses_repr);
    }

    return 1;

}
