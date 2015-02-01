/* check if a file exists */

#include <stdio.h>
#include <file.h>

int main(int argc, char *argv[])
{
    const char *path = "./main.c";

    if(file_exists(path) == 0)
    {
        printf("file exists!\n");
    }
    else
    {
        printf("file %s does not exist.\n", path);
    }

    return 0;
}
