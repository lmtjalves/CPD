/* Inspired in c.learncodethehardway.org/book/ex20.html */

#ifndef DEBUG_H__
#define DEBUG_H__

#ifdef NDEBUG

#define LOG_GENERIC(LOG_TYPE, MESSAGE, ...)
#define LOG_DEBUG(MESSAGE, ...)
#define LOG_ERROR(MESSAGE, ...)
#define LOG_WARN(MESSAGE, ...) 
#define LOG_INFO(MESSAGE, ...) 
#define SENTINEL(MESSAGE, ...) 

#else

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define CLEAN_ERRNO() (errno == 0 ? "None" : strerror(errno))

/* Public interface, so we only include these inside the ifdef NDEBUG*/
#define LOG_GENERIC(LOG_TYPE, MESSAGE, ...) \
do {\
fprintf(stderr, LOG_TYPE " (%s:%d: errno: %s ) " MESSAGE "\n", __FILE__, __LINE__, CLEAN_ERRNO(), __VA_ARGS__);\
} while(0)
#define LOG_DEBUG(MESSAGE, ...) LOG_GENERIC("[DEBUG]", MESSAGE, __VA_ARGS__)
#define LOG_ERROR(MESSAGE, ...) LOG_GENERIC("[ERROR]", MESSAGE, __VA_ARGS__)
#define LOG_WARN(MESSAGE, ...) LOG_GENERIC("[WARN]", MESSAGE, __VA_ARGS__)
#define LOG_INFO(MESSAGE, ...) LOG_GENERIC("[INFO]", MESSAGE, __VA_ARGS__)
#endif /*NDEBUG*/

#endif /*DEBUG_H__*/
