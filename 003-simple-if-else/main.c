/* Ferdinand Saufler <mail@saufler.de>
 * 06.03.2015
 * simple if else */

#include <stdio.h>

int main()
{
    int x = 1;
    int y = 2;

    /* tenary operator */
    int z = (x > y) ? 0 : 1;

    printf("z = %d\n", z);

    /* the example "tenary operator" equals: */
    if(x > y)
    {
        z = 0;
    }
    else
    {
        z = 1;
    }

    printf("z = %d\n", z);

    return 0;
}
