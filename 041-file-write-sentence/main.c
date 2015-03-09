/* Ferdinand Saufler <mail@saufler.de>
 * 01.03.2015
 * this program reads one line from stdin and prints it to a file */

#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 256

int main()
{
    char c[BUFLEN];
    FILE *f;
    char *ret;

    f = fopen("out.txt","w+");
    
    if(f == NULL)
    {
        printf("an error occoured!");
        exit(1);
    }
    printf("Enter a sentence: \n");
    ret = fgets(c,BUFLEN,stdin);
    if(ret > 0)
    {
        fprintf(f,"%s",c);
    }
    fclose(f);

    return 0;
}
