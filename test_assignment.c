#include "unit_test.h"
#include "assignment.h"

static bool assignment_is_zero(struct assignment assignment) {
    return assignment.vars[0] == 0 && assignment.vars[1] == 0;
}

UT_TEST(assignment_zero_initialized) {
    struct assignment assignment = new_stack_assignment();
    UT_ASSERT_TRUE(assignment_is_zero(assignment));
    return 0;
}

UT_TEST(assignment_set_var0) {
    struct assignment assignment = new_stack_assignment();

    assignment_set_var(&assignment, 0, false);
    //UT_PRINTF("assignment.vars = {%" PRIx64 " %" PRIx64 "}", assignment.vars[0], assignment.vars[1]);
    UT_ASSERT_TRUE(assignment_is_zero(assignment));

    assignment_set_var(&assignment, 0, true);
    //UT_PRINTF("assignment.vars = {%" PRIx64 " %" PRIx64 "}", assignment.vars[0], assignment.vars[1]);
    UT_ASSERT_FALSE(assignment_is_zero(assignment));

    return 0;
}

UT_TEST(assignment_set_var0_get_var0) {
    struct assignment assignment = new_stack_assignment();

    assignment_set_var(&assignment, 0, false);
    UT_ASSERT_FALSE(assignment_get_var(assignment, 0));

    assignment_set_var(&assignment, 0, true);
    UT_ASSERT_TRUE(assignment_get_var(assignment, 0));
    
    return 0;
}

UT_TEST(assignment_set_var01_get_var01) {
    struct assignment assignment = new_stack_assignment();

    assignment_set_var(&assignment, 0, false);
    UT_ASSERT_FALSE(assignment_get_var(assignment, 0));
    assignment_set_var(&assignment, 1, false);
    UT_ASSERT_FALSE(assignment_get_var(assignment, 1));

    assignment_set_var(&assignment, 0, true);
    UT_ASSERT_TRUE(assignment_get_var(assignment, 0));
    assignment_set_var(&assignment, 1, true);
    UT_ASSERT_TRUE(assignment_get_var(assignment, 1));

    assignment_set_var(&assignment, 0, false);
    UT_ASSERT_FALSE(assignment_get_var(assignment, 0));
    assignment_set_var(&assignment, 1, false);
    UT_ASSERT_FALSE(assignment_get_var(assignment, 1));

    return 0;
}

UT_TEST(assignment_set_var_get_var_first64) {
    struct assignment assignment = new_stack_assignment();

    size_t var;
    for(var = 0; var < 64; ++var) {
        assignment_set_var(&assignment, var, false);
        UT_ASSERT_FALSE(assignment_get_var(assignment, var));
    }

    for(var = 0; var < 64; ++var) {
        assignment_set_var(&assignment, var, true);
        UT_ASSERT_TRUE(assignment_get_var(assignment, var));
    }

    for(var = 0; var < 64; ++var) {
        assignment_set_var(&assignment, var, false);
        UT_ASSERT_FALSE(assignment_get_var(assignment, var));
    }

    return 0;
}

UT_TEST(assignment_set_var_get_var_first64_reverse_order) {
    struct assignment assignment = new_stack_assignment();

    size_t var;
    for(var = 63; var != 0; --var) {
        assignment_set_var(&assignment, var, false);
        UT_ASSERT_FALSE(assignment_get_var(assignment, var));
    }
    assignment_set_var(&assignment, 0, false);
    UT_ASSERT_FALSE(assignment_get_var(assignment, 0));


    for(var = 63; var != 0; --var) {
        assignment_set_var(&assignment, var, true);
        UT_ASSERT_TRUE(assignment_get_var(assignment, var));
    }
    assignment_set_var(&assignment, 0, true);
    UT_ASSERT_TRUE(assignment_get_var(assignment, 0));

    for(var = 63; var != 0; --var) {
        assignment_set_var(&assignment, var, false);
        UT_ASSERT_FALSE(assignment_get_var(assignment, var));
    }
    assignment_set_var(&assignment, 0, false);
    UT_ASSERT_FALSE(assignment_get_var(assignment, 0));

    return 0;
}

