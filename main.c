/**
 * @file main.c
 * @author Renan Yamaguchi (renan.yamaguchi@setis.com)
 * @brief main to test things
 * @version 0.1
 * @date 2020-02-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "util.h"
#include "Map.h"
#include "Shapes.h"
#include "bmp.h"

#define NUM_TESTS 3

void (*gv_tests[NUM_TESTS])(void) = {testMap, testShapes, testBmp};

int main(void)
{
    unsigned int opt = 2;

    if (opt >= NUM_TESTS)
        return 1;

    gv_tests[opt]();

    return 0;
}