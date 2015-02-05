/* how to print a memory address
 * start the program a several times, is the printed memory
 * address always the same? why? */

#include <stdio.h>

int main()
{
    int i = 42;
    printf("address of i: %p\n", &i);
    return 0;
}
