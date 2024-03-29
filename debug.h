#ifndef DEBUG_H__
#define DEBUG_H__
/* Inspired in c.learncodethehardway.org/book/ex20.html */

#include <stdio.h>
#include <errno.h>
#include <string.h>

/*Implementation*/

#define DEBUG_LEVEL_NO_DEBUG -10
#define DEBUG_LEVEL_ERROR 0
#define DEBUG_LEVEL_WARN 10
#define DEBUG_LEVEL_INFO 20
#define DEBUG_LEVEL_DEBUG 30


/*if DEBUG_LOG_LEVEL is not defined at compile time we assume runtime debug option.*/
#ifndef DEBUG_LOG_LEVEL
extern int debug_log_level;
#define DEBUG_LOG_LEVEL debug_log_level
/*maybe we should do some checking*/
#define DEBUG_SET_LEVEL(LEVEL) \
do { \
    debug_log_level = LEVEL; \
} while(0)

#else 
/*no need to define DEBUG_LOG_LEVEL because it's already defined*/
#define DEBUG_SET_LEVEL(LEVEL) LOG_ERROR("Trying to set debug level when debug is compile time set.%s", "")
#endif

#define DEBUG_CLEAN_ERRNO() (errno == 0 ? "None" : strerror(errno))

#define DEBUG_REAL_LOG_GENERIC(LOG_TYPE, MESSAGE, ...) \
    do {\
        if (errno == 0) { \
            fprintf(stderr, LOG_TYPE " (%s:%5d) " MESSAGE "\n", __FILE__, __LINE__,  __VA_ARGS__);\
        } else { \
            fprintf(stderr, LOG_TYPE " (%s:%5d: errno: %s) " MESSAGE "\n", __FILE__, __LINE__, DEBUG_CLEAN_ERRNO(), __VA_ARGS__);\
            errno = 0; \
        } \
    } while(0)


/*Defined so we don't have to put "" at the end of every LOG*. It's used to allow for no arguments*/
#define DEBUG_LOG_GENERIC(LOG_TYPE, LEVEL, MESSAGE, ...) \
    do { \
        if ( LEVEL <= DEBUG_LOG_LEVEL) { \
            DEBUG_REAL_LOG_GENERIC(LOG_TYPE, MESSAGE "%s", __VA_ARGS__, " "); \
        } \
    } while(0)





/* Public interface */
#define LOG_ERROR(MESSAGE, ...) DEBUG_LOG_GENERIC("[ERROR]", DEBUG_LEVEL_ERROR, MESSAGE, __VA_ARGS__)
#define LOG_WARN(MESSAGE, ...) DEBUG_LOG_GENERIC("[WARN]", DEBUG_LEVEL_WARN, MESSAGE, __VA_ARGS__)
#define LOG_INFO(MESSAGE, ...) DEBUG_LOG_GENERIC("[INFO]", DEBUG_LEVEL_INFO, MESSAGE, __VA_ARGS__)
#define LOG_DEBUG(MESSAGE, ...) DEBUG_LOG_GENERIC("[DEBUG]", DEBUG_LEVEL_DEBUG, MESSAGE, __VA_ARGS__)

#endif /*DEBUG_H__*/
