/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:48:59 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/08 15:05:45 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>

# include <stdlib.h> // TIRAR DPS

typedef struct s_philo
{
	int	philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
}	t_philo;

typedef struct s_fork
{
	int				fork;
	int				available;
}	t_fork;

typedef struct s_info
{
	t_philo	*philo;
	t_fork	*forks;
	int		n;
}	t_info;


// func_aux/utils1.c
int	error(char *str);
int	is_number(char *str);
int	ft_atoi(const char *str);


#endif