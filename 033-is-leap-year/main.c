/* is the entered year a leap year? */

#include <stdio.h>
#include <check.h>

int main(int argc, char **argv)
{
    unsigned int y;

    printf("enter a year: ");
    int s = scanf("%d", &y);
    if(s > 0)
    {
        if (is_leapyear(&y) == 0 )
        printf("%d is a leap year!\n",y);
        else
        printf("%d is not a leap year!\n",y);
    }
    else
    {
        printf("error at scanf. \n");
    }

    return 0;
}
