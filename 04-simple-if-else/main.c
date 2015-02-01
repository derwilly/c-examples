/* Ferdinand Saufler
 * 28.01.2015
 *
 * simple if else
 */

#include <stdio.h>

int main()
{
    int x = 1;
    int y = 2;

    // tenary operator
    int z = (x > y) ? 0 : 1;

    printf("z = %i\n", z);

    // the example "tenary operator" equals:
    if(x > y)
    {
        z = 0;
    }
    else
    {
        z = 1;
    }

    printf("z = %i\n", z);

    return 0;
}
