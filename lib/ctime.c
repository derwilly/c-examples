/* ctime.c
 * Ferdinand Saufler
 * 09.11.2014 */

#include <time.h>
#include "ctime.h"

/* get_strtime()
 * this functions writes the current date and time of a given
 * format to a buffer buf.
 * the function returns the number of bytes (excluding the terminating
 * null byte) placed in the array buf.  If the length of the result
 * string (including the terminating null byte) would exceed buflen,
 * then get_strtime() returns 0, and the contents of the array are undefined.*/
int get_strtime(char *buf, int buflen, const char* format)
{
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    return strftime(buf,buflen,format,timeinfo);
}
