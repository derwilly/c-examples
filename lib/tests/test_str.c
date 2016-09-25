#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <str.h>

void test_str()
{
    /* sizeof */
    printf("sizeof size_t = %lu\n",sizeof(size_t));

    /* starts_with() */
    char *a = "the brown fox jumps over the lazy dog";
    char *pattern = "the";
    if (starts_with(pattern, a) == 0)
    {
        printf("a starts with \"%s\"\n",pattern);
    }

    /* to upper */
    char binks[] = "Jar Jar Binks";
    printf("%s to upper is ",binks);
    to_upper(binks);
    printf("%s\n",binks);

    /* to lower */
    char c3po[] = "C-3PO";
    printf("%s to lower is ",c3po);
    to_lower(c3po);
    printf("%s\n",c3po);

    /* print_bits() */
    uint32_t reg = 0xA711CFFF;
    print_bits(reg);

    /* remove_blanks() */
    char *b = "the  brown fox    jumps over  the    lazy dog";
    char *nobl = remove_blanks(b);
    if(nobl == NULL)
        printf("nulli nulli\n");
    printf("%s\n",nobl);
    free(nobl);

    /* remove_newline() */
    char c[] = "the brown fox jumps over the lazy dog\n";
    remove_newline(c);
    int i;
    int found_newline = 0;
    for(i=0;i<=strlen(c);i++)
    {
        if(c[i]=='\n')
            found_newline = 1;
    }

    if(found_newline == 1)
    {
        printf("found a newline in c, remove_newline fails.\n");
    }
    else
    {
        printf("cant find newline in c, remove_newline succeeds.\n");
    }

    /* count_char() */
    char d[] = "Powerful you have become, the dark side i sense in you.";
    int count_e = count_char(d,'e');
    printf("\"e\" appears %d times in \"%s\"\n",count_e,d);

    /* count_words() */
    unsigned long wc = count_words(a);
    printf("a has %lu words.\n",wc);
    wc = count_words(NULL);
    printf("NULL has %lu words.\n",wc);

    /* strlength */
    unsigned long len = strlength(a);
    printf("strlength of \"%s\" is %lu\n",a,len);
}
