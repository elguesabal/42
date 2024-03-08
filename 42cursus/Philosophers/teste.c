#include <stdio.h>
// #include <iostream>
#include <pthread.h>
// #include <process.h>
#include <unistd.h>


// //	pthread_create() pthread_join() pthread_exit()

// void	*funcao(void *param)
// {
// 	printf("aaa\n");
// 	sleep(3);
// 	pthread_exit(0); // ESSA FUNCAO E PROIBIDA
// }

// int	main()
// {
// 	pthread_t	id;
// 	int			rc;

// 	pthread_create(&id, NULL, funcao, NULL);
// 	rc = (int)pthread_join(id, NULL);
// 	printf("teste: %d\n", rc);
// 	return (0);
// }




// //	pthread_detach()

// void	*funcao(void *param)
// {
// 	printf("Nova thread iniciada\n");
// 	sleep(3);
// 	printf("Nova thread concluida\n");
// 	return NULL;
// }

// int	main()
// {
// 	pthread_t	id;
// 	int	n = 90;

// 	pthread_create(&id, NULL, funcao, &n);	

// 	pthread_detach(id);

// 	printf("Thread principal continuando...\n");
// 	sleep(5);
// 	printf("Thread principal concluida\n");

// 	return (0);
// }




// //	pthread_mutex_init() pthread_mutex_destroy()

// pthread_mutex_t	mutex;

// int	main()
// {
// 	pthread_mutex_init(&mutex, NULL);

// 	// ...

// 	pthread_mutex_destroy(&mutex);

// 	return (0);
// }




// //	pthread_self() pthread_mutex_lock() pthread_mutex_unlock()

pthread_mutex_t	lock;

void	*funcao(void *param)
{
	int *n = (int *)param;
	int	temp;

	printf("thread: %ld\n", pthread_self());

	// int	i = 0;
	// while (i < 100000)
	// {
	// 	temp = *n;
	// 	temp++;
	// 	*n = temp;
	// 	i++;
	// }

	// int	i = 0;
	// while (i < 100000)
	// {
	// 	pthread_mutex_lock(&lock);
	// 	temp = *n;
	// 	temp++;
	// 	*n = temp;
	// 	pthread_mutex_unlock(&lock);
	// 	i++;
	// }

	// temp = *n;
	// sleep(2);
	// temp++;
	// *n = temp;
	
	pthread_mutex_lock(&lock);
	temp = *n;
	sleep(2);
	temp++;
	*n = temp;
	pthread_mutex_unlock(&lock);

	pthread_exit(0);
}

int	main()
{
	pthread_t id1, id2;
	int	n = 0;

	pthread_create(&id1, NULL, funcao, &n);
	pthread_create(&id2, NULL, funcao, &n);

	// printf("thread 1 return: %d\n", (int)pthread_join(id1, NULL));
	// printf("thread 2 return: %d\n", (int)pthread_join(id2, NULL));

	pthread_mutex_init(&lock, NULL);

	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

	pthread_mutex_destroy(&lock);

	printf("n: %d\n", n);
}