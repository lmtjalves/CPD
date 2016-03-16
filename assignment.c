
#include "assignment.h"
#include "assert.h"
#include "project_specific.h"

#define GET_BIT(value, bit_num) (((value) >> (bit_num)) & 1)
#define UINT8_MASK(value) ((var) & 0x3F)


struct assignment new_stack_assignment(void) {
    struct assignment ret = { .vars = {0,0}};
    return ret;
}

bool assignment_get_var(struct assignment assignment, uint8_t var) {
    ASSERT(var <= MAX_VAR);
    //ASSERT(var <= assignment.cur_var);
 
    
    /*We want 0 if var < 64, and 1 if var >= 64, so we extract the 6th bit since 64 = 0100 0000 */
    size_t index = GET_BIT(var, 6);
   
    return GET_BIT(assignment.vars[index], UINT8_MASK(var)) == 1;

    on_error:
    ASSERT_EXIT();
}

void assignment_set_var(struct assignment *assignment, uint8_t var, bool bool_value) {
    ASSERT_NON_NULL(assignment);
    ASSERT(var <= MAX_VAR);
    //ASSERT(var == assignment->cur_var);
    
    uint64_t value = bool_value ? 1 : 0;
    /*We want 0 if var < 64, and 1 if var >= 64, so we extract the 6th bit since 64 = 0100 0000 */
    size_t index = GET_BIT(var, 6);
    assignment->vars[index] = ((~( ((uint64_t) 1) << UINT8_MASK(var))) & assignment->vars[index]) | (value << UINT8_MASK(var));
    //assignment->cur_var++;

    return;

    on_error:
    ASSERT_EXIT();
}