UT_TEST(assignment_set_var_get_var_all128) {
    struct assignment assignment = new_stack_assignment();

    size_t var;
    for(var = 0; var < 128; ++var) {
        assignment_set_var(&assignment, var, false);
        UT_ASSERT_FALSE(assignment_get_var(assignment, var));
    }

    for(var = 0; var < 128; ++var) {
        assignment_set_var(&assignment, var, true);
        UT_ASSERT_TRUE(assignment_get_var(assignment, var));
    }

    for(var = 0; var < 128; ++var) {
        assignment_set_var(&assignment, var, false);
        UT_ASSERT_FALSE(assignment_get_var(assignment, var));
    }

    return 0;
}

UT_TEST(assignment_from_num_0_0) {
    uint64_t num[2] = {0, 0};
    struct assignment assignment = new_stack_assignment_from_num(num);

    size_t var;
    for(var = 0; var < 128; ++var) {
        UT_ASSERT_FALSE(assignment_get_var(assignment, var));
    }

    return 0;
}

UT_TEST(assignment_from_num_0_MAX) {
    uint64_t num[2] = {0, UINT64_MAX};
    struct assignment assignment = new_stack_assignment_from_num(num);

    size_t var;
    for(var = 0; var < 64; ++var) {
        UT_ASSERT_TRUE(assignment_get_var(assignment, var));
    }
    for(var = 64; var < 128; ++var) {
        UT_ASSERT_FALSE(assignment_get_var(assignment, var));
    }

    return 0;
}

UT_TEST(assignment_from_num_MAX_0) {
    uint64_t num[2] = {UINT64_MAX, 0};
    struct assignment assignment = new_stack_assignment_from_num(num);

    size_t var;
    for(var = 0; var < 64; ++var) {
        UT_ASSERT_FALSE(assignment_get_var(assignment, var));
    }
    for(var = 64; var < 128; ++var) {
        UT_ASSERT_TRUE(assignment_get_var(assignment, var));
    }

    return 0;
}

UT_TEST(assignment_from_num_MAX_MAX) {
    uint64_t num[2] = {UINT64_MAX, UINT64_MAX};
    struct assignment assignment = new_stack_assignment_from_num(num);

    size_t var;
    for(var = 0; var < 128; ++var) {
        UT_ASSERT_TRUE(assignment_get_var(assignment, var));
    }

    return 0;
}

UT_TEST(assignment_from_num_even_bits_set) {
    /* 5 - 0101 0101 0101 0101 0101 read from right to left*/
    uint64_t num[2] = {0x5555555555555555, 0x5555555555555555};
    struct assignment assignment = new_stack_assignment_from_num(num);

    size_t var;
    for(var = 0; var < 128; var += 2) {
        UT_ASSERT_TRUE(assignment_get_var(assignment, var));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 1));
    }

    return 0;
}

UT_TEST(assignment_from_num_odd_bits_set) {
    /* A - 1010 read from right to left*/
    uint64_t num[2] = {0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA};
    struct assignment assignment = new_stack_assignment_from_num(num);

    size_t var;
    for(var = 0; var < 128; var += 2) {
        UT_ASSERT_FALSE(assignment_get_var(assignment, var));
        UT_ASSERT_TRUE(assignment_get_var(assignment, var + 1));
    }

    return 0;
}

