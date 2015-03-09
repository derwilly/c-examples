/* print bits of an integer */

#include <stdio.h>
#include <str.h>

int main(void)
{
    int i;
    for(i=0;i<=16;i++)
    {
        print_bits(i);
    }

    printf("\n");

    print_bits(1000);
    print_bits(65535);
    print_bits(4294967295);

    return 0;
}
