/* linear search example */

#include <stdio.h>

#define SIZE 1000

int main(int argc, char **argv)
{
    int arr[SIZE] = {0}, i, check, search;

    for(i = 0; i<=SIZE;i++)
    {
        arr[i] = i;
    }

    printf("enter a number between 0 and 1000 to search for: ");
    check = scanf("%d", &search);


    if(search > 1000 || check < 1)
    {
        printf("error, input has to be <= 1000!");
    }
    else
    {
        for(i = 0; i<=SIZE;i++)
        {
            if(search == arr[i])
            {
                printf("found your number at position %d\n",i);
                break;
            }
        }
    }

    return 0;
}
