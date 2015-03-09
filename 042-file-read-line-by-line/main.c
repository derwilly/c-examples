/* Ferdinand Saufler <mail@saufler.de>
 * 02.03.2015
 * this program reads a file line by line and prints it to the stdin */

#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 256

int main()
{
    char line[BUFLEN];
    char *filename = "fox.txt";
    FILE *f;

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

    return 0;
}
