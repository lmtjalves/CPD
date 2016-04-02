#include "assignment.h"
#include "assert.h"

#define GET_BIT(value, bit_num) (((value) >> (bit_num)) & 1)
#define UINT8_MASK(value) ((var) & 0x3F)
#define MAX_BIT 127

struct assignment new_stack_assignment(void) {
    struct assignment ret = { .vars = {0,0}};
    return ret;
}

/* Assumes big_num = num[0] num[1], so v0 = num[1][0], v1 = num[1][1], ... v63=num[1][63]*/
struct assignment new_stack_assignment_from_num(uint64_t num[2]) {
    struct assignment ret;

    size_t var = 0;
    int num_i; /*int :'(*/
    for(num_i = 1; num_i >= 0; --num_i) { 
        size_t bit_i;
        for(bit_i = 0; bit_i < 64; ++bit_i) {
            assignment_set_var(&ret, var, GET_BIT(num[num_i], bit_i));
            ++var;
        }
    }

    return ret;
}

bool assignment_get_var(struct assignment assignment, uint8_t var) {
    ASSERT(var <= MAX_BIT);
    //ASSERT(var <= assignment.cur_var);

    /*We want 0 if var < 64, and 1 if var >= 64, so we extract the 6th bit since 64 = 0100 0000 */
    size_t index = GET_BIT(var, 6);

    return GET_BIT(assignment.vars[index], UINT8_MASK(var)) == 1;

on_error:
    ASSERT_EXIT();
}

void assignment_set_var(struct assignment *assignment, uint8_t var, bool bool_value) {
    ASSERT_NON_NULL(assignment);
    ASSERT(var <= MAX_BIT);
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

#undef GET_BIT
#undef UINT8_MASK
#undef MAX_BIT
