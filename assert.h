#ifndef ASSERT_H__
#define ASSERT_H__

#include "debug.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


#define ASSERT_MSG_VA(EXPR, MSG, ...) \
    do {\
        if (!(EXPR)) {\
            LOG_ERROR("Evaluation of '" #EXPR "' failed. ||| "  MSG, __VA_ARGS__);\
            goto on_error; /*Error handling*/\
        } \
    } while (0)

#define ASSERT_MSG(EXPR, MSG) ASSERT_MSG_VA(EXPR, MSG "%s", "")

#define ASSERT(EXPR) ASSERT_MSG(EXPR, "")

#define ASSERT_NON_NULL(EXPR) ASSERT_MSG(EXPR, "A null pointer was passed as argument.")

#define ASSERT_EXIT() \
    do { \
        LOG_ERROR("Reached point of no return. Exiting.%s", ""); \
        exit(1); \
    } while(0)

#define ASSERT_ERROR(MSG) \
    do { \
        ASSERT_MSG(false, MSG); \
    } while(0)


#endif /*ASSERT_H__*/
