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

int get_total_area(OBJ *Shapes, int len)
{
    int total = 0;
    for (int i = 0; i < len; i++)
        total += Shape(Shapes[i]).area();
    return total;
}

int get_total_area_plus(OBJ *Shapes, int len)
{
    int total = 0;
    int five = 5;
    Circle(Circulo, five);

    Circulo.self();
    PRINT("%d", Circulo.area());
    PRINT("%d", Circulo.perimeter());
    printf("\r\n");
    for (int i = 0; i < len; i++)
        total += Shape(Shapes[i]).area();
    total += Circulo.area();
    return total;
}

void test_shapes(void)
{
    Circle(Circulo, 10);
    Square(Quadrado, 10);
    OBJ Shapes[2];

    Shapes[0] = &Circulo;
    Shapes[1] = &Quadrado;

    Circulo.self();
    PRINT("%d", Circulo.area());
    PRINT("%d", Circulo.perimeter());
    printf("\r\n");
    Quadrado.self();
    PRINT("%d", Quadrado.area());
    PRINT("%d", Quadrado.perimeter());
    printf("\r\n");
    PRINT("%d", get_total_area(Shapes, 2));
    printf("\r\n");
    PRINT("%d", get_total_area_plus(Shapes, 2));
}