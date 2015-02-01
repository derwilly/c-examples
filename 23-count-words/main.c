/* count words in a sentence */

#include <stdio.h>
#include <file.h>

int main(int argc, char *argv[])
{
    const char *sentence = "the brown fox jumps over the lazy dog";
    int words = count_words(sentence);

    printf("the sentence:\n");
    printf("%s\n", sentence);
    printf("has %d words.\n", words);

    return 0;
}
