/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:27:06 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 17:10:39 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	creat_map(int *fd)
{
	int		j;
	int		i;
	char	c;

	j = 0;
	i = 0;
	while (read(*fd, &c, 1))
	{
		if (c != '\n')
		{
			g_map[j][i] = c;
			g_copy_map[j][i] = c;
			i++;
		}
		else
		{
			i = 0;
			j++;
		}
	}
}

int	read_map(char *file, t_j_i *resolution)
{
	int				fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	creat_map(&fd);
	close(fd);
	resolution->j = size_j();
	resolution->i = size_i();
	return (0);
}

void	render_map(t_components *position)
{
	int	i;
	int	j;

	j = 0;
	while (g_map[j][0])
	{
		i = 0;
		while (g_map[j][i])
		{
			if (g_map[j][i] == '1')
				render_map_wall(j, i, i * 72, j * 72);
			else if (g_map[j][i] == 'C')
				render_map_coin(position, i * 72, j * 72);
			else if (g_map[j][i] == 'E')
				render_map_exit(position, j, i);
			else if (g_map[j][i] == 'P')
				render_map_protagonist(position, j, i);
			i++;
		}
		j++;
	}
}
