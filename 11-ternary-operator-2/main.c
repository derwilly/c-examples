/* ternary operator 2 */

#include <stdio.h>

int main(void)
{
    int a = 0;
    printf("a is %s\n",  a == 0 ? "zero" : a > 0 ? "positive" : "negative");

    int b = 1;
    printf("b is %s\n",  b == 0 ? "zero" : b > 0 ? "positive" : "negative");

    return 0;
}
