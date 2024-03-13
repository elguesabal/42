/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:48:59 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/12 16:28:25 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
#include <sys/time.h>

# include <stdlib.h> // TIRAR DPS


typedef struct s_fork
{
	int				fork;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philo
{
	// int				philo;	// SERIO Q EU TENTEI SALVAR O VALOR DE i EM UMA VARIAVEL Q EU DEPÉNDO DE i PRA SABER A POSICAO DO ARRAY PRA ACESSAR?
	int				dead;
	pthread_t		id;
	t_fork			*left;
	t_fork			*right;
}	t_philo;

typedef struct s_info
{
	int					n;
	int					die;
	int					eat;
	int					slept;
	int					repetitions;
	struct timeval		time;
	t_philo				*philo;
	t_fork				*forks;
}	t_info;


// func_aux/utils1.c
int		error(char *str);
int		is_number(char *str);
int		ft_atoi(const char *str);
// void	insert_arg(t_info *info, char **argv);
// void	init_philo_fork(t_info *info);
int		init_info(t_info *info, char **argv);
int		milliseconds(t_info *info);
void	init_mutex(t_info *info);
void	destroy_mutex(t_info *info);

// func_aux/verification.c
int	verification(int argc, char **argv);


#endif