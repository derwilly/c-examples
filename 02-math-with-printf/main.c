/* Ferdinand Saufler
 * 27.05.2014
 *
 * calc with printf
 */

#include <stdio.h>

int main()
{
    printf("2 + 2 ist: %i\n", 2+2);
    printf("3 - 2 ist: %i\n", 3-2);
    printf("10 * 2 ist: %i\n", 10*2);
    printf("3.0 / 2.0 ist: %f\n", 3.0 / 2.0);
    printf("4.1 / 1.22 ist: %.2f (rounded on two digits)\n", 4.1 / 1.22);
    return 0;
}
