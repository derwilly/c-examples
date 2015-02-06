/* this program initialize 2 int arrays in reversed order
 * and order them using the bubble sort algorithm
 * sorting uses 2 threads that run in parallel. compare the result
 * to "serial-bubblesort".
 *
 * the image "parallel.png" shows that every time 2 cpus are active
 *
 * on my machine (quad-core), sorting tooks ~5-7 secounds for MAX=100000
 * thats a huge improvement compared to the serial solution.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
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

void *bubble(void* arr)
{
    char *array = (char*)arr;
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
    return NULL;
}

int main (void) {

    const int buflen = 80;
    char t_start[buflen];
    char t_stop[buflen];

    int ts_start;
    int ts_stop;

    int rc;
    pthread_t t1, t2;

    /* initialize both arrays in revesed order */
    init_array(arr1);
    init_array(arr2);

    /* get start time */
    ts_start = (int)time(NULL);
    get_strtime(t_start, buflen , "%T");
    printf("start: %s (timestamp: %d)\n",t_start, ts_start);

    /* create thread one */
    rc = pthread_create(&t1, NULL, bubble, (void*)arr1);
    if( rc != 0 ) {
        printf("cant create thread 1\n");
        return EXIT_FAILURE;
    }

    /* create thread two */
    rc = pthread_create(&t2, NULL, bubble, (void*)arr2);
    if( rc != 0 ) {
        printf("cant create thread 2\n");
        return EXIT_FAILURE;
    }

    /* wait until the 2 threads have finished. */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

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
