#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct
{
	int	comer;
	int	pensar;
	int	dormir;
}	t_tempo;

void	*acao(void *param)
{
	t_tempo		*tempo;
	static int	acoes;

	tempo = (t_tempo *)param;
	if (acoes == 0)
	{
		usleep(tempo->comer);
		printf("comeu em %d ms\n", tempo->comer / 1000);
		acoes++;
	}
	else if (acoes == 1)
	{
		usleep(tempo->pensar);
		printf("pensou em %d ms\n", tempo->pensar / 1000);
		acoes++;
	}
	else if (acoes == 2)
	{
		usleep(tempo->dormir);
		printf("dormiu em %d ms\n", tempo->dormir / 1000);
		acoes++;
	}

	if (acoes == 3)
		acoes = 0;
}

int	main(void)
{
	t_tempo		tempo;
	pthread_t	id;

	tempo.comer = 2000 * 1000;
	tempo.pensar = 1000 * 1000;
	tempo.dormir = 5000 * 1000;


	while (1)
	{
		pthread_create(&id, NULL, acao, &tempo);
		pthread_join(id, NULL);
	}


	return (0);
}