#include "unit_test.h"
#include "crepr.h"
#include "clauses.h"

UT_TEST(create_clauses) {
  struct new_crepr crepr_aux = new_crepr("test/ex1.in");

  UT_ASSERT_TRUE(crepr_aux.success == true);
  struct crepr* crepr= crepr_aux.crepr;

  struct result result = maxsat(crepr);

  printf("%d %" PRIu64 "\n", result_maxsat(&result), result_na(&result));

  for(int i = 1; i <= crepr_num_vars(crepr); i++) {
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
