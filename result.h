#ifndef RESULT_H__
#define RESULT_H__

#include "assignment.h"

#include <stdio.h>
#include <string.h>

struct result {
	uint16_t maxsat_value; //FIXME depends on MAX_NUM_CLAUSES. see clauses_repr.c
	uint64_t na; //number of complete variable assignments that achieve MAXSAT
	struct assignment sample; //one sample of the assignments that achieve MAXSAT
};

struct result new_stack_result(void);

uint16_t result_get_maxsat_value (struct result *result);
void result_set_maxsat_value (struct result *result, uint16_t new_maxsat_value);

uint64_t result_get_na (struct result *result);
void result_set_na (struct result *result, uint64_t number_assignments);

struct assignment result_get_assignment_sample(struct result *result);
void result_set_assignment_sample(struct result *result, struct assignment new_sample);

void result_update(struct result *result, uint16_t new_maxsat_value, struct assignment new_sample);

#endif /*RESULT_H__*/
