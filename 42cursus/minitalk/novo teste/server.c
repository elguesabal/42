#include "minitalk.h"

void	converter()
{

}

int	main(void)
{
	signal(SIGUSR1, converter);
	signal(SIGUSR2, converter);

	printf("PID: %d", getpid());

	while (1)
	{
		sleep(1);
	}
}