
#ifndef ASSERT_H__
#define ASSERT_H__

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

/* Repeating macro from debug.h but without the variadic args because we're compiling with C89*/
#define ASSERT_CLEAN_ERRNO() (errno == 0 ? "None" : strerror(errno))
#define ASSERT_LOG_GENERIC0(LOG_TYPE, MESSAGE) \
do {\
fprintf(stderr, LOG_TYPE " (%s:%d: errno: %s ) " MESSAGE "\n", __FILE__, __LINE__, ASSERT_CLEAN_ERRNO());\
} while(0)

#define ASSERT_LOG_GENERIC1(LOG_TYPE, MESSAGE, ARG1) \
do {\
fprintf(stderr, LOG_TYPE " (%s:%d: errno: %s ) " MESSAGE "\n", __FILE__, __LINE__, ASSERT_CLEAN_ERRNO(),ARG1);\
} while(0)

#define ASSERT_LOG_BACKTRACE0(MESSAGE) ASSERT_LOG_GENERIC0("[BACKTRACE]", MESSAGE)
#define ASSERT_LOG_BACKTRACE1(MESSAGE, ARG1) ASSERT_LOG_GENERIC1("[BACKTRACE]", MESSAGE, ARG1)
#define ASSERT_LOG_ASSERT0(MESSAGE) ASSERT_LOG_GENERIC0("[ASSERT]", MESSAGE)
#define ASSERT_LOG_ASSERT1(MESSAGE, ARG1) ASSERT_LOG_GENERIC1("[ASSERT]", MESSAGE, ARG1)

#ifdef __linux__
#include <execinfo.h>
static void assert_log_backtrace(void) {
    const int BACKTRACE_LIMIT = 100;
    void *trace[BACKTRACE_LIMIT] ; 
    char **messages = (char **)NULL;
    int i, trace_size = 0;

    trace_size = backtrace(trace, BACKTRACE_LIMIT);
    messages = backtrace_symbols(trace, trace_size);
    ASSERT_LOG_BACKTRACE0("Execution_path:");
    for (i=0; i<trace_size; ++i) {
        ASSERT_LOG_BACKTRACE1("%s", messages[i]);
    }
    free(messages);
}
#else
static void assert_log_backtrace(void) {
    ASSERT_LOG_BACKTRACE0("Not printing backtrace because not running on linux!");
}
#endif /*__linux__*/

#define ASSERT_MSG(EXPR, MSG) do {\
    if (!(EXPR)) {\
        ASSERT_LOG_ASSERT1("Evaluation of '" #EXPR "' failed. MSG: %s", MSG);\
        assert_log_backtrace();\
        goto on_error; /*Error handling*/\
    }\
} while (0)

#define ASSERT(EXPR) ASSERT_MSG(EXPR, "")

#define ASSERT_NON_NULL(EXPR) ASSERT_MSG(EXPR, "A null pointer was passed as argument.")

#define ASSERT_EXIT() \
do { \
    ASSERT_LOG_ASSERT0("Exiting"); \
    exit(1); \
} while(0)

#endif /*ASSERT_H__*/
