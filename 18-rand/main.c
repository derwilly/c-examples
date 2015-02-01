/* random number generation */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int i, r;

    /* seed the random generator */
    srand(time(NULL));

    /* generate 10 random numbers between 0 and 9 */
    for(i = 1; i <= 10; i++)
    {
        r = rand() % 10;
        printf("%d ", r);
    }

    printf("\n");
    return 0;
}
