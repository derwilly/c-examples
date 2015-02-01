/* Ferdinand Saufler
 * 27.05.2014
 *
 * pointer to an int array
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    int numbers[5];
    int *p;

    // first element [0]
    p = numbers;
    *p = 10;

    // secound element [1]
    p++;
    *p = 20;

    // third element [2]
    p = &numbers[2];
    *p = 30;

    // 4. element [3]
    p = numbers + 3;
    *p = 40;

    // 5. element [4]
    p = numbers;
    *(p+4) = 50;

    int n;
    for(n=0;n<5; n++)
        printf("%d ", numbers[n]);

    printf("\n");

	return 0;
}
