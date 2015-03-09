/* remove unnecessary blanks from a string */

#include <stdio.h>
#include <stdlib.h>
#include <str.h>

int main(int argc, char *argv[])
{
    char text[] = "this    is   a  sentence. ";
    char *p;

    /* remove the unnecessary blanks in text */
    p = remove_blanks(text);

    printf("%s\n",p);

    /* dont forget to free the memory allocated from remove_blanks() */
    free(p);

    return 0;
}
