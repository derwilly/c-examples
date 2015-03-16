/* Ferdinand Saufler <mail@saufler.de>
 * 14.03.2015
 * ternary operator */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 1;

    printf("a is %s\n",  a >= 0 ? "positive" : "negative");
    printf("a has value %s\n",  a == 0 ? "equal to zero" : "different from zero");

    return 0;
}
