#include <stdio.h>
// #include <iostream>
#include <pthread.h>
// #include <process.h>
#include <unistd.h>

// void	*funcao(void *param)
// {
// 	printf("aaa\n");
// 	sleep(3);
// 	pthread_exit(0);
// }

// int	main()
// {
// 	pthread_t	id1, id2;
// 	int			rc;

// 	pthread_create(&id1, NULL, funcao, NULL);
// 	// rc = (int)pthread_join(id, NULL);
// 	printf("testeeeeee\n");
// 	printf("teste: %d\n", (int)pthread_join(id1, NULL));
// 	return (0);
// }




void	*funcao(void *param)
{
	// sleep(1);
	// int *teste = (int *)param;
	// printf("teste: %d\n", *teste);
	// printf("teste:\n");

	while (1)
	{

	}
}

int	main()
{
	pthread_t id1, id2;
	int	n = 10;

	pthread_create(&id1, NULL, funcao, &n);
	pthread_create(&id2, NULL, funcao, &n);

	// printf("teste: %d\n", (int)pthread_join(id1, NULL));
	// printf("teste: %d\n", (int)pthread_join(id2, NULL));
	(int)pthread_join(id1, NULL);
	(int)pthread_join(id2, NULL);
}