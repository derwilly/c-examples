/* is the entered number a palindrome?
 * examples: 11, 777, 1221, 12321 */

#include <stdio.h>
#include <check.h>

int main(int argc, char **argv)
{
    int number;

    printf("enter an integer: ");
    int s = scanf("%d", &number);
    if(s > 0)
    {
        if (is_prime(&number) == 0 )
        printf("%d is a prime!\n",number);
        else
        printf("%d is not a prime!\n",number);
    }
    else
    {
        printf("error at scanf. \n");
    }

    return 0;
}
