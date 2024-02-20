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
				perror("Error\nMapa contem mais elementos que o necessário");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

// int	count_components()
// {

// }

// int	rectangular_map()
// {

// }

// int	wall_on_the_sides()
// {

// }

// int	valid_path()
// {

// }