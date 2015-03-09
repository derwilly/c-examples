/* count how often a char appears in a string */

#include <stdio.h>
#include <string.h>
#include <str.h>

int main(int argc, char *argv[])
{
    char *sentence = "the brown fox jumps over the lazy dog";
    int count = count_char(sentence, 'o');
    printf("\"o\" appears %d times in \"%s\".\n",count,sentence);

    return 0;
}
