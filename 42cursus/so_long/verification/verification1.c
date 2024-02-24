/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:27:18 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/23 11:57:26 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_components(void)
{
	int	j;
	int	i;

	j = 0;
	while (MAP[j][0])
	{
		i = 0;
		while (MAP[j][i])
		{
			if (MAP[j][i] != '0' && MAP[j][i] != '1' && MAP[j][i] != 'C' && MAP[j][i] != 'E' && MAP[j][i] != 'P')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	count_components(components *position)
{
	int	j;
	int	i;
	int	exit;
	int	coin;
	int	protagonist;

	coin = 0;
	protagonist = 0;
	exit = 0;
	j = 0;
	while (MAP[j][0])
	{
		i = 0;
		while (MAP[j][i])
		{
			if (MAP[j][i] == 'C')
				coin++;
			else if (MAP[j][i] == 'P')
			{
				position->protagonist.j = j;
				position->protagonist.i = i;
				protagonist++;
			}
			else if (MAP[j][i] == 'E')
				exit++;
			i++;
		}
		j++;
	}
	N_COIN = coin;
	N_EXIT = exit;
	return (!coin || protagonist != 1 || exit != 1);
}

int	rectangular_map(void)
{
	int	j;
	int	i;
	int	aux_j;
	int	aux_i;

	aux_j = 0; // VERIFICA NA VERTICAL
	while (MAP[aux_j][0])
		aux_j++;
	j = 0;
	i = 0;
	while (MAP[j][i])
	{
		while (MAP[j][i])
			j++;
		if (aux_j != j)
			return (1);
		j = 0;
		i++;
	}
	aux_i = 0; // VERIFICA NA HORIZONTAL
	while (MAP[0][aux_i])
		aux_i++;
	j = 0;
	i = 0;
	while (MAP[j][i])
	{
		while (MAP[j][i])
			i++;
		if (aux_i != i)
			return (1);
		i = 0;
		j++;
	}
	return (0);
}

int	wall_on_the_sides(void)
{
	int	j;
	int	i;

	// VEIFICA A PRIMEIRA LINHA DO MAPA
	i = 0;
	while (MAP[0][i])
	{
		if (MAP[0][i] != '1')
			return (1);
		i++;
	}

	// VERIFICA A ULTIMA COLUNA DO MAPA
	i--;
	j = 0;
	while (MAP[j][i])
	{
		if (MAP[j][i] != '1')
			return (1);
		j++;
	}

	// VERIFICA A PRIMEIRA COLUNA DO MAPA
	j = 0;
	while (MAP[j][0])
	{
		if (MAP[j][0] != '1')
			return (1);
		j++;
	}

	// VERIFICA A ULTIMA LINHA DO MAPA
	j--;
	i = 0;
	while (MAP[j][i])
	{
		if (MAP[j][i] != '1')
			return (1);
		i++;
	}

	return (0);
}
