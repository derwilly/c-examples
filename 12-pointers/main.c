/* pointers */

#include <stdio.h>

int main(int argc, char* argv[])
{
    int firstval, secoundval;
    int *pntr;

    pntr = &firstval;
    *pntr = 10;
    pntr = &secoundval;
    *pntr = 20;

    printf("firstval is %d\n", firstval);
    printf("secoundval is %d\n", secoundval);

    return 0;
}
