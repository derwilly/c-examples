/* uname */

#include <stdio.h>
#include <sys/utsname.h>

int main()
{
    struct utsname buf;

	if(uname(&buf) == 0)
	{
		printf("%s\n", buf.sysname);
		printf("%s\n", buf.nodename);
		printf("%s\n", buf.release);
		printf("%s\n", buf.version);
		printf("%s\n", buf.machine);
	}
	else
	{
	    printf("error at uname.\n");
	}

	return 0;
}
