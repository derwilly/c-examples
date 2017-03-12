/*
 * Password Generator V1.4.1
 * main.c
 * Ferdinand Saufler <mail@saufler.de>
 * 12.03.2013, last updated 12.03.2017
 *
 * Copyright (C) 2014 Ferdinand Saufler
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <stdlib.h>  // rand
#include <string.h>
#include <time.h>

#define C_SET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!$%&/{}[]()=?+*#.:,;-_<>@~"
#define GENX_TIMES 7
#define PW_MIN_LEN 3
#define PW_MAX_LEN 128

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("usage: %s [length]\n", argv[0]);
        return -1;
    }
    char *pEnd;
    int length = strtol(argv[1], &pEnd, 10);
    if(length <= 0)
    {
        printf("usage: %s [length]\n", argv[0]);
        return -2;
    }
    if(length < PW_MIN_LEN)
    {
        printf("usage: %s [length]. Password min length is %d.\n", argv[0],PW_MIN_LEN);
        return -2;
    
    }
    if(length > PW_MAX_LEN)
    {
        printf("usage: %s [length]. Password max length is %d.\n", argv[0],PW_MAX_LEN);
        return -2;
    
    }


    printf("choose one password from the list below:\n");

    /* Initialize random seed */
    srand (time(NULL));

    /* get len of C_SET */
    int c_source_len = sizeof(C_SET) / sizeof(C_SET[0]);

    if(length >= PW_MIN_LEN && length <= PW_MAX_LEN)
    {
        int i, j, r;
        char *pw = (char *)malloc(length * sizeof(char) + 1);
        for(j = 0; j < GENX_TIMES; j++)
        {
            for(i = 0;i < length; i++)
            {
                r = rand() % (c_source_len-1);
                pw[i] = C_SET[r];
            }

            pw[++i] = 0;
            printf("password: %s \n", pw);
        }
        free(pw);
    }
    return 0;
}
