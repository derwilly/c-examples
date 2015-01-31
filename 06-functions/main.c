/* Ferdinand Saufler
 * mail@saufler.de
 * 10.11.2014
 *
 * functions 1
 */

#include <stdio.h>
#include <string.h>

void print_string(const char *str)
{
    printf("%s\n", str);
}

int add(int i, int j)
{
    return i+j;
}

int main(int argc, char *argv[])
{
    const char *my_str = "the brown fox jumps over the lazy dog.";
    print_string(my_str);

    int i = 3, j = 4;
    printf("%d + %d = %d\n",i,j,add(i,j));

    return 0;
}
