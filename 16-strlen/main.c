/* Ferdinand Saufler
 * 10.11.2014
 *
 * strlen()
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    const char *sentence = "the brown fox jumps over the lazy dog";
    printf("\"%s\" has a lenth of %d characters.\n", sentence, (unsigned)strlen(sentence));

    return 0;
}
