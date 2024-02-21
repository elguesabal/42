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
			{
				perror("Error\nMapa contem mais elementos inesistentes");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	count_components(void)
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
				protagonist++;
			else if (MAP[j][i] == 'E')
				exit++;
			i++;
		}
		j++;
	}
	if (!coin || protagonist != 1 || exit != 1)
		perror("Error\nExistem mais de uma saida, protagonista ou nao existem coins");
	return (!coin || protagonist != 1 || exit != 1);
}

int	rectangular_map(void)
{
	int	j;
	int	i;
	int	aux_j;
	int	aux_i;

	// VERIFICA NA VERTICAL
	aux_j = 0;
	while (MAP[aux_j][0])
		aux_j++;
	j = 0;
	i = 0;
	while (MAP[j][i])
	{
		while (MAP[j][i])
			j++;
		if (aux_j != j)
		{
			perror("Error\nMapa nao retangular na vertical");
			return (1);
		}
		j = 0;
		i++;
	}

	// VERIFICA NA HORIZONTAL
	aux_i = 0;
	while (MAP[0][aux_i])
		aux_i++;
	j = 0;
	i = 0;
	while (MAP[j][i])
	{
		while (MAP[j][i])
			i++;
		if (aux_i != i)
		{
			perror("Error\nMapa nao retangular na horizontal");
			return (1);
		}
		i = 0;
		j++;
	}

	return (0);
}

int	wall_on_the_sides()
{
	int	j;
	int	i;

	while ()
	{
		while ()
		{
			
		}
	}
}

// int	valid_path()
// {

// }