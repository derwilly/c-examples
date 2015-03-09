/* Ferdinand Saufler <mail@saufler.de>
 * 02.03.2015
 * this program prints the contents of /etc/lsb-release */

#include <stdio.h>
#include <stdlib.h>
#include <file.h>

#define BUFLEN 256

int main()
{
    char line[BUFLEN];
    char *filename = "/etc/lsb-release";
    FILE *f;

    if(file_exists(filename) == 0)
    {
        f = fopen(filename,"r");

        if(f == NULL)
        {
            printf("file does not exists! (%s)\n", filename);
            exit(1);
        }

        while(fgets(line, BUFLEN, f) != NULL)
        {
            printf("%s",line);
        }

        fclose(f);
    }
    else
    {
        printf("%s doesnt exists.\n",filename);
    }

    return 0;
}
