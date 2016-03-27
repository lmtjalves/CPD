#include "unit_test.h"
#include "clauses_repr.h"
#include "clauses.h"

UT_TEST(create_clauses) {
  struct new_clauses_repr_from_file clauses_repr_aux = new_clauses_repr_from_file("test/ex1.in");

  UT_ASSERT_TRUE(clauses_repr_aux.success == true);
  struct clauses_repr *clauses_repr = clauses_repr_aux.clauses_repr;

  struct result result = maxsat(clauses_repr);

  printf("%d %" PRIu64 "\n", result_get_maxsat_value(&result), result_get_na(&result));

  for(int i = 1; i <= clauses_repr_num_vars(clauses_repr); i++) {
    if(assignment_get_var(result.sample, i) == false) {
      printf("%d ", -i);
    } else {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}

UT_ENDTEST
