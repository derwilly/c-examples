/* limits */

#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    printf("limits on this system:\n");
    printf("number of bits in a char: %d\n", CHAR_BIT);
    printf("Minimum value a \"signed char\" can hold.: %d\n", SCHAR_MIN);
    printf("Maximum value a \"signed char\" can hold.: %d\n", SCHAR_MAX);
    printf("Maximum value an \"unsigned char\" can hold.: %d\n", UCHAR_MAX);
    printf("Minimum value a \"signed short int\" can hold.: %d\n", SHRT_MIN);
    printf("Maximum value a \"signed short int\" can hold.: %d\n", SHRT_MAX);
    printf("Maximum value an \"unsigned short int\" can hold.: %d\n", USHRT_MAX);
    printf("Minimum value a \"signed int\" can hold.: %d\n", INT_MIN);
    printf("Maximum value a \"signed int\" can hold.: %d\n", INT_MAX);
    printf("Maximum value an \"unsigned int\" can hold.: %u\n", UINT_MAX);

    return 0;
}
