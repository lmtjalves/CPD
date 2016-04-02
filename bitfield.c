#include "assert.h"
#include "bitfield.h"

#define GET_BIT(VALUE, BIT) (((VALUE) >> (BIT)) & 0x1)
#define LEAST3BITS(BIT) ((BIT) & 0x7)

struct bitfield new_stack_bitfield(size_t num_bits) {
    struct bitfield ret = {.num_bits = num_bits};

    size_t num_bytes = (num_bits + 7) / 8;
    ASSERT_MALLOC(uint8_t, ret.bits, num_bytes);
    memset(ret.bits, 0, num_bytes);

    return ret;

on_error:
    ASSERT_EXIT();
}

bool bitfield_get(struct bitfield bitfield, size_t bit) {
    ASSERT_NON_NULL(bitfield.bits);
    ASSERT(bit <= bitfield.num_bits);
    
    size_t index = bit / 8;
    return GET_BIT(bitfield.bits[index], LEAST3BITS(bit));

    on_error:
    ASSERT_EXIT();
}

void bitfield_set(struct bitfield bitfield, size_t bit, bool bool_value) {
    ASSERT_NON_NULL(bitfield.bits);
    ASSERT(bit <= bitfield.num_bits);
    
    uint64_t value = bool_value ? 1 : 0;
    /*We want 0 if var < 64, and 1 if var >= 64, so we extract the 6th bit since 64 = 0100 0000 */
    size_t index = bit / 8;
    bitfield.bits[index] = ( (~(((uint8_t) 1) << LEAST3BITS(bit))) & bitfield.bits[index]) | (value << LEAST3BITS(bit));

    return;

    on_error:
    ASSERT_EXIT();
}

void bitfield_free(struct bitfield bitfield) {
    ASSERT_FREE(bitfield.bits);

    return;

    on_error:
    ASSERT_EXIT();
}

#undef GET_BIT
#undef UINT8_MASK
