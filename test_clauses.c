#include "unit_test.h"
#include "clauses_repr.h"

UT_TEST(create_clauses) {
  struct new_clauses_repr_from_file clauses_repr_aux = new_clauses_repr_from_file("test/ex1.in");

  UT_ASSERT_TRUE(clauses_repr_aux.success == true);
  struct clauses_repr *clauses_repr = clauses_repr_aux.clauses_repr;


  return 0;
}

UT_ENDTEST
