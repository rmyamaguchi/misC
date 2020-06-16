#include <stdio.h>
#include "enum.h"

ENUM(MONTHS, {JANUARY = 1,
              FEBRUARY,
              MARCH,
              APRIL,
              MAY,
              JUNE,
              JULY,
              AUGUST = 31,
              SEPTEMBER,
              OCTOBER,
              NOVEMBER,
              DECEMBER});

ENUM(WEEKDAYS, {SUNDAY = 1,
                MONDAY,
                TUESDAY,
                WEDNESDAY,
                THURSDAY,
                FRIDAY,
                SATURDAY});

int main()
{
    int num = 7;
    printf("\r\nHello");
    printf("\r\n|%2d| : |%s|", 1, STRENUM(MONTHS, 1));     // | 1| : |JANUARY|
    printf("\r\n|%2d| : |%s|", num, STRENUM(MONTHS, num)); // | 7| : |JULY|
    printf("\r\n|%2d| : |%s|", 31, STRENUM(MONTHS, 31));   // |31| : |AUGUST|
    printf("\r\n|%2d| : |%s|", 35, STRENUM(MONTHS, 35));   // |35| : |DECEMBER|

    char *str1 = STRENUM(WEEKDAYS, 2);   // pointing to "MONDAY"
    char *str2 = STRENUM(MONTHS, 3);     // overwrites, pointing to "MARCH"
    printf("\r\nWEEKDAYS : |%s|", str1); // |broken|
    printf("\r\nMONTHS : |%s|", str2);   // |MARCH|
}