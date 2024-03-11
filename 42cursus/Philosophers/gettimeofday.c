#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

int	main(void)
{
	struct timeval	teste;
	
	gettimeofday(&teste, NULL);

	printf("Tempo atual: %ld segundos, %ld microssegundos\n", teste.tv_sec, teste.tv_usec);
}






// pthread_mutex_t	lock;

// void	*funcao1(void *param)
// {
// 	pthread_mutex_lock(&lock);
// 	printf("lock da funcao\n");
// 	sleep(2);
// 	printf("unlock da funcao\n");
// 	pthread_mutex_unlock(&lock);
// }

// void	*funcao2(void *param)
// {
// 	struct timeval	time1, time2;
// 	long int		n;

// 	gettimeofday(&time1, NULL);

// 	pthread_mutex_lock(&lock);
// 	gettimeofday(&time2, NULL);
// 	if (time2.tv_sec - time1.tv_sec < 3)
// 		printf("deu tempo\n");
// 	else
// 		printf("nao deu tempo\n");
// 	pthread_mutex_unlock(&lock);
// }

// // void	*funcao3(void *param)
// // {
// // 	while (1)
// // 	{
// // 		printf("teste\n");
// // 		sleep(1);
// // 	}
// // }

// int	main(void)
// {
// 	pthread_t	id1, id2, id3;
// 	int			n;

// 	pthread_mutex_init(&lock, NULL);

// 	pthread_create(&id1, NULL, funcao1, &n);
// 	pthread_create(&id2, NULL, funcao2, &n);
// 	// pthread_create(&id3, NULL, funcao3, &n);

// 	pthread_join(id1, NULL);
// 	pthread_join(id2, NULL);
// 	// pthread_join(id3, NULL);

// 	pthread_mutex_destroy(&lock);

// 	return (0);
// }