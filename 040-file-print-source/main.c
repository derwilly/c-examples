/* Ferdinand Saufler <mail@saufler.de>
 * 01.03.2015
 * this program prints its own sourcecode */

#include <stdio.h>

int main()
{
    FILE *f;
    char c;
    f = fopen(__FILE__,"r");

    while(c != EOF)
    {
        c = getc(f);
        if((int)c != -1)
        {
            putchar(c);
        }
    }
    printf("\n");
    fclose(f);
    return 0;
}
