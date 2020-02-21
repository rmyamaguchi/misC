/**
 * @file Shapes.h
 * @author Renan Masashi Yamaguchi
 * @brief Classic inheritance test
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef SHAPES_H
#define SHAPES_H

#include "util.h"

/* Shape object */
#define Shape_ATTRIBUTES(name) \
    int (*area)(void);         \
    int (*perimeter)(void);    \
    void (*self)(void);

#define Shape_METHODS(name) \
    void METHOD(Shape, name, self)(void) { printf("\r\nMy name is: %s", #name); }

#define Shape1(name) CAST(Shape, name)
#define Shape2(name, NULL) \
    CLASS(Shape, name);    \
    (name).self = METHOD(Shape, name, self);

#define Shape(...) VA_SELECT(Shape, __VA_ARGS__)

/* Circle object */
#define PI 3.1416
#define Circle_ATTRIBUTES(name) \
    int r;

#define Circle_METHODS(name)                                                         \
    int METHOD(Circle, name, area)(void) { return (int)(PI * (name).r * (name).r); } \
    int METHOD(Circle, name, perimeter)(void) { return (int)(2 * PI * (name).r); }

#define Circle1(name) CAST(Circle, name)
#define Circle2(name, radius)                           \
    CLASS(Circle, name, Shape);                         \
    (name).r = radius;                                  \
    (name).area = METHOD(Circle, name, area);           \
    (name).perimeter = METHOD(Circle, name, perimeter); \
    (name).self = METHOD(Shape, name, self);

#define Circle(...) VA_SELECT(Circle, __VA_ARGS__)

/* Square object */
#define Square_ATTRIBUTES(name) \
    int l;

#define Square_METHODS(name)                                             \
    int METHOD(Square, name, area)(void) { return (name).l * (name).l; } \
    int METHOD(Square, name, perimeter)(void) { return 4 * (name).l; }

#define Square1(name) CAST(Square, name)
#define Square2(name, side)                             \
    CLASS(Square, name, Shape);                         \
    (name).l = side;                                    \
    (name).area = METHOD(Square, name, area);           \
    (name).perimeter = METHOD(Square, name, perimeter); \
    (name).self = METHOD(Shape, name, self);

#define Square(...) VA_SELECT(Square, __VA_ARGS__)

/* Tests */
extern void testShapes(void);

#endif /* SHAPES_H */
