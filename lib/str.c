/* str.c
 * Ferdinand Saufler
 * 21.11.2014
 */

#include <stdio.h>
#include <stdlib.h>
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

char *remove_blanks(char *str)
{
    /* allocate memory for the new "blank-cleared" string */
    char *new_str = (char*)malloc(sizeof(strlen(str)+1));

    /* count vars */
    int i = 0;
    int j = 0;

    /* iterate over the string until we find '\0' */
    while (str[i] != '\0')
    {
        /* if there is no doubled-space, copy the character*/
        if (!(str[i] == ' ' && str[i+1] == ' ')) {
            new_str[j] = str[i];
            j++;
        }
        i++;
    }

    /* remove a tailing ' ' at the end of the string. */
    if (new_str[j-1] == ' ')
        new_str[j-1] = '\0';
    else
        new_str[j] = '\0';

    return new_str;
}

int count_char(char *str, const char c)
{
    int count = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == c)
            count++;
        i++;
    }
    return count;
}
