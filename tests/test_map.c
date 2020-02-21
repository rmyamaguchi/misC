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

void testMap(void)
{
    int i_foo = 42;
    int i_bar = 314;
    int i_aaa = 11;
    char s_str[] = "banana";
    Map(map1, 5);

    printf("\r\n");
    map1.put("foo", &i_foo);
    map1.put("bar", &i_bar);
    map1.put("aaa", &i_aaa);
    map1.put("str", s_str);

    PRINT(%d, *(int *)map1.val("foo"));
    PRINT(%d, *(int *)map1.val("bar"));
    PRINT(%d, *(int *)map1.val("aaa"));
    PRINT(%s, (char *)map1.val("str"));
    printf("\r\n");
}