UT_TEST(assignment_from_num_4bit_patterns) {
    struct assignment assignment;
    size_t var;
   
    /* 1 - 0001 */
    uint64_t num1[2] = {0x1111111111111111, 0x1111111111111111};
    assignment = new_stack_assignment_from_num(num1);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 0));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 2));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 3));
    }

    /* 2 - 0010 */
    uint64_t num2[2] = {0x2222222222222222, 0x2222222222222222};
    assignment = new_stack_assignment_from_num(num2);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 0));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 1));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 2));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 3));
    }

    /* 3 - 0011 */
    uint64_t num3[2] = {0x3333333333333333, 0x3333333333333333};
    assignment = new_stack_assignment_from_num(num3);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 0));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 1));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 2));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 3));
    }

    /* 4 - 0100 */
    uint64_t num4[2] = {0x4444444444444444, 0x4444444444444444};
    assignment = new_stack_assignment_from_num(num4);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 0));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 2));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 3));
    }

    /* 5 - 0101 */
    uint64_t num5[2] = {0x5555555555555555, 0x5555555555555555};
    assignment = new_stack_assignment_from_num(num5);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 0));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 2));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 3));
    }

    /* 6 - 0110 */
    uint64_t num6[2] = {0x6666666666666666, 0x6666666666666666};
    assignment = new_stack_assignment_from_num(num6);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_FALSE(assignment_get_var(assignment,  var + 0));
        UT_ASSERT_TRUE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 2));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 3));
    }

    /* 7 - 0111 */
    uint64_t num7[2] = {0x7777777777777777, 0x7777777777777777};
    assignment = new_stack_assignment_from_num(num7);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 0));
        UT_ASSERT_TRUE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 2));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 3));
    }

    /* 8 - 1000 */
    uint64_t num8[2] = {0x8888888888888888, 0x8888888888888888};
    assignment = new_stack_assignment_from_num(num8);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 0));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 2));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 3));
    }

    /* 9 - 1001 */
    uint64_t num9[2] = {0x9999999999999999, 0x9999999999999999};
    assignment = new_stack_assignment_from_num(num9);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 0));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 2));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 3));
    }

    /* A - 1010 */
    uint64_t numA[2] = {0xAAAAAAAAAAAAAAAA, 0xAAAAAAAAAAAAAAAA};
    assignment = new_stack_assignment_from_num(numA);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 0));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 1));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 2));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 3));
    }

    /* B - 1011 */
    uint64_t numB[2] = {0xBBBBBBBBBBBBBBBB, 0xBBBBBBBBBBBBBBBB};
    assignment = new_stack_assignment_from_num(numB);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 0));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 1));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 2));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 3));
    }

    /* C - 1100 */
    uint64_t numC[2] = {0xCCCCCCCCCCCCCCCC, 0xCCCCCCCCCCCCCCCC};
    assignment = new_stack_assignment_from_num(numC);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 0));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 2));
        UT_ASSERT_TRUE(assignment_get_var(assignment, var + 3));
    }

    /* D - 1101 */
    uint64_t numD[2] = {0xDDDDDDDDDDDDDDDD, 0xDDDDDDDDDDDDDDDD};
    assignment = new_stack_assignment_from_num(numD);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 0));
        UT_ASSERT_FALSE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 2));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 3));
    }

    /* E - 1110 */
    uint64_t numE[2] = {0xEEEEEEEEEEEEEEEE, 0xEEEEEEEEEEEEEEEE};
    assignment = new_stack_assignment_from_num(numE);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_FALSE(assignment_get_var(assignment,  var + 0));
        UT_ASSERT_TRUE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_TRUE(assignment_get_var(assignment,  var + 2));
        UT_ASSERT_TRUE(assignment_get_var(assignment, var + 3));
    }

    /* F - 1111 */
    uint64_t numF[2] = {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
    assignment = new_stack_assignment_from_num(numF);
    for(var = 0; var < 128; var += 4) {
        UT_ASSERT_TRUE(assignment_get_var(assignment, var + 0));
        UT_ASSERT_TRUE(assignment_get_var(assignment, var + 1));
        UT_ASSERT_TRUE(assignment_get_var(assignment, var + 2));
        UT_ASSERT_TRUE(assignment_get_var(assignment, var + 3));
    }

    return 0;
}




UT_ENDTEST
