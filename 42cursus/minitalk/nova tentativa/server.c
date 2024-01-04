#include "minitalk.h"

void    store_signal(int signum)
{

}

int	main(void)
{
    signal(SIGUSR1, store_signal);
    signal(SIGUSR2, store_signal);

    printf("PID: %d\n", getpid());
    while(1)
        sleep(1);
	return (0);
}