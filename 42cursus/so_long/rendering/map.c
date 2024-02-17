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
	int	width;
	int	height;

	j = 0;
	height = 0;
	while (MAP[j][0])
	{
		i = 0;
		width = 0;
		while (MAP[j][i])
		{
			if (MAP[j][i] == '0')
			{
			}
			else if (MAP[j][i] == '1')
				render_map_wall(j, i, width, height);
			else if (MAP[j][i] == 'C')
			{
				draw_background("./img_xpm/coin/coin1.xpm", width, height);
			}
			else if (MAP[j][i] == 'E')
			{
				draw_background("./img_xpm/exit/exit1.xpm", width, height);
			}
			else if (MAP[j][i] == 'P')
				render_map_protagonist(position, j, i, width, height);
			width += 72;
			i++;
		}
		height += 72;
		j++;
	}
}