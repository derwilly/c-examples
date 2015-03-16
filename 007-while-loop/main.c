/* Ferdinand Saufler <mail@saufler.de>
 * 14.03.2015
 * while loop */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* print each entry in argv */
    int args = 0;
    while(args < argc)
    {
        printf("arg %d: %s\n", args, argv[args]);
        args++;

        if(args == argc)
        {
            printf("\n");
        }
    }

    /* now lets print a countdown */
    int n = 3;
    while (n>0)
    {
        printf("%d, ",n) ;
        --n;
    }

    printf("meins!\n");

    return 0;
}
