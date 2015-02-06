/* this program initialize 2 int arrays in reversed order
 * and order them using the bubble sort algorithm
 * compare the time with "parallel-bubblesort"
 *
 * the image "serial.png" shows that every time 1 cpu is active
 *
 * on my machine (quad-core), sorting tooks ~17 secounds for MAX=100000
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ctime.h"

#define MAX 100000

int arr1[MAX];
int arr2[MAX];

void init_array(int *array)
{
    int i, j;
    for(i = MAX,j=0; i >= 0; i--,j++)
    {
        array[j] = i;
    }
}

void bubble(int *array)
{
    int i, temp, elemente=MAX;
    while(elemente > 0)
    {
        elemente--;
        for(i = 1; i <= elemente; i++)
        {
            if(array[i-1] > array[i])
            {
                temp=array[i];
                array[i]=array[i-1];
                array[i-1]=temp;
            }
        }
    }
}

int main (void) {

    const int buflen = 80;
    char t_start[buflen];
    char t_stop[buflen];

    int ts_start;
    int ts_stop;

    /* initialize both arrays in revesed order */
    init_array(arr1);
    init_array(arr2);

    /* get start time */
    ts_start = (int)time(NULL);
    get_strtime(t_start, buflen , "%T");
    printf("start: %s (timestamp: %d)\n",t_start, ts_start);

    /* run the serial operation */
    bubble(arr1);
    bubble(arr2);

    /* get stop time */
    ts_stop = (int)time(NULL);
    get_strtime(t_stop, buflen , "%T");

    printf("stop : %s (timestamp: %d)\n",t_stop, ts_stop);

    /* print the timedif */
    printf("operation takes %d secounds.\n", ts_stop-ts_start);

    //int i;
    //for(i = 0; i < MAX; i++)
    //    printf("[%d-%d]", arr1[i], arr2[i]);

    return EXIT_SUCCESS;
}
