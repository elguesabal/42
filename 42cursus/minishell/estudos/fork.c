#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// fork
// wait

// int	main(void)
// {
// 	pid_t	pid;

// 	pid = fork();

// 	if (pid == -1)
// 		printf("Erro\n");
// 	else if (pid == 0)
// 		printf("teste 1 Processo filho: %d\n", getpid());
// 	else if (pid > 0)
// 	{
// 		// sleep(3);
// 		// while (1)
// 		// {}
// 		printf("teste 2 Processo pai: %d\n", getpid());
// 		printf("teste 3 Processo filho: %d\n", pid);
// 	}

// 	return (0);
// }





// int	main(void)	// NAO ENTENDI A FUNCAO wait()
// {
// 	pid_t	pid, child_pid;
// 	int		status;

// 	printf("processo pai %d\n\n", getpid());

// 	pid = fork();

// 	if (pid == -1)
// 		printf("Erro\n");
// 	else if (pid == 0)
// 	{
// 		child_pid = wait(&status);
// 		printf("child_pid %d\tstatus: %d\n", child_pid, status);
// 		printf("teste 1 Processo filho: %d\n", getpid());
// 	}
// 	else if (pid > 0)
// 	{
// 		// while (1)
// 		// {}
// 		sleep(3);
// 		printf("teste 2 Processo pai: %d\n", getpid());
// 		printf("teste 3 Processo filho: %d\n", pid);
// 	}

// 	return (0);
// }





int	main(void)	// ESTUDAR ESSE ASSUNTO NA 42 PQ NO MEU PC TA DANDO DIFERENCA
{
	pid_t	pid;

	pid = fork();

	if (pid == -1)
		printf("Erro\n");
	else if (pid == 0)
	{
		printf("teste 1 Processo filho: %d\n", getpid());
	}
	else if (pid > 0)
	{
		printf("teste 2 Processo pai: %d\n", getpid());
		printf("teste 3 Processo filho: %d\n", pid);
	}

	return (0);
}