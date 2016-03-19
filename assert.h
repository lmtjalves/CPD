
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
static void assert_log_backtrace(void) {
    const int BACKTRACE_LIMIT = 100;
    void *trace[BACKTRACE_LIMIT] ; 
    char **messages = (char **)NULL;
    int i, trace_size = 0;

    trace_size = backtrace(trace, BACKTRACE_LIMIT);
    messages = backtrace_symbols(trace, trace_size);
    ASSERT_LOG_BACKTRACE("Execution_path:");
    for (i=0; i<trace_size; ++i) {
        ASSERT_LOG_BACKTRACE_VA("%s", messages[i]);
    }
    free(messages);
}
#else
static void assert_log_backtrace(void) {
    ASSERT_LOG_BACKTRACE("Not printing backtrace because not running on linux!");
}
#endif /*__linux__*/

#define ASSERT_MSG(EXPR, MSG) ASSERT_MSG_VA(EXPR, MSG "%s", "")

#define ASSERT_MSG_VA(EXPR, MSG, ...) do {\
    if (!(EXPR)) {\
        ASSERT_LOG_ASSERT_VA("Evaluation of '" #EXPR "' failed. ||| "  MSG, __VA_ARGS__);\
        assert_log_backtrace();\
        goto on_error; /*Error handling*/\
    }\
} while (0)

#define ASSERT(EXPR) ASSERT_MSG(EXPR, "")

#define ASSERT_NON_NULL(EXPR) ASSERT_MSG(EXPR, "A null pointer was passed as argument.")

#define ASSERT_EXIT() \
do { \
    ASSERT_LOG_ASSERT("Exiting"); \
    exit(1); \
} while(0)

#define ASSERT_SENTINEL ASSERT_MSG(false, "Reached sentinel. This should never happen")

#endif /*ASSERT_H__*/
