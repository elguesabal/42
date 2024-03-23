/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:48:59 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/21 14:42:45 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				dead;
	pthread_t		id;
	int				repetitions;
	int				actions;
	struct timeval	time_eat;
}	t_philo;

typedef struct s_info
{
	int					n;
	int					die;
	int					eat;
	int					slept;
	struct timeval		time;
	t_philo				*philo;
	pthread_mutex_t		*forks;
}	t_info;

typedef struct s_dead
{
	t_philo				*philo;
	int					*die;
}	t_dead;

// philosopher/philosopher.c
void    eat(t_info *info, int i);
void    to_sleep(t_info *info, int i);
void	think(t_info *info, int i);
void	*philosopher(void *param);
void	creat_philosopher(t_info *info);

// philosopher/assistant.c
void	*death_count(void *param);
int		dead_philosopher(t_info *info);
											// int	last_death(t_info *info, int list);
int		repetitions(t_info *info);
int		all_dead(t_info *info);
void    finish(t_info *info);

// func_aux/verification.c
int	verification(int argc, char **argv);

// func_aux/utils1.c
int		is_number(char *str);
int		ft_atoi(const char *str);
int		init_info(t_info *info, char **argv);
int		number(void);
int		milliseconds(t_info *info);

// func_aux/utils2.c
void	destroy_mutex(t_info *info);


#endif