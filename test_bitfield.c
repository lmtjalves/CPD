#include "unit_test.h"
#include "bitfield.h"

UT_TEST(bitfield_8bits_set0_set1) {
    size_t num_bits = 8;
    struct bitfield bitfield = new_stack_bitfield(num_bits);

    UT_ASSERT_TRUE(bitfield.num_bits == num_bits);

    size_t bit;
    for(bit = 0; bit < num_bits; ++bit) {
        bitfield_set(bitfield, bit, 0);
        UT_ASSERT_FALSE(bitfield_get(bitfield, bit));
    }

    for(bit = 0; bit < num_bits; ++bit) {
        bitfield_set(bitfield, bit, 1);
        UT_ASSERT_TRUE(bitfield_get(bitfield, bit));
    }

    bitfield_free(bitfield);

    return 0;
}


UT_TEST(bitfield_set0_set1_set0_from_1bit_to_200bit) {
    size_t num_bits;
    for (num_bits = 1; num_bits <= 200; ++num_bits) {
        struct bitfield bitfield = new_stack_bitfield(num_bits);

        UT_ASSERT_TRUE(bitfield.num_bits == num_bits);

        size_t bit;
        for(bit = 0; bit < num_bits; ++bit) {
            bitfield_set(bitfield, bit, 0);
            UT_ASSERT_FALSE(bitfield_get(bitfield, bit));
        }
        for(bit = 0; bit < num_bits; ++bit) {
            bitfield_set(bitfield, bit, 1);
            UT_ASSERT_TRUE(bitfield_get(bitfield, bit));
        }
        for(bit = 0; bit < num_bits; ++bit) {
            bitfield_set(bitfield, bit, 0);
            UT_ASSERT_FALSE(bitfield_get(bitfield, bit));
        }

        bitfield_free(bitfield);
    }

    return 0;
}

UT_ENDTEST
