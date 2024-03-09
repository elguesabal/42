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
	int				n;
	// int				*fork_left;
	// int				*fork_right;
	int				*fork;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	struct s_philo	*next;
	struct s_philo	*previous;
}	t_philo;

typedef struct s_fork
{
	int				fork;
	int				n;
	struct s_fork	*next;
	struct s_fork	*previous;
}	t_fork;

typedef struct s_first
{
	int				n;
	struct t_philo	*philo;
	struct t_fork	*fork;
}	t_first;


// func_aux/utils1.c
int	ft_atoi(const char *str);


#endif