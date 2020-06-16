#include <stdlib.h>
#include <string.h>
#include "enum.h"

/**
 * @brief Clear all of the specified character in the given string.
 *  
 * @param[in,out] s String to be cleaned
 * @param[in] c Chosen character
 */
static void strclean(char *s, char c)
{
    char *p = s;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] != c)
            *(p++) = s[i++];
        else /* skip when == c */
            i++;
    }
    *p = '\0';
}

#define BUFF_SIZE 1024         ///< Max size of enum string
static const char sep[] = ","; ///< enum standard separator

/**
 * @brief Translate a number to the equivalent string in a given enum.
 * 
 * @param[in] e Enumeration full body as a string
 * @param[in] num Number to be translated
 * 
 * @return String translation
 */
char *strenum(const Enum e, int num)
{
    static char aux[BUFF_SIZE]; ///< Internal buffer string

    char *str = "NULL"; ///< String member of the enum
    int val = 0;        ///< Enumerator value
    char *c;

    strcpy(aux, e);
    strclean(aux, ' ');
    strclean(aux, '{');
    strclean(aux, '}');

    str = strtok(aux, sep);
    while (str != NULL)
    {
        /* Check if a number is forced */
        c = strchr(str, '=');
        if (c != NULL)
        {
            val = atoi(c + 1);
            *c = '\0';
        }
        /* Check if it is the right number */
        if (num == val++)
            break;
        /* Get next string */
        str = strtok(NULL, sep);
    }
    return str == NULL ? "NULL" : str;
}
