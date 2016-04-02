#ifndef BITFIELD_H__
#define BITFIELD_H__

#include <stdbool.h>
#include <stdint.h>

struct bitfield {
    uint8_t *bits;
    size_t num_bits;
};

/* new_stack because it returns a struct by value, but it must be free'd because it allocs memory.
 * All bits start at 0*/
struct bitfield new_stack_bitfield(size_t num_bits);
bool bitfield_get(struct bitfield bitfield, size_t bit);
void bitfield_set(struct bitfield bitfield, size_t bit, bool value);
void bitfield_free(struct bitfield bitfield);

#endif /*BITFIELD_H__*/
