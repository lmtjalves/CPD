#include "unit_test.h"
#include "result.h"

static bool result_is_zero(struct result result) {
    struct assignment zero_assignment = new_stack_assignment();
    return result.maxsat_value == 0 && result.na == 0 &&
           ~( memcmp( &(result.sample), &zero_assignment, sizeof(struct assignment) ) );
}

UT_TEST(result_zero_initialized) {
    struct result result = new_stack_result();
    UT_ASSERT_TRUE(result_is_zero(result));
    return 0;
}

UT_TEST(result_set_maxsat) {
    struct result result = new_stack_result();

    result_set_maxsat(&result, 0);
    UT_ASSERT_TRUE(result_is_zero(result));

    result_set_maxsat(&result, 1);
    UT_ASSERT_TRUE(result.maxsat_value == 1);

    return 0;
}


UT_TEST(result_set_maxsat_result_maxsat) {
    struct result result = new_stack_result();

    result_set_maxsat(&result, 0);
    UT_ASSERT_FALSE(result_maxsat(&result));

    result_set_maxsat(&result, 10);
    UT_ASSERT_TRUE(result_maxsat(&result) == 10);

    return 0;
}

UT_TEST(result_set_na) {
    struct result result = new_stack_result();

    result_set_na(&result, 0);
    UT_ASSERT_TRUE(result_is_zero(result));

    result_set_na(&result, 15);
    UT_ASSERT_TRUE(result.na == 15);

    return 0;
}


UT_TEST(result_set_na_result_na) {
    struct result result = new_stack_result();

    result_set_na(&result, 0);
    UT_ASSERT_FALSE(result_na(&result));

    result_set_na(&result, 10);
    UT_ASSERT_TRUE(result_na(&result) == 10);

    return 0;
}

UT_TEST(result_set_assignment) {
    struct result result = new_stack_result();
    struct assignment assignment = new_stack_assignment();

    size_t var;
    for(var = 0; var < 128; ++var) {
        if( (var % 2) == 0) {
          assignment_set_var(&assignment, var, false);
        } else {
          assignment_set_var(&assignment, var, true);
        }
    }

    result_set_assignment(&result, assignment);
    UT_ASSERT_FALSE(memcmp( &(result.sample), &assignment, sizeof(struct assignment)));

    return 0;
}


UT_TEST(result_set_assignment_result_assignment) {
    struct result result = new_stack_result();
    struct assignment assignment = new_stack_assignment();

    size_t var;
    for(var = 0; var < 128; ++var) {
        if( (var % 2) == 0) {
          assignment_set_var(&assignment, var, false);
        } else {
          assignment_set_var(&assignment, var, true);
        }
    }

    result_set_assignment(&result, assignment);
    struct assignment sample = result_assignment(&result);

    UT_ASSERT_FALSE(memcmp(&sample, &assignment, sizeof(struct assignment)));

    return 0;
}

UT_TEST(result_update_case0) {
    struct result result = new_stack_result();
    struct assignment assignment = new_stack_assignment();
    uint8_t new_maxsat_value_0 = 0;

    result_update(&result, new_maxsat_value_0, assignment);

    UT_ASSERT_TRUE(result.na == 1 && result.maxsat_value == new_maxsat_value_0);
    UT_ASSERT_FALSE(memcmp(&(result.sample), &assignment, sizeof(struct assignment)));

    result_update(&result, new_maxsat_value_0, assignment);

    UT_ASSERT_TRUE(result.na == 2 && result.maxsat_value == new_maxsat_value_0);
    UT_ASSERT_FALSE(memcmp(&(result.sample), &assignment, sizeof(struct assignment)));

    return 0;
}

UT_TEST(result_update_case1) {
    struct result result = new_stack_result();
    struct assignment assignment = new_stack_assignment();
    uint8_t new_maxsat_value_1 = 30;

    result_update(&result, new_maxsat_value_1, assignment);

    UT_ASSERT_TRUE(result.na == 1 && result.maxsat_value == new_maxsat_value_1);
    UT_ASSERT_FALSE(memcmp(&(result.sample), &assignment, sizeof(struct assignment)));

    return 0;
}

UT_TEST(result_update_case2) {
    struct result result = new_stack_result();
    struct assignment assignment = new_stack_assignment();
    uint8_t new_maxsat_value_2 = 5;

    result_set_maxsat(&result, 6);
    result_update(&result, new_maxsat_value_2, assignment);

    UT_ASSERT_TRUE(result.na == 0 && result.maxsat_value == 6);
    UT_ASSERT_FALSE(memcmp(&(result.sample), &assignment, sizeof(struct assignment)));

    return 0;
}


UT_ENDTEST
