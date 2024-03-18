#include "../philosophers.h"

int	error(char *str)
{
	printf("%s", str);
	return (1);
}

int	is_number(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == 43)
	{
		str++;
	}
	while (*str && *str > 47 && *str < 58)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

// void	insert_arg(t_info *info, char **argv)	// GUARDANDO CASO SEJA NECESSARIO DIMINUIR A FUNCAO alloc_memory
// {
// 	info->n = ft_atoi(argv[1]);
// 	info->die = ft_atoi(argv[2]);
// 	info->eat = ft_atoi(argv[3]);
// 	info->slept = ft_atoi(argv[4]);
//	if (argv[5])
//		info->repetitions = ft_atoi(argv[5]);
//	else
//		info->repetitions = 0;
//	gettimeofday(&info->time, NULL);
// }

// void	init_philo_fork(t_info *info)	// GUARDANDO CASO SEJA NECESSARIO DIMINUIR A FUNCAO alloc_memory
// {
// 	int	i;

// 	i = 0;
// 	while (i < info->n)
// 	{
// 		info->philo[i].philo = i + 1;
//		info->philo[i].dead = 0;
// 		info->forks[i].fork = i + 1;
// 		pthread_mutex_init(&info->forks[i].lock, NULL);
// 		i++;
// 	}
// }

int	init_info(t_info *info, char **argv)
{
	int	i;

	info->n = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]) * 1000;
	info->eat = ft_atoi(argv[3]) * 1000;
	info->slept = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		info->repetitions = ft_atoi(argv[5]);
	else
		info->repetitions = 0;
	gettimeofday(&info->time, NULL);
	// insert_arg(info, argv);	// GUARDANDO CASO SEJA NECESSARIO DIMINUIR A FUNCAO init_info()

	info->philo = malloc((info->n + 1) * sizeof(t_philo));
	info->forks = malloc((info->n + 1) * sizeof(t_fork));
	if (!info->forks || !info->philo)
		return (error("Error\nmemoria nao alocada para os garfos ou filosofos\n"));

	i = 0;
	while (i < info->n)
	{
		// info->philo[i].philo = i + 1;	// SERIO Q EU TENTEI SALVAR O VALOR DE i EM UMA VARIAVEL Q EU DEPÉNDO DE i PRA SABER A POSICAO DO ARRAY PRA ACESSAR?
		info->philo[i].dead = 0;
		info->philo[i].actions = 0;
		// info->philo[i].time_die = ;
		// info->philo[i].time_eat = ;
		// info->philo[i].time_sleep = ;
		info->forks[i].fork = i + 1;
		// info->philo[i].left = NULL;	// ACHEI Q IA PRECISAR SALVAR O PONTEIRO
		// info->philo[i].right = NULL;	// ACHEI Q IA PRECISAR SALVAR O PONTEIRO
		info->philo[i].time_eat = info->time;
		// info->forks[i].available = 1;
		pthread_mutex_init(&info->forks[i].lock, NULL);
		i++;
	}
	// init_philo_fork(info);	// GUARDANDO CASO SEJA NECESSARIO DIMINUIR A FUNCAO init_info()

	return (0);
}

int	milliseconds(t_info *info)
{
	struct timeval	current_time;
	int				seconds;
	int				microseconds;

	gettimeofday(&current_time, NULL);
	seconds = (current_time.tv_sec - info->time.tv_sec) * 1000;
	microseconds = (current_time.tv_usec - info->time.tv_usec) / 1000;
	return (seconds + microseconds);
}

// void	init_mutex(t_info *info)	// JA TA INICIANDO NA FUNCAO init_info()
// {
// 	int	i;

// 	i = 0;
// 	while (i < info->n)
// 	{
// 		pthread_mutex_init(&info->forks[i].lock, NULL);
// 		i++;
// 	}
// }

void	destroy_mutex(t_info *info)
{
	int	i;
	
	i = 0;
	while (i < info->n)
	{
		pthread_mutex_destroy(&info->forks[i].lock);
		i++;
	}
}