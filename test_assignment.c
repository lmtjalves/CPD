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




UT_ENDTEST
