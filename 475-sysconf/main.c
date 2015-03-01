/* Ferdinand Saufler <mail@saufler.de>
 * 01.03.2015
 * sysconf - man sysconf */

#include <stdio.h>
#include <unistd.h>

int main()
{

    printf("maximum lenth of arguments: %ld\n",sysconf(_SC_ARG_MAX));       /* Seconds since boot */
    printf("number of simultaneous processes per user ID: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("maximum lenth of hostname: %ld\n", sysconf(_SC_HOST_NAME_MAX));
    printf("maximum lenth of a login-name: %ld\n", sysconf(_SC_LOGIN_NAME_MAX));
    printf("number of clock ticks per secound: %ld\n", sysconf(_SC_CLK_TCK)); 
    return 0;
}
