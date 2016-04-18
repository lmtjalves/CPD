#ifndef CLAUSES_H__
#define CLAUSES_H__

#include "result.h"
#include "crepr.h"

/* Returns the maxsat of the given group of clauses.
*/
struct result maxsat(const struct crepr *crepr);

#endif /*CLAUSES_H__*/
