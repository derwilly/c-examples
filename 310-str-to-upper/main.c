/* string to_upper */

#include <stdio.h>
#include <str.h>

int main(int argc, char *argv[])
{
    char str[] = "The quick brown fox jumps over the lazy dog";
    printf("the string before conversion:\n%s\n",str);
    to_upper(str);
    printf("the string after conversion:\n%s\n",str);

    return 0;
}
