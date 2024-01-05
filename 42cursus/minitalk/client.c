#include "minitalk.h"

int	main(int agrc, char *argv[])
{
	int	i;

	i = 0;
	while (argv[2][i])
	{
		i++;
	}
	str_client = malloc(i * sizeof(char));
	i = 0;
	while (argv[2][i])
	{
		str_client[i] = argv[2][i];
		i++;
	}
	printf("%p", str_client);
	kill(atoi(argv[1]), SIGUSR1);
}