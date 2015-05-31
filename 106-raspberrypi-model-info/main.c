/* Ferdinand Saufler <mail@saufler.de>
 * 16.03.2015
 * this program checks /proc/cpuinfo to detect a PI1/PI2  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct raspberry {
    char ModelName[254];
    char Hardware[254];
    char Revision[5];
} Raspberry;

int main()
{
    char *filename = "/proc/cpuinfo";
    FILE *f;
    char line[254];

    /* open the file for reading */
    f = fopen(filename,"r");

    /* allocate memory for the config struct */
    Raspberry *info = malloc(sizeof(Raspberry));

    printf("loading values from %s:\n", filename);

    /* iterate over the lines, and scan its contents */
    while(fgets(line,sizeof(line),f) != NULL)
    {
        if(sscanf(line, "model name : %[^\t\n]", info->ModelName) == 1)
        {
            printf("Model: %s\n", info->ModelName);
            continue;
        }
        else if(sscanf(line, "Hardware : %s", info->Hardware) == 1)
        {
            printf("Hardware: %s\n", info->Hardware);
            continue;
        }
        else if(sscanf(line, "Revision : %s", info->Revision) == 1)
        {
            printf("Revision: %s\n", info->Revision);
            continue;
        }
    }

    if(strcmp(info->Hardware,"BCM2708") == 0)
    {
        printf("This is a Raspberry Pi 1.\n");
    }
    else if(strcmp(info->Hardware,"BCM2836") == 0)
    {
        printf("This is a Raspberry Pi 2.\n");
    }
    else
    {
        printf("Neither a Pi1 or a Pi2.\n");
    }

    /* close the file f */
    fclose(f);

    /* cleanup Memory */
    free(info);

    return 0;
}
