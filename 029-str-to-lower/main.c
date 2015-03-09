/* string to_lower */

#include <stdio.h>
#include <str.h>

int main(int argc, char *argv[])
{
    char str[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    printf("the string before conversion:\n%s\n",str);
    to_lower(str);
    printf("the string after conversion:\n%s\n",str);

    return 0;
}
