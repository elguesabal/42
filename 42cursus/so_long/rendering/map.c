#include "../so_long.h"

width_height	*read_map(char *file)
{
	width_height	*resolution;
	int				fd;
	char			c;
	int				i;
	int				j;

	resolution = malloc(sizeof(width_height));

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Erro\n");
		return (NULL);
	}

	// PASSAR O MAPA .ber PARA MATRIZ
	i = 0;
	j = 0;
	while (read(fd, &c, 1))
	{
		if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		{
			MAP[j][i] = c;
			i++;
		}
		else if (c == '\n')
		{
			MAP[j][i] = '\0';
			i = 0;
			j++;
		}
	}
	MAP[j + 1][0] = '\0';
	close(fd);
	resolution->height = ft_strlen(MAP[0]);
	resolution->width = j + 1;
	return (resolution);
}

// DESENHAR O MAPA COM A MATRIZ
void	render_map(components *position)
{
	int	i;
	int	j;

	j = 0;
	while (MAP[j][0])
	{
		i = 0;
		while (MAP[j][i])
		{
			if (MAP[j][i] == '0')
			{
			}
			else if (MAP[j][i] == '1')
				render_map_wall(j, i, i * 72, j * 72);
			else if (MAP[j][i] == 'C')
				render_map_coin(position, i * 72, j * 72);
			else if (MAP[j][i] == 'E')
				render_map_exit(position, j, i);
			else if (MAP[j][i] == 'P')
				render_map_protagonist(position, j, i);
			i++;
		}
		j++;
	}
}