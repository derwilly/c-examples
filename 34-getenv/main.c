/* getenv example */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *env = getenv("PATH");
    if (env == NULL)
    {
        printf("cant get \"PATH\" var...\n");
    }
    else
    {
        printf("PATH = %s\n", env);
    }

    return 0;
}
