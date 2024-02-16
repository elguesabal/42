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
	int	i = 0;
	int	j = 0;
	int	width;
	int	height;

	height = 0;
	while (MAP[j][0])
	{
		width = 0;
		i = 0;
		while (MAP[j][i])
		{
			if (MAP[j][i] == '0')
			{
			}
			else if (MAP[j][i] == '1')
			{
				if (j == 0 && i == 0)
					draw_background("./img_xpm/wall/wall1.xpm", width, height);
				else if (j == 0 && i != 0 && MAP[j][i + 1] != '\0')
					draw_background("./img_xpm/wall/wall2.xpm", width, height);
				else if (j == 0 && MAP[j][i + 1] == '\0')
					draw_background("./img_xpm/wall/wall3.xpm", width, height);
				else if (j != 0 && MAP[j + 1][0] != '\0' && i == 0)
					draw_background("./img_xpm/wall/wall4.xpm", width, height);
				else if (j != 0 && MAP[j + 1][0] != '\0' && MAP[j][i + 1] == '\0')
					draw_background("./img_xpm/wall/wall6.xpm", width, height);
				else if (MAP[j + 1][0] == '\0' && i == 0)
					draw_background("./img_xpm/wall/wall7.xpm", width, height);
				else if (MAP[j + 1][0] == '\0' && i != 0 && MAP[j][i + 1] != '\0')
					draw_background("./img_xpm/wall/wall8.xpm", width, height);
				else if (MAP[j + 1][0] == '\0' && MAP[j][i + 1] == '\0')
					draw_background("./img_xpm/wall/wall9.xpm", width, height);
				else
					draw_background("./img_xpm/wall/block.xpm", width, height);
			}
			else if (MAP[j][i] == 'C')
			{
				// draw_background("", width, height);
			}
			else if (MAP[j][i] == 'E')
			{
				// draw_background("", width, height);
			}
			else if (MAP[j][i] == 'P')
			{
				position->protagonist.height = 72 * i;
				position->protagonist.width = 72 * j;
				position->protagonist_i = i;
				position->protagonist_j = j;
				draw_background("./img_xpm/protagonist/protagonist1.xpm", width, height);
			}
			width += 72;
			i++;
		}
		height += 72;
		j++;
	}
}