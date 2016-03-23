#include "result.h"

struct result new_stack_result(void){

  struct result res = { .maxsat_value = 0,
                        .na = 0,
                        res.sample = new_stack_assignment()
                      };
  return res;
}

uint8_t result_get_maxsat_value (struct result *result){
  //#pragma omp critical
  return result->maxsat_value;
}

void result_set_maxsat_value (struct result *result, uint8_t new_maxsat_value){
  //#pragma omp critical
  result->maxsat_value = new_maxsat_value;
}

uint64_t result_get_na (struct result *result){
  //#pragma omp critical
  return result->na;
}

void result_set_na (struct result *result, uint64_t number_assignments){
  //#pragma omp critical
  result->na = number_assignments;
}

struct assignment result_get_assignment_sample(struct result *result){
  //#pragma omp critical
  return result->sample;
}

void result_set_assignment_sample(struct result *result, struct assignment new_sample){
  //#pragma omp critical{}
  result->sample.vars[0] = new_sample.vars[0];
  result->sample.vars[1] = new_sample.vars[1];
}

bool result_update(struct result *result, uint8_t new_maxsat_value, struct assignment new_sample){
  if (new_maxsat_value == result->maxsat_value){
    //#pragma omp atomic FIXME
    (result->na)++;
  } else if (new_maxsat_value > result->maxsat_value){
    //#pragma omp critical FIXME
    {
      result->maxsat_value = new_maxsat_value;
      result->sample.vars[0] = new_sample.vars[0];
      result->sample.vars[1] = new_sample.vars[1];
      result->na = 1;
    }
  } else {
    return false;
  }
  return true;
}
