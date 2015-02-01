/* Ferdinand Saufler
 * mail@saufler.de
 * 27.05.2014
 *
 * Pointer to functions
 */

#include <stdio.h>

int operate(int a, int b, int (*fptr)(int,int))
{
    return (*fptr)(a,b);
}

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int main(int argc, char* argv[])
{
    int a;
    int (*subtraction)(int,int) = sub;

    a = operate(1, 2, add);
    a = operate(10, a, subtraction);
    printf("10 - (1 + 2) = %d\n", a);

    return 0;
}
