/**
 * @file util.h
 * @author Renan Masashi Yamaguchi
 * @brief Some useful macros, typedefs and brainstroming ;)
 * @version 0.1
 * @date 2020-02-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef UTIL_H
#define UTIL_H

/************************************************************************************
 * POSIX DEFINES
 ************************************************************************************/

/************************************************************************************
 * INCLUDES
 ************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************
 * DEFINES
 ************************************************************************************/
#define PRINT_F printf

/************************************************************************************
 * MACROS
 ************************************************************************************/

/******************************************
 * @brief Some classics
 */
#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a < b ? b : a
#define UNREF_PAR(x) (x) = (x)

/******************************************
 * @brief Macro overloading.
 * @note The overloaded macros must be named NAMEx, where x is the number arguments.
 * @warning This implementation does not work when nesting overloaded macros within 
 * other overloaded macros.
 */
#define CAT(a, b) a##b
#define SELECT(name, num) CAT(name, num)

#define GET_COUNT(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, count, ...) count
#define VA_SIZE(...) GET_COUNT(__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define VA_SELECT(name, ...)           \
    SELECT(name, VA_SIZE(__VA_ARGS__)) \
    (__VA_ARGS__)

#ifdef EXAMPLE
#define FOO(...) VA_SELECT(FOO, __VA_ARGS__)
#define FOO1(foo) (foo)
#define FOO2(foo, oof) (foo) + (oof)
#define FOO3(foo, oof, fofo) (foo) + (oof) + (fofo)
#endif

/******************************************
 * @brief Macro overloading that works when nested within other overloaded macros.
 * @note The macro that accepts the maximum number of arguments must always be present.
 */
#define NONE(...)
#define GET_MACRO(_1, _2, _3, name, ...) name

#ifdef EXAMPLE
#define FOO2(foo, oof) (foo) + (oof)
#define FOO3(foo, oof, fofo) (foo) + (oof) + (fofo)
#define FOO(...)                       \
    GET_MACRO(__VA_ARGS__, FOO3, FOO2) \
    (__VA_ARGS__)
#endif

/******************************************
 * @brief Macro to print a variable name and its value.
 */
#define VAL(var) #var, (var)
#define PRINT(format, var) PRINT_F("\r\n" __FILE__ ":%d >> %s: " format, __LINE__, VAL(var))

/******************************************
 * @brief Macro to test if things worked (0 => OK)
 */
#define ASSERT(x)             \
    if (x)                    \
    {                         \
        PRINT("ERROR %d", x); \
        exit(EXIT_FAILURE);   \
    }

/******************************************
 * @brief Something to avoid too many #ifdef _DEBUG_.
 */
#ifdef _DEBUG_
#define IF_DBG(...) __VA_ARGS__
#define ELSE(...)
#else
#define IF_DBG(...)
#define ELSE(...) __VA_ARGS__
#endif /* _DEBUG_ */

/************************************************************************************
 * TYPEDEFS
 ************************************************************************************/
typedef void *OBJ;

typedef unsigned char byte;

typedef union VOID_P {
    void *void_;
    char *s;
    int *d;
    long *l;
    unsigned int *ui;
    unsigned long *lu;
} Ptr;

#endif /* UTIL_H */