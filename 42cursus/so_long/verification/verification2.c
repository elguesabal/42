#include "../so_long.h"

// VEIFICA A PRIMEIRA LINHA DO MAPA
int	first_line(int *i)
{
	*i = 0;
	while (MAP[0][*i])
	{
		if (MAP[0][*i] != '1')
			return (1);
		(*i)++;
	}
	return (0);
}

// VERIFICA A ULTIMA COLUNA DO MAPA
int	last_column(int *j, int *i)
{
	(*i)--;
	*j = 0;
	while (MAP[*j][*i])
	{
		if (MAP[*j][*i] != '1')
			return (1);
		(*j)++;
	}
	return (0);
}

// VERIFICA A PRIMEIRA COLUNA DO MAPA
int	first_column(int *j)
{
	*j = 0;
	while (MAP[*j][0])
	{
		if (MAP[*j][0] != '1')
			return (1);
		(*j)++;
	}
	return (0);
}

// VERIFICA A ULTIMA LINHA DO MAPA
int	last_line(int *j, int *i)
{
	(*j)--;
	*i = 0;
	while (MAP[*j][*i])
	{
		if (MAP[*j][*i] != '1')
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
