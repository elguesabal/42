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
	int *teste = (int *)param;
	sleep(1);
	// printf("teste: %d\n", *teste);
	// printf("teste:\n");
	(*teste)++;
	pthread_exit(0);
}

int	main()
{
	pthread_t id1, id2;
	int	n1 = 1;
	int	n2 = 2;

	pthread_create(&id1, NULL, funcao, &n1);
	pthread_create(&id2, NULL, funcao, &n1);

	// printf("return: %d\n", (int)pthread_join(id1, NULL));
	// printf("return: %d\n", (int)pthread_join(id2, NULL));
	(int)pthread_join(id1, NULL);
	(int)pthread_join(id2, NULL);
	printf("n1: %d", n1);
}