/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:24:38 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 13:21:30 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	aux_move(components *position, j_i *p, int *movements)
{
	if (!position->n_c)
		draw_background("./img/e/e2.xpm",
			position->e.i * 72, position->e.j * 72);
	else
		draw_background("./img/e/e1.xpm",
			position->e.i * 72, position->e.j * 72);
	draw_background("./img/p/p1.xpm", p->i * 72, p->j * 72);
	(*movements)++;
	putnbr(*movements);
	write(1, "\n", 1);
	if (!position->n_c && g_map[position->p.j][position->p.i] == 'E')
		close_window(0, NULL);
}

void	move_horizontal(int *movements, components *position, int direction)
{
	if (g_map[position->p.j][position->p.i + direction] != '1')
	{
		if (g_map[position->p.j][position->p.i + direction] == 'C')
		{
			position->n_c--;
			g_map[position->p.j][position->p.i + direction] = '0';
		}
		draw_background("./img/void.xpm",
			position->p.i * 72, position->p.j * 72);
		position->p.i += 1 * direction;
		aux_move(position, &position->p, movements);
	}
}

void	move_vertical(int *movements, components *position, int direction)
{
	if (g_map[position->p.j + direction][position->p.i] != '1')
	{
		if (g_map[position->p.j + direction][position->p.i] == 'C')
		{
			position->n_c--;
			g_map[position->p.j + direction][position->p.i] = '0';
		}
		draw_background("./img/void.xpm",
			position->p.i * 72, position->p.j * 72);
		position->p.j += 1 * direction;
		aux_move(position, &position->p, movements);
	}
}

int	ft_key(int key, void *param)
{
	static int		movements;
	components		*position;

	position = (components *)param;
	if (key == 'w' || key == 65362)
		move_vertical(&movements, position, -1);
	else if (key == 'a' || key == 65361)
		move_horizontal(&movements, position, -1);
	else if (key == 's' || key == 65364)
		move_vertical(&movements, position, 1);
	else if (key == 'd' || key == 65363)
		move_horizontal(&movements, position, 1);
	else if (key == 65307)
		close_window(0, NULL);
	return (0);
}

int	close_window(int key, void *param)
{
	(void)key;
	(void)param;
	if (g_mlx_prt && g_win_ptr)
		mlx_destroy_window(g_mlx_prt, g_win_ptr);
	if (g_mlx_prt)
		mlx_destroy_display(g_mlx_prt);
	if (g_mlx_prt)
		free(g_mlx_prt);
	free_map();
	exit(0);
	return (0);
}
