/* bit operators */

#include <stdio.h>

int main(void)
{
    // not
    printf("not:\n");
    printf("!0     = %d\n", !0);
    printf("!1     = %d\n\n", !1);

    // and
    printf("and:\n");
    printf("0 & 0 = %d\n",   0 & 0);
    printf("0 & 1 = %d\n",   0 & 1);
    printf("1 & 0 = %d\n",   1 & 0);
    printf("1 & 1 = %d\n\n", 1 & 1);

    // nand
    printf("nand:\n");
    printf("!(0 & 0) = %d\n",   !(0 & 0));
    printf("!(0 & 1) = %d\n",   !(0 & 1));
    printf("!(1 & 0) = %d\n",   !(1 & 0));
    printf("!(1 & 1) = %d\n\n", !(1 & 1));

    // or
    printf("or:\n");
    printf("0 | 0 = %d\n",   0 | 0);
    printf("0 | 1 = %d\n",   0 | 1);
    printf("1 | 0 = %d\n",   1 | 0);
    printf("1 | 1 = %d\n\n", 1 | 1);

    // nor
    printf("nor:\n");
    printf("!(0 | 0) = %d\n",   !(0 | 0));
    printf("!(0 | 1) = %d\n",   !(0 | 1));
    printf("!(1 | 0) = %d\n",   !(1 | 0));
    printf("!(1 | 1) = %d\n\n", !(1 | 1));

    // xor
    printf("xor:\n");
    printf("0 ^ 0 = %d\n",   0 ^ 0);
    printf("0 ^ 1 = %d\n",   0 ^ 1);
    printf("1 ^ 0 = %d\n",   1 ^ 0);
    printf("1 ^ 1 = %d\n\n", 1 ^ 1);

    // xnor
    printf("xnor:\n");
    printf("!(0 ^ 0) = %d\n",   !(0 ^ 0));
    printf("!(0 ^ 1) = %d\n",   !(0 ^ 1));
    printf("!(1 ^ 0) = %d\n",   !(1 ^ 0));
    printf("!(1 ^ 1) = %d\n\n", !(1 ^ 1));

    return 0;
}
