/* Ferdinand Saufler <mail@saufler.de>
 * 16.03.2015
 * this programs loads values from a config file */

#include <stdio.h>
#include <stdlib.h>
#include <file.h>

typedef struct Config {
    char dbHost[254];
    char dbDatabase[254];
    char dbUser[32];
    char dbPassword[32];
} Config;

int main()
{
    char *filename = "main.conf";
    FILE *f;
    char line[254];

    /* open the file for reading */
    f = fopen(filename,"r");

    /* allocate memory for the config struct */
    Config *config = malloc(sizeof(Config));

    printf("loading values from %s:\n", filename);

    /* iterate over the lines, and scan its contents */
    while(fgets(line,sizeof(line),f) != NULL)
    {
        if(sscanf(line, "DB_HOST=%s", config->dbHost) == 1)
        {
            printf("Host: %s\n", config->dbHost);
            continue;
        }
        else if(sscanf(line, "DB_DATABASE=%s", config->dbDatabase) == 1)
        {
            printf("Database: %s\n", config->dbDatabase);
            continue;
        }
        else if(sscanf(line, "DB_USER=%s", config->dbUser) == 1)
        {
            printf("User: %s\n", config->dbUser);
            continue;
        }
        else if(sscanf(line, "DB_PASSWORD=%s", config->dbPassword) == 1)
        {
            printf("Password: %s\n", config->dbPassword);
            continue;
        }
    }
    /* close the file f */
    fclose(f);

    /* cleanup Memory */
    free(config);

    return 0;
}
