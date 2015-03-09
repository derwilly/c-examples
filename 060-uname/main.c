/* Ferdinand Saufler <mail@saufler.de>
 * 09.03.2015
 * uname - man 2 uname
 * get name and information about current kernel */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/utsname.h>

int main()
{
    struct utsname buf;

    if(uname(&buf) != 0)
    {
        printf("something went wrong with uname().\n");
        printf("error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("sysname: %s\n",buf.sysname);
        printf("nodename: %s\n",buf.nodename);
        printf("release: %s\n",buf.release);
        printf("version: %s\n",buf.version);
        printf("machine: %s\n",buf.machine);
        #ifdef _GNU_SOURCE
            printf("domain-name = %s\n", buf.domainname);
        #endif
    }

    return EXIT_SUCCESS;
}
