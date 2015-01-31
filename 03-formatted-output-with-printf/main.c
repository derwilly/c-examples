/* Ferdinand Saufler
 * mail@saufler.de
 * 28.01.2015
 *
 * formatted output with printf
 */

#include <stdio.h>

int main()
{
    printf("signed decimal integer: %i \n", 7);
    printf("signed decimal integer: %d \n", -4);
    printf("unsigned decimal integer: %i \n", 23);
    printf("unsigned octal: %o \n", 520);
    printf("unsigned hexadecimal integer: %x \n", 100);
    printf("unsigned hexadecimal integer (uppercase): %X \n", 100);
    printf("decimal floating point: %f \n", 102.47);
    printf("decimal floating point, rounded: %.2f \n", 102.47);
    printf("character: %c \n", 'c');
    printf("string: %s \n", "foo bar...");
    int p = 0;
    printf("pointer address: %p \n", &p);
    return 0;
}
