/* getpid example */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int pid;

    pid = getpid();
    printf("this process has id %d\n", pid);

    return 0;
}
