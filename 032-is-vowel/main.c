/* vowel or not? */

#include <stdio.h>
#include <check.h>

int main(int argc, char **argv)
{
    char c;

    printf("enter a character: ");
    int s = scanf("%c",&c);
    if(s > 0)
    {
        if (is_vowel(&c) == 0 )
        printf("%c is a vowel!\n",c);
        else
        printf("%c is not a vowel!\n",c);
    }
    else
    {
        printf("error at scanf. \n");
    }

    return 0;
}
