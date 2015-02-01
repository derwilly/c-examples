/* sigterm example */

#include <stdio.h>
#include <signal.h>

void sig_handler(int signal)
{
    printf("Received signal %d\n", signal);
}

int main()
{
    // register a signal handler.
    signal(SIGTERM, sig_handler);

    printf("sending signal %d\n", SIGTERM);
    raise(SIGTERM);
    printf("exiting...\n");
    return 0;
}
