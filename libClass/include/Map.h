/**
 * @file Map.h
 * @author Renan Masashi Yamaguchi
 * @brief A pseudo (kind of) Map object in C (GNU C)
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef MAP_H
#define MAP_H

#include "util.h"

/* Map object */
#define Map_ATTRIBUTES(name) \
    int size;                \
    int i;                   \
    char **keys;             \
    void **vals;             \
    void *(*val)(char *);    \
    void (*put)(char *, void *);

#define Map_METHODS(name)                                                       \
    void *METHOD(Map, name, val)(char *__key)                                   \
    {                                                                           \
        for (int __i = 0; __i < (name).size && (name).keys[__i] != NULL; __i++) \
            if (!strcmp((name).keys[__i], __key))                               \
                return (name).vals[__i];                                        \
        return NULL;                                                            \
    }                                                                           \
    void METHOD(Map, name, put)(char *__key, void *__val)                       \
    {                                                                           \
        for (int __i = 0; __i < (name).size; __i++)                             \
        {                                                                       \
            if ((name).keys[__i] == NULL)                                       \
                (name).keys[__i] = __key;                                       \
            if (!strcmp((name).keys[__i], __key))                               \
            {                                                                   \
                (name).vals[__i] = __val;                                       \
                return;                                                         \
            }                                                                   \
        }                                                                       \
    }

#define Map1(name) CAST(Map, name)
#define Map2(name, const_len)               \
    CLASS(Map, name);                       \
    (name).size = (const_len);              \
    (name).i = 0;                           \
    (name).keys = (char * [(const_len)]){}; \
    (name).vals = (void * [(const_len)]){}; \
    (name).val = METHOD(Map, name, val);    \
    (name).put = METHOD(Map, name, put);

#define Map(...) VA_SELECT(Map, __VA_ARGS__)

#endif /* MAP_H */