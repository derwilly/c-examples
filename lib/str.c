/* str.c
 * Ferdinand Saufler
 * 21.11.2014
 */

#include <string.h>
#include <stdio.h>
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
        {
            *str -= 32;
        }
        ++str;
    }
}

void to_lower(char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str += 32;
        }
        ++str;
    }
}

void print_bits(int value)
{
    int i;

    /* how long is an integer on this machine? */
    int s = sizeof(int) * 8;

    /* create a mask, the mask should be 1000...000 */
    int mask = 1 << (s - 1);

    /* iterate over the number of bits an integer has */
    for(i = 1; i <= s; i++)
    {
        putchar(((value & mask) == 0) ? '0' : '1');
        /* shift value by one bit to the left */
        value = value << 1;

        /* insert a whitespace after 8 bits to group them */
        if(i % 8 == 0 && i < s)
        {
            printf(" ");
        }
    }
    printf("\n");
}
