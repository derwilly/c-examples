/* Ferdinand Saufler <mail@saufler.de>
 * 16.03.2015
 *
 * this programs forces a buffer overflow
 * - the compiler should give you a warning:
 *   "... will always overflow destination buffer"
 * - still run the example and see what happens
 * - use valgrind (make valgrind)
 * - why does this happen?
 *
 * man strcpy:
 * "The  strcpy()  function  copies the string pointed to by src, including
 * the terminating null byte ('\0'), to the buffer  pointed  to  by  dest.
 * The  strings  may  not overlap, and the destination string dest must be
 * large enough to receive the copy.  Beware  of  buffer  overruns!"
 *
 * countermeasure:
 * use safe equivalent functions, which check the buffers length:
 * gets() -> fgets()
 * scanf("%s",str) -> scanf("%10s",str);
 * strcpy() -> strncpy()
 * strcat() -> strncat()
 * sprintf() -> snprintf()
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    char *str = "abcdefghijklm";
    char buf[10];

    /* kapow */
    strcpy(buf, str);
    
    printf("%s",buf);

    return 0;
}
