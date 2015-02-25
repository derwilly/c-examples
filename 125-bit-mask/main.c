/* using a bitmask to change the value of a 8-bit register */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    /* set reg to "0110 0110" */
    uint8_t reg = 0x66;

    /* initialize the mask to "1111 0000" */
    uint8_t mask = 0xf0;

    /* set the first tetrade to "0000" => reg = "0000 0110" */
    reg &= ~mask;

    /* now you can or the new value for the first tetrade to reg.
     * reg should be "0011 0110" now */
    reg |= 0x30;

    /* print the value of reg, "0011 0110"[2] = "54"[10] */
    printf("reg: %u\n",reg);

    return 0;
}
