/* integer - odd or even? */

#include <stdio.h>
#include <check.h>

int main(int argc, char **argv)
{
    int n;

    printf("enter an integer: ");
    int s = scanf("%d",&n);
    if(s > 0)
    {
        if (is_odd(&n) == 0 )
        printf("%d is odd!\n",n);
        else
        printf("%d is even!\n",n);
    }
    else
    {
        printf("error at scanf. \n");
    }

    return 0;
}
