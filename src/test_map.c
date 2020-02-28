/**
 * @file test_map.c
 * @author Renan Masashi Yamaguchi
 * @brief Test Map.h
 * @version 0.1
 * @date 2020-02-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "util.h"
#include "Map.h"

void test_map(void)
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
}