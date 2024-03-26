/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:19:12 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/26 08:32:04 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	destroy_mutex(t_info *info)
{
	int	i;

	usleep(info->die);
	i = 0;
	while (i < info->n)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
}
