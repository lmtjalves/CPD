#ifndef CLAUSES_H__
#define CLAUSES_H__

#include "result.h"
#include "clauses_repr.h"

/* Returns the maxsat of the given group of clauses.
*/
struct result maxsat(const struct clauses_repr *clauses_repr);

#endif /*CLAUSES_H__*/
