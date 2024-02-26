/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:33:13 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 10:43:35 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	first_line(int *i)
{
	*i = 0;
	while (g_map[0][*i])
	{
		if (g_map[0][*i] != '1')
			return (1);
		(*i)++;
	}
	return (0);
}

int	last_column(int *j, int *i)
{
	(*i)--;
	*j = 0;
	while (g_map[*j][*i])
	{
		if (g_map[*j][*i] != '1')
			return (1);
		(*j)++;
	}
	return (0);
}

int	first_column(int *j)
{
	*j = 0;
	while (g_map[*j][0])
	{
		if (g_map[*j][0] != '1')
			return (1);
		(*j)++;
	}
	return (0);
}

int	last_line(int *j, int *i)
{
	(*j)--;
	*i = 0;
	while (g_map[*j][*i])
	{
		if (g_map[*j][*i] != '1')
			return (1);
		(*i)++;
	}
	return (0);
}

int	wall_on_the_sides(void)
{
	int	j;
	int	i;

	if (first_line(&i))
		return (1);
	if (last_column(&j, &i))
		return (1);
	if (first_column(&j))
		return (1);
	if (last_line(&j, &i))
		return (1);
	return (0);
}
