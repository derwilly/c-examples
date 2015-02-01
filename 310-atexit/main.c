/* atexit() example */

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
