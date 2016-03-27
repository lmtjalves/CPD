#include "assert.h"
#include "assignment.h"
#include "clauses_repr.h"
#include "clauses.h"
#include "project_specific.h"
#include "result.h"
#include <stdlib.h>

int main(int argc, const char * argv[]){

    if(argc != 2) {
        printf("Invalid number of arguments!");
        exit(EXIT_FAILURE);
    }

    //number of arguments given is 2: program name and input file path.
    struct new_clauses_repr_from_file clauses_repr_from_file = new_clauses_repr_from_file(argv[1]);
    
    if(!clauses_repr_from_file.success){
        exit(EXIT_FAILURE);
    }

    //clauses_repr_from_file created successfully
    struct clauses_repr * clauses_repr = clauses_repr_from_file.clauses_repr;

    struct result result = new_stack_result();

    result = maxsat(clauses_repr);

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
    
return 0;

}
