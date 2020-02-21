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
 * @brief Does something need to be said?
 */
#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a < b ? b : a

/******************************************
 * @brief Macro overloading.
 * @note The overloaded macros must be named NAMEx, where x is the number arguments.
 * @warning This implementation does not work when nesting overloaded macros within 
 * other overloaded macros.
 */
#define CAT(A, B) A##B
#define SELECT(NAME, NUM) CAT(NAME, NUM)

#define GET_COUNT(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, COUNT, ...) COUNT
#define VA_SIZE(...) GET_COUNT(__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define VA_SELECT(NAME, ...)           \
    SELECT(NAME, VA_SIZE(__VA_ARGS__)) \
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
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME

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
#define PRINT(format, var) PRINT_F("\r\n" __FILE__ ":%d >> %s: " #format, __LINE__, VAL(var))

/******************************************
 * @brief Macros to assist in declaring objects.
 * @note The declaration of an object Obj should follow something along the lines:
 *    #define Obj_ATTRIBUTES(obj_name)
 *    #define Obj_METHODS(obj_name) \
 *       return_type METHOD(Obj, obj_name, func_name)(func_arguments) {...}
 *    #define Obj1(obj_name) CAST(Obj, obj_name)
 *    #define Objn(obj_name, attributes) \
 *       CLASS(Obj, obj_name); \
 *       // Initilization of n-1 attributes
 *    #define Obj(...) VA_SELECT(Obj, __VA_ARGS__)
 * @note Methods must have their respective function pointers as object attributes, which must be
 * properly initialized.
 */
#define METHOD(obj_type, obj_name, func_name) \
    __##obj_type##__##obj_name##_##func_name

#define _METHODS2(obj_type, obj_name) \
    obj_type##_METHODS(obj_name)
#define _METHODS3(obj_type, obj_name, obj_inherit) \
    _METHODS2(obj_type, obj_name)                  \
    _METHODS2(obj_inherit, obj_name)
#define _METHODS(...)                            \
    GET_MACRO(__VA_ARGS__, _METHODS3, _METHODS2) \
    (__VA_ARGS__)

#define _ATTRIBUTES2(obj_type, obj_name) \
    obj_type##_ATTRIBUTES(obj_name)
#define _ATTRIBUTES3(obj_type, obj_name, obj_inherit) \
    _ATTRIBUTES2(obj_inherit, obj_name)               \
    _ATTRIBUTES2(obj_type, obj_name)
#define _ATTRIBUTES(...)                               \
    GET_MACRO(__VA_ARGS__, _ATTRIBUTES3, _ATTRIBUTES2) \
    (__VA_ARGS__)

#define _CLASS2(obj_type, obj_name)          \
    static struct __##obj_type##__##obj_name \
    {                                        \
        _ATTRIBUTES(obj_type, obj_name)      \
    } obj_name;                              \
    _METHODS(obj_type, obj_name)
#define _CLASS3(obj_type, obj_name, obj_inherit)     \
    static struct __##obj_type##__##obj_name         \
    {                                                \
        _ATTRIBUTES(obj_type, obj_name, obj_inherit) \
    } obj_name;                                      \
    _METHODS(obj_type, obj_name, obj_inherit)

#define _CAST2(obj_type, obj_name) \
    (*((struct {_ATTRIBUTES(obj_type, obj_name)} *)(obj_name)))
#define _CAST3(obj_type, obj_name, obj_inherit) \
    (*((struct {_ATTRIBUTES(obj_type, obj_name, obj_inherit)} *)(obj_name)))

#define CLASS(...)                           \
    GET_MACRO(__VA_ARGS__, _CLASS3, _CLASS2) \
    (__VA_ARGS__)

#define CAST(...)                          \
    GET_MACRO(__VA_ARGS__, _CAST3, _CAST2) \
    (__VA_ARGS__)

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

typedef union VOID_P {
    void *void_;
    char *s;
    int *d;
    long *l;
    unsigned int *ui;
    unsigned long *lu;
} Ptr;

#endif /* UTIL_H */