/* Ferdinand Saufler <mail@saufler.de>
 * 09.03.2015
 * this program prints the timezone if defined in /etc/timezone */

#include <stdio.h>
#include <stdlib.h>
#include <file.h>

#define BUFLEN 256

int main()
{
    char timezone[BUFLEN];
    char *filename = "/etc/timezone";
    FILE *f;

    if(file_exists(filename) == 0)
    {
        f = fopen(filename,"r");

        if(f == NULL)
        {
            printf("file does not exists! (%s)\n", filename);
            exit(1);
        }

        if(fgets(timezone, BUFLEN, f) != NULL)
        {
            printf("%s",timezone);
        }

        fclose(f);
    }
    else
    {
        printf("%s doesnt exists.\n",filename);
    }

    return 0;
}
