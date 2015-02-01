/* str.c
 * Ferdinand Saufler
 * 21.11.2014
 */

#include <string.h>
#include "str.h"

int starts_with(char* pattern, char* str)
{
    int len = strlen(pattern);
    if(strncmp(pattern, str, len) == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void to_upper(char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;

        ++str;
    }
}

void to_lower(char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;

        ++str;
    }
}
