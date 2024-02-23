/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:27:06 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/23 16:25:56 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	read_map(char *file, j_i *resolution)
{
	// j_i				*resolution;
	int				fd;
	char			c;
	int				i;
	int				j;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nErro ao abrir mapa");
		return (1);
	}

	// PASSAR O MAPA .ber PARA MATRIZ
	i = 0;
	j = 0;
	while (read(fd, &c, 1))
	{
		// if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')	// ERA FEITO ASSIM MAS MUDEI PQ LA NA VERIFICACAO E MELHOR DE TRABALHAR
		if (c != '\n')
		{
			MAP[j][i] = c;
			COPY_MAP[j][i] = c;
			i++;
		}
		else // if (c == '\n')
		{
			// MAP[j][i] = '\0';
			i = 0;
			j++;
		}
	}
	// MAP[j + 1][0] = '\0';
	// i = size_i();
	// while (i)
	// {
	// 	MAP[j + 1][i] = '\0';
	// 	i--;
	// }
	close(fd);
	// resolution = malloc(sizeof(j_i));	// NAO VERIFIQUEI ALOCACAO DE MEMORIA
	resolution->i = size_i();
	resolution->j = j + 1;
	return (0);
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