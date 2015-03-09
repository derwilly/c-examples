/* Ferdinand Saufler <mail@saufler.de>
 * 09.03.2015
 * type casting example */

#include <stdio.h>

int main()
{
    int i = 11, j = 3;
    double d;

    d = (double)i/j;

    printf("%d / %d = %.2f\n",i,j,d);

    return 0;
}
