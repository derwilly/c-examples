/* Ferdinand Saufler
 * mail@saufler.de
 * 10.11.2014
 *
 * if else conditions
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 1;
    char c = 'c';
    char *arr = "fox";

    if(i==0)
    {
        printf("i is 0.\n");
    }
    else
    {
        printf("i is not 0. its %d\n", i);
    }

    if(strlen(&c) == 1)
    {
        printf("the string-lenth of c is 1.\n");
    }
    else if(strlen(&c) == 2)
    {
        printf("the string-lenth of c is 2.\n");
    }
    else if(strlen(&c) > 2)
    {
        printf("the string-lenth of c is greater than 2.\n");
    }
    else
    {
        printf("anything else.\n");
    }

    if(strcmp(arr, "fox") == 0)
    {
        printf("arr is a fox.\n");
    }
    else
    {
        printf("arr isnt a fox.");
    }

    return 0;
}
