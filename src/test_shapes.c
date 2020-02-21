/**
 * @file test_shapes.c
 * @author Renan Masashi Yamaguchi
 * @brief Test Shapes.h
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "util.h"
#include "Shapes.h"

int getTotalArea(OBJ *Shapes, int len)
{
    int i_total = 0;
    for (int i = 0; i < len; i++)
        i_total += Shape(Shapes[i]).area();
    return i_total;
}

int getTotalAreaPlus(OBJ *Shapes, int len)
{
    int i_total = 0;
    int i_five = 5;
    Circle(Circulo, i_five);

    Circulo.self();
    PRINT(% d, Circulo.area());
    PRINT(% d, Circulo.perimeter());
    printf("\r\n");
    for (int i = 0; i < len; i++)
        i_total += Shape(Shapes[i]).area();
    i_total += Circulo.area();
    return i_total;
}

void testShapes(void)
{
    Circle(Circulo, 10);
    Square(Quadrado, 10);
    OBJ Shapes[2];

    Shapes[0] = &Circulo;
    Shapes[1] = &Quadrado;

    Circulo.self();
    PRINT(% d, Circulo.area());
    PRINT(% d, Circulo.perimeter());
    printf("\r\n");
    Quadrado.self();
    PRINT(% d, Quadrado.area());
    PRINT(% d, Quadrado.perimeter());
    printf("\r\n");
    PRINT(% d, getTotalArea(Shapes, 2));
    printf("\r\n");
    PRINT(% d, getTotalAreaPlus(Shapes, 2));
}