/* check if a directory exists */

#include <stdio.h>
#include <file.h>

int main(int argc, char *argv[])
{
    const char *path = "/home";
    const char *path2 = "/home/me";

    if(directory_exists(path) == 0)
    {
        printf("%s directory exists.\n", path);
    }
    else
    {
        printf("cant find the directory %s.\n", path);
    }

    if(directory_exists(path2) == 0)
    {
        printf("%s directory exists.\n", path2);
    }
    else
    {
        printf("cant find the directory %s.\n", path2);
    }

    return 0;
}
