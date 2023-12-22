#include "minitalk.h"

void	save(int signum)
{
// printf("%d\n", signum);
	if (signum == 10)
		message[n_signal] = '0';
	else
		message[n_signal] = '1';
	n_signal++;
}

int	main(void)
{
	signal(SIGUSR1, save);
	signal(SIGUSR2, save);

	printf("PID: %d\n", getpid());
	while (1)
	{
		sleep(5);
printf("%s\n", message);
	}
}