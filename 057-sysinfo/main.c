/* sysinfo */

#include <stdio.h>
#include <sys/sysinfo.h>

int main()
{
    struct sysinfo buf;

	if(sysinfo(&buf) == 0)
	{
	    printf("uptime: %lu\n",buf.uptime);       /* Seconds since boot */
		printf("load  1min: %lu\n",buf.loads[0]); /* 1, 5, and 15 minute load averages */
		printf("load  5min: %lu\n",buf.loads[1]);
		printf("load 15min: %lu\n",buf.loads[2]);
		printf("totalram: %lu\n",buf.totalram);   /* Total usable main memory size */
		printf("freeram: %lu\n",buf.freeram);     /* Available memory size */
		printf("sharedram: %lu\n",buf.sharedram); /* Amount of shared memory */
		printf("bufferram: %lu\n",buf.bufferram); /* Memory used by buffers */
		printf("totalswap: %lu\n",buf.totalswap); /* Total swap space size */
		printf("freeswap: %lu\n",buf.freeswap);   /* swap space still available */
		printf("procs: %d\n",buf.procs);          /* Number of current processes */
		printf("totalhigh: %lu\n",buf.totalhigh); /* Total high memory size */
		printf("freehigh: %lu\n",buf.freehigh);   /* Available high memory size */
		printf("mem_unit: %d\n",buf.mem_unit);    /* Memory unit size in bytes */
	}
	else
	{
	    printf("error at sysinfo().");
	}

	return 0;
}
