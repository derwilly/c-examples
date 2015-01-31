/*
 * str.c
 * Ferdinand Saufler <mail@saufler.de>
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
