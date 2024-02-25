/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:24:38 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/23 12:15:17 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	aux_move(components *position, j_i *protagonist, int *movements)
{
	if (!position->n_coin)
		draw_background("./img/exit/exit2.xpm", position->exit.i * 72, position->exit.j * 72);
	else
		draw_background("./img/exit/exit1.xpm", position->exit.i * 72, position->exit.j * 72);

	draw_background("./img/protagonist/protagonist1.xpm", protagonist->i * 72, protagonist->j * 72);
	(*movements)++;
	putnbr(*movements);
	write(1, "\n", 1);

	if (!position->n_coin && MAP[position->protagonist.j][position->protagonist.i] == 'E')
		mlx_destroy_window(MLX_PTR, WIN_PTR);
}

void	move_horizontal(int *movements, components *position, int direction)
{
	if (MAP[position->protagonist.j][position->protagonist.i + direction] != '1')
	{
		if (MAP[position->protagonist.j][position->protagonist.i + direction] == 'C')
		{
			position->n_coin--;
			MAP[position->protagonist.j][position->protagonist.i + direction] = '0';
		}
		draw_background("./img/void.xpm", position->protagonist.i * 72, position->protagonist.j * 72);
		position->protagonist.i += 1 * direction;

		aux_move(position, &position->protagonist, movements);

	}
}

void	move_vertical(int * movements, components *position, int direction)
{
	if (MAP[position->protagonist.j + direction][position->protagonist.i] != '1')
	{
		if (MAP[position->protagonist.j + direction][position->protagonist.i] == 'C')
		{
			position->n_coin--;
			MAP[position->protagonist.j + direction][position->protagonist.i] = '0';
		}
		draw_background("./img/void.xpm", position->protagonist.i * 72, position->protagonist.j * 72);
		position->protagonist.j += 1 * direction;
		// if (!position->n_coin)
		// 	draw_background("./img/exit/exit2.xpm", position->exit.i * 72, position->exit.j * 72);
		// else
		// 	draw_background("./img/exit/exit1.xpm", position->exit.i * 72, position->exit.j * 72);
		aux_move(position, &position->protagonist, movements);
		// if (!position->n_coin && MAP[position->protagonist.j][position->protagonist.i] == 'E')
		// 	mlx_destroy_window(MLX_PTR, WIN_PTR);
	}
}

// FUNCAO DE EVENTO DE TECLA
int    ft_key(int key, void *param)
{
	static int		movements;
	components		*position = (components *)param;

	if(key == 'w' || key == 65362)
		move_vertical(&movements, position, -1);
	else if(key == 'a' || key == 65361)
		move_horizontal(&movements, position, -1);
	else if(key == 's' || key == 65364)
		move_vertical(&movements, position, 1);
	else if(key == 'd' || key == 65363)
		move_horizontal(&movements, position, 1);
	else if(key == 65307)	// ESC
	{
		mlx_destroy_window(MLX_PTR, WIN_PTR);
		// exit();
	}


	// int	i;
	// if(key == 'p')		// RAPOSA ANIMADA
	// {
	// 	i = 1;
	// 	while(1)
	// 	{
	// 		if(i > 4)
	// 			i = 1;
	// 		draw_background(name_image("./img/fox/fox", i), 0, 0);
	// 		usleep(200000);
	// 		i++;
	// 	}
	// }
}

// FUNCAO DE EVENTO DE CLICK Q FECHA A JANELA CLICANDO NO X
int close_window(int key, void *param)
{
    mlx_destroy_window(MLX_PTR, WIN_PTR);
    return (0);
}