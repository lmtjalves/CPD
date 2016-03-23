
#ifndef ASSERT_H__
#define ASSERT_H__

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

/* Repeating macro from debug.h but without the variadic args because we're compiling with C89*/
#define ASSERT_CLEAN_ERRNO() (errno == 0 ? "None" : strerror(errno))
#define ASSERT_LOG_GENERIC(LOG_TYPE, MESSAGE) \
do {\
fprintf(stderr, LOG_TYPE " (%s:%d: errno: '%s' ) " MESSAGE "\n", __FILE__, __LINE__, ASSERT_CLEAN_ERRNO());\
} while(0)

#define ASSERT_LOG_GENERIC_VA(LOG_TYPE, MESSAGE, ...) \
do {\
fprintf(stderr, LOG_TYPE " (%s:%d: errno: '%s' ) " MESSAGE "\n", __FILE__, __LINE__, ASSERT_CLEAN_ERRNO(), __VA_ARGS__);\
} while(0)

#define ASSERT_LOG_BACKTRACE(MESSAGE) ASSERT_LOG_GENERIC("[BACKTRACE]", MESSAGE)
#define ASSERT_LOG_BACKTRACE_VA(MESSAGE, ...) ASSERT_LOG_GENERIC_VA("[BACKTRACE]", MESSAGE, __VA_ARGS__)
#define ASSERT_LOG_ASSERT(MESSAGE) ASSERT_LOG_GENERIC("[ASSERT]", MESSAGE)
#define ASSERT_LOG_ASSERT_VA(MESSAGE, ...) ASSERT_LOG_GENERIC_VA("[ASSERT]", MESSAGE, __VA_ARGS__)

#ifdef __linux__

#include <execinfo.h>
#define ASSERT_LOG_BACKTRACE_BACKTRACE() \
do { \
    /*using albb prefix to avoid shadowing other variables*/ \
    const int albb_BACKTRACE_LIMIT = 100; \
    void *albb_trace[albb_BACKTRACE_LIMIT]; \
    char **albb_messages = (char **)NULL; \
    int albb_i, albb_trace_size = 0; \
\
    albb_trace_size = backtrace(albb_trace, albb_BACKTRACE_LIMIT); \
    albb_messages = backtrace_symbols(albb_trace, albb_trace_size); \
    ASSERT_LOG_BACKTRACE("Execution_path:"); \
    for (albb_i=0; albb_i < albb_trace_size; ++albb_i) { \
        ASSERT_LOG_BACKTRACE_VA("%s", albb_messages[albb_i]); \
    } \
    free(albb_messages);\
} while(0)

#else

#define ASSERT_LOG_BACKTRACE_BACKTRACE() ASSERT_LOG_BACKTRACE("Not printing backtrace because not running on linux!")

#endif /*__linux__*/

#define ASSERT_MSG(EXPR, MSG) ASSERT_MSG_VA(EXPR, MSG "%s", "")

#define ASSERT_MSG_VA(EXPR, MSG, ...) do {\
    if (!(EXPR)) {\
        ASSERT_LOG_ASSERT_VA("Evaluation of '" #EXPR "' failed. ||| "  MSG, __VA_ARGS__);\
        ASSERT_LOG_BACKTRACE_BACKTRACE(); \
        goto on_error; /*Error handling*/\
    } \
} while (0)

#define ASSERT(EXPR) ASSERT_MSG(EXPR, "")

#define ASSERT_NON_NULL(EXPR) ASSERT_MSG(EXPR, "A null pointer was passed as argument.")

#define ASSERT_EXIT() \
do { \
    ASSERT_LOG_ASSERT("Reached point of no return. Exiting."); \
    ASSERT_LOG_BACKTRACE_BACKTRACE(); \
    exit(1); \
} while(0)


#define ASSERT_MALLOC(TYPE, VAR, COUNT) \
do { \
    VAR = (TYPE *) malloc(sizeof(TYPE) * (COUNT)); \
    ASSERT_NON_NULL(VAR); \
} while(0)

#define ASSERT_MALLOC_CREATE_VAR(TYPE, VAR, COUNT) \
TYPE *VAR; \
ASSERT_MALLOC(TYPE, VAR, COUNT)

#define ASSERT_FREE(p) \
do { \
ASSERT_NON_NULL(p); \
free(p); \
} while(0)

#endif /*ASSERT_H__*/
