/* Ferdinand Saufler <mail@saufler.de>
 * 09.03.2015
 * mkdir example
 * man 2 mkdir */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    char *dir = "test-dir";

    /* try to create a directory with read/write/search permissions
     * for owner and group, and with read/search permissions for others. */
    if(mkdir(dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0)
    {
        printf("something went wrong with mkdir().\n");
        printf("error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("successfully created directory \"%s\"\n",dir);
    }

    return EXIT_SUCCESS;
}
