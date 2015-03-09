/* sigint example */

#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t signal_status;

void sig_handler(int signal)
{
    printf("Received signal %d\n", signal);
    signal_status = signal;
}

int main()
{
    /* register the signal handler */
    signal(SIGINT, sig_handler);

    printf("signal value: %d\n", signal_status);
    printf("sending signal: %d\n", SIGINT);
    raise(SIGINT);
    printf("signal value: %d\n", signal_status);

    return 0;
}
