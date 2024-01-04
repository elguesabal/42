#include "minitalk.h"

void	res(int signum)
{
	// str_server = malloc(4 * sizeof(char));

// for(int i = 0; i < 4; i++)
// {
// 	str_server[i] = 'p';
// }

	// printf("\n%s", str); BEM BUGADO SEM /n NO FINAL
	// printf("%s", str); BEM BUGADO SEM /n NO FINAL
	printf("teste:%p:teste\n", str_client);
	//free(str_client);
}

int	main(void)
{
	signal(SIGUSR1, res);

	// printf("PID: %d", getpid()); PQ TA BUGANDO SE NAO BOTAR /n NO FIM????
	printf("PID: %d\n", getpid());

	while (1)
	{
		sleep(1);
	}
}