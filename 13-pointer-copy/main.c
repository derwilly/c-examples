/* Ferdinand Saufler
 * 27.05.2014
 *
 * more Pointer stuff
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    int firstval = 5, secoundval = 10;
    int *p1, *p2;

    p1 = &firstval;
    p2 = &secoundval;
    *p1 = 10;
    *p2 = *p1;
    p1 = p2;
    *p1 = 20;

    printf("firstval is %d\n", firstval);
    printf("secoundval is %d\n", secoundval);

    return 0;
}
