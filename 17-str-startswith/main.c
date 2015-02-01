/* Ferdinand Saufler
 * 21.11.2014
 */

#include <stdio.h>
#include <str.h>

int main(int argc, char *argv[])
{
    char *sentence = "the brown fox jumps over the lazy dog";
    char *pattern = "the";

    if(starts_with(pattern, sentence) == 0)
    {
        printf("the sentence \"%s\" starts with \"%s\".\n",sentence,pattern);
    }
    return 0;
}
