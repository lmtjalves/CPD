
#ifndef ASSIGNMENT_H__
#define ASSIGNMENT_H__

#include <inttypes.h>
#include <stdbool.h>

/* We want 128 bits because there are at most 128 variables.
 * We save the state of a variable in a bit.*/
struct assignment {
    uint64_t vars[2];
};

struct assignment new_stack_assignment(void);
bool assignment_get_var(struct assignment assignment, uint8_t var);
void assignment_set_var(struct assignment *assignment, uint8_t var, bool value);

#endif /*ASSIGNMENT_H__*/
