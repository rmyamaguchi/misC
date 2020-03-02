/**
 * @file test_map.c
 * @author Renan Masashi Yamaguchi
 * @brief Test Map.h and Shapes.h
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "class.h"
#include "Map.h"
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
    int five;

    five = 5 + total;
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

int main(void)
{
    unsigned int opt = 1;

    switch (opt)
    {
    case 0:
    {
        int foo = 42;
        int bar = 314;
        int aaa = 11;
        char str[] = "banana";
        Map(map1, 5);

        printf("\r\n");
        map1.put("foo", &foo);
        map1.put("bar", &bar);
        map1.put("aaa", &aaa);
        map1.put("str", str);

        PRINT("%d", *(int *)map1.val("foo"));
        PRINT("%d", *(int *)map1.val("bar"));
        PRINT("%d", *(int *)map1.val("aaa"));
        PRINT("%s", (char *)map1.val("str"));
        printf("\r\n");
        break;
    }

    case 1:
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
        break;
    }

    default:
        break;
    }

    return 0;
}