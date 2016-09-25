#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file.h>

void test_file()
{
    char buf[32];

    /* file_exists() */
    const char *file = "/proc/config.gz";
    if(file_exists(file) == 0)
        printf("file %s exists.\n",file);
    else
        printf("file %s doesnt exists.\n",file);

    /* directory_exists() */
    const char *dir = "/proc";
    if(directory_exists(dir) == 0)
        printf("directory %s exists.\n",dir);
    else
        printf("directory %s doesnt exists.\n",dir);

    /* get_filesize() */
    unsigned long sz = get_filesize(file);
    printf("the size of %s is %lu Bytes.\n",file,sz);

    /* get_format_size() */
    get_format_size(sz, buf);
    printf("%s has a formatted size of %s.\n",file,buf);
}
