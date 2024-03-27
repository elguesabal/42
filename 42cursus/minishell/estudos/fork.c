#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();

	if (pid == -1)
		printf("Erro\n");
	else if (pid == 0)
		printf("teste 1 Processo filho: %d\n", getpid());
	else if (pid > 0)
	{
		printf("teste 2 Processo pai: %d\n", getpid());
		printf("teste 3 Processo filho: %d\n", pid);
	}

	return (0);
}