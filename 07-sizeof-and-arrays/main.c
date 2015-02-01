/* sizeof() */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int iarray[] = {1, 2, 3, 4};
    char fname[] = "Ferdl";
    char fname_array[] = {'F','e','r','d','i','n','a','n','d','\0'};

    printf("the size of an int is %lu bytes\n", sizeof(int));
    printf("the size of iarray is %ld bytes\n",sizeof(iarray));
    printf("the number of ints in iarray is %ld\n",sizeof(iarray)/sizeof(int));

    printf("the size of a char is %ld bytes\n", sizeof(char));
    printf("the size of fname is %ld bytes\n",sizeof(fname));
    printf("the number of chars in fname is %ld\n",
           sizeof(fname)/sizeof(char));

    printf("the size of fname_array is %ld bytes\n",sizeof(fname_array));
    printf("the number of chars in fname_array is %ld\n",
           sizeof(fname_array)/sizeof(char));

    return 0;
}
