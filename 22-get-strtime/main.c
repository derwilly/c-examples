/* print date and time in a given format. */

#include <stdio.h>
#include <ctime.h>

#define buflen 80

int main(int argc, char *argv[])
{
    char buf[buflen];

    int ret = get_strtime(buf, buflen , "%A, %d. %B %G %H:%M:%S");

    printf("return value of get_strtime: %d\n", ret);
    printf("current date and time: %s\n", buf);

    return 0;
}
