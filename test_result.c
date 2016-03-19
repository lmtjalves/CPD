#include "unit_test.h"
#include "result.h"

static bool result_is_zero(struct result result) {
    return result.maxsat_value == 0 && result.na == 0 &&
           result.sample.vars[0] == 0 && result.sample.vars[1] == 0;
}

UT_TEST(result_zero_initialized) {
    struct result result = new_stack_result();
    UT_ASSERT_TRUE(result_is_zero(result));
    return 0;
}

UT_TEST(result_set_maxsat_value_) {
    struct result result = new_stack_result();

    result_set_maxsat_value(&result, 0);
    UT_ASSERT_TRUE(result_is_zero(result));

    result_set_maxsat_value(&result, 1);
    UT_ASSERT_TRUE(result.maxsat_value == 1);

    return 0;
}


UT_TEST(result_set_maxsat_value_get_maxsat_value) {
    struct result result = new_stack_result();

    result_set_maxsat_value(&result, 0);
    UT_ASSERT_FALSE(result_get_maxsat_value(result));

    result_set_maxsat_value(&result, 10);
    UT_ASSERT_TRUE(result_get_maxsat_value(result) == 10);

    return 0;
}

UT_TEST(result_set_na_) {
    struct result result = new_stack_result();

    result_set_na(&result, 0);
    UT_ASSERT_TRUE(result_is_zero(result));

    result_set_na(&result, 15);
    UT_ASSERT_TRUE(result.na == 15);

    return 0;
}


UT_TEST(result_set_na_get_na) {
    struct result result = new_stack_result();

    result_set_na(&result, 0);
    UT_ASSERT_FALSE(result_get_na(result));

    result_set_na(&result, 10);
    UT_ASSERT_TRUE(result_get_na(result) == 10);

    return 0;
}

UT_TEST(result_set_assignment_sample_) {
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

    result_set_assignment_sample(&result, assignment);
    UT_ASSERT_TRUE(result.sample.vars[0] == assignment.vars[0] && result.sample.vars[1] == assignment.vars[1]);

    return 0;
}


UT_TEST(result_set_assignment_sample_get_assignment_sample) {
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

    result_set_assignment_sample(&result, assignment);
    UT_ASSERT_TRUE(result_get_assignment_sample(result).vars[0] == assignment.vars[0] && \
                   result_get_assignment_sample(result).vars[1] == assignment.vars[1]);

    return 0;
}

UT_ENDTEST
