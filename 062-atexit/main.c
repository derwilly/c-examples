/* Ferdinand Saufler <mail@saufler.de>
 * 01.03.2015
 * atexit() example */

#include <stdio.h>
#include <stdlib.h>

void bye()
{
    printf("bye :)\n");
}

int main()
{
    atexit(bye);
    return 0;
}
