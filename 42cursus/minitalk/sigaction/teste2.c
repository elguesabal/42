#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	teste()
{
	printf("TESTE\n");
}

int	main(void)
{
	struct	sigaction sa;
	sa.sa_handler = teste;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("PID: %d\n", getpid());

	while(1)
		pause();
	return (0);
}