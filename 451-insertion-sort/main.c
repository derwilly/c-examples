/* Ferdinand Saufler <mail@saufler.de>
 * 02.03.2015
 * this program sorts an array of integers with the insertion sort algorithm */

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int elements)
{
    int index, pos, pos_value;

    /* iterate from left-1 to right */
    for(index=1; index<=elements; index++)
    {
        /* save the current position */
        pos_value = arr[index];

        /* search for a minor value than pos_value is */
        for(pos=index; arr[pos-1] > pos_value && pos > 0; pos--)
        {
            /* if the predecessor is greater than the current element */
            arr[pos] = arr[pos-1];
        }
        /* write the saved element to the new position */
        arr[pos] = pos_value;
    }
}


int main()
{
    int i;
    int array[] = {9,4,3,7,6,8,5,1,2};

    insertion_sort(array, sizeof(array)/sizeof(int));

    for(i=1; i <= sizeof(array)/sizeof(int); i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    
    return 0;
}
