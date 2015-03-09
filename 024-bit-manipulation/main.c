/* how to set, clear and toggle a single bit in c. */

#include <stdio.h>
#include <stdint.h>


void print_bin(int number)
{
    if (number)
    {
        print_bin(number >> 1);
        putc((number & 1) ? '1' : '0', stdout);
    }
    else
    {
        putc('0', stdout);
    }
}

int main()
{
    uint8_t reg = 0b00000000;

    /* SETTING A BIT
       Use the bitwise OR operator (|) to set a bit.
       That will set bit x. */
    reg |= 1 << 2;

    print_bin(reg);
    printf("\n");

    /* CLEARING A BIT
       Use the bitwise AND operator (&) to clear a bit.
       That will clear bit x. You must invert the bit string with the bitwise
       NOT operator (~), then AND it. */
    reg &= ~(1 << 2);

    print_bin(reg);
    printf("\n");

    /* TOGGLING A BIT
       The XOR operator (^) can be used to toggle a bit.
       That will toggle bit x. */
    reg ^= 1 << 2;

    print_bin(reg);
    printf("\n");

    /* CHECKING A BIT
       To check a bit, AND it with the bit you want to check */
    if(reg & (1 << 2))
        printf("bit 2 is set\n");

    return 0;
}
