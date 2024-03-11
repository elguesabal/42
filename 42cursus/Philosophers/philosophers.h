/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:48:59 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/11 19:58:43 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

# include <stdlib.h> // TIRAR DPS

typedef struct s_philo
{
	int				philo;
	int				dead;
	pthread_t		id;
	// pthread_mutex_t	lock;
	// int	time_die;
	// int	time_eat;
	// int	time_sleep;
}	t_philo;

typedef struct s_fork
{
	int				fork;
	// int				available;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_info
{
	int		n;
	int		die;
	int		eat;
	int		slept;
	int		repetitions;
	t_philo	*philo;
	t_fork	*forks;
}	t_info;


// func_aux/utils1.c
int	error(char *str);
int	is_number(char *str);
int	ft_atoi(const char *str);
// void	insert_arg(t_info *info, char **argv);
// void	init_philo_fork(t_info *info);
int	init_info(t_info *info, char **argv);

// func_aux/verification.c
int	verification(int argc, char **argv);


#endif