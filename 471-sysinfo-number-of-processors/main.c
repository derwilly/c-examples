/* Ferdinand Saufler <mail@saufler.de>
 * 01.03.2015
 * sysinfo - number of processors
 * man 3 get_nprocs */

#include <stdio.h>
#include <sys/sysinfo.h>

int main()
{
    printf("your system has %d processors. \n", get_nprocs());
	return 0;
}
