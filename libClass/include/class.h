
#ifndef CLASS_H
#define CLASS_H

#include "util.h"

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

#endif /* CLASS_H */