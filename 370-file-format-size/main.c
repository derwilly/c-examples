/* print the formatted string (KB, MB, GB,..)
 * of an integer (filesize) */

#include <stdio.h>
#include <file.h>

#define buflen 24

int main(int argc, char *argv[])
{
    char buf[buflen];
    unsigned long file_size = 17234563;

    get_format_size(file_size, buf);
    printf("the file has a size of %s\n", buf);

    return 0;
}
