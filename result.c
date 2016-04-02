#include "result.h"
#include "assert.h"

struct result new_stack_result(void){

  struct result res = { .maxsat_value = 0,
                        .na = 0,
                        res.sample = new_stack_assignment()
                      };
  return res;
}

uint16_t result_get_maxsat_value (struct result *result){
  ASSERT_NON_NULL(result);
	
	return result->maxsat_value;

  on_error:
  ASSERT_EXIT();
}

void result_set_maxsat_value (struct result *result, uint16_t new_maxsat_value){
  ASSERT_NON_NULL(result);

  result->maxsat_value = new_maxsat_value;

  return;

  on_error:
  ASSERT_EXIT();
}

uint64_t result_get_na (struct result *result){
  ASSERT_NON_NULL(result);

  return result->na;

  on_error:
  ASSERT_EXIT();
}

void result_set_na (struct result *result, uint64_t number_assignments){
  ASSERT_NON_NULL(result);

  result->na = number_assignments;

  return;

  on_error:
  ASSERT_EXIT();
}

struct assignment result_get_assignment_sample(struct result *result){
  ASSERT_NON_NULL(result);

  return result->sample;

  on_error:
  ASSERT_EXIT();
}

void result_set_assignment_sample(struct result *result, struct assignment new_sample){
  ASSERT_NON_NULL(result);

  result->sample = new_sample;

  return;

  on_error:
  ASSERT_EXIT();
}

void result_update(struct result *result, uint16_t new_maxsat_value, struct assignment new_sample){
  ASSERT_NON_NULL(result);
	
  if (new_maxsat_value == result->maxsat_value){
      (result->na)++;
  } else if (new_maxsat_value > result->maxsat_value){
      {
      	  result->maxsat_value = new_maxsat_value;
      	  result->sample = new_sample;
      	  result->na = 1;
      }
  }

  return;
  on_error:
  	ASSERT_EXIT();
}
