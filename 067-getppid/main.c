/* getpid example */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int id;
    id = getpid();
    printf("this process has id %d\n", id);

    id = getppid();
    printf("the parent process has id %d\n", id);

    return 0;
}
