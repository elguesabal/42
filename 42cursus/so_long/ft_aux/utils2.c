/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:32:47 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 17:55:40 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	size_j(void)
{
	int	count;

	count = 0;
	while (g_map[count][0])
		count++;
	return (count);
}

int	size_i(void)
{
	int	count;

	count = 0;
	while (g_map[0][count])
		count++;
	return (count);
}

int	error(char *str, int release)
{
	perror(str);
	if (release)
		free_map();
	return (1);
}

void	free_map(void)
{
	int	j;

	j = size_j();
	while (j != -1)
	{
		if (g_map && g_map[j])
			free(g_map[j]);
		if (g_copy_map && g_copy_map[j])
			free(g_copy_map[j]);
		j--;
	}
	if (g_map)
		free(g_map);
	if (g_copy_map)
		free(g_copy_map);
}
