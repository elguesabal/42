/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:27:18 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 10:43:09 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_components(void)
{
	int	j;
	int	i;

	j = 0;
	while (g_map[j][0])
	{
		i = 0;
		while (g_map[j][i])
		{
			if (g_map[j][i] != '0' && g_map[j][i] != '1' && g_map[j][i] != 'C'
				&& g_map[j][i] != 'E' && g_map[j][i] != 'P')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	count(int *c, j_i *position, int *p, int *e)
{
	int	j;
	int	i;

	j = 0;
	while (g_map[j][0])
	{
		i = 0;
		while (g_map[j][i])
		{
			if (g_map[j][i] == 'C')
				(*c)++;
			else if (g_map[j][i] == 'P')
			{
				position->j = j;
				position->i = i;
				(*p)++;
			}
			else if (g_map[j][i] == 'E')
				(*e)++;
			i++;
		}
		j++;
	}
}

int	count_components(components *position)
{
	int	e;
	int	c;
	int	p;

	c = 0;
	p = 0;
	e = 0;
	count(&c, &position->p, &p, &e);
	g_n_c = c;
	g_n_e = e;
	return (!c || p != 1 || e != 1);
}

int	vertical_check(void)
{
	int	i;
	int	j;
	int	aux_j;

	aux_j = 0;
	while (g_map[aux_j][0])
		aux_j++;
	j = 0;
	i = 0;
	while (g_map[j][i])
	{
		while (g_map[j][i])
			j++;
		if (aux_j != j)
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

int	horizontal_check(void)
{
	int	i;
	int	j;
	int	aux_i;

	aux_i = 0;
	while (g_map[0][aux_i])
		aux_i++;
	j = 0;
	i = 0;
	while (g_map[j][i])
	{
		while (g_map[j][i])
			i++;
		if (aux_i != i)
			return (1);
		i = 0;
		j++;
	}
	return (0);
}
