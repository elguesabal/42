#include "../so_long.h"

void	move_vertical(components *position, int direction)
{
	if (MAP[position->protagonist_j][position->protagonist_i + direction] != '1')
	{
		draw_background("./img_xpm/void.xpm", position->protagonist.height, position->protagonist.width);
		position->protagonist.height += 72 * direction;
		position->protagonist_i += 1 * direction;
		draw_background("./img_xpm/protagonist/protagonist1.xpm", position->protagonist.height, position->protagonist.width);
	}
}

void	move_horizontal(components *position, int direction)
{
	if (MAP[position->protagonist_j + direction][position->protagonist_i] != '1')
	{
		draw_background("./img_xpm/void.xpm", position->protagonist.height, position->protagonist.width);
		position->protagonist.width += 72 * direction;
		position->protagonist_j += 1 * direction;
		draw_background("./img_xpm/protagonist/protagonist1.xpm", position->protagonist.height, position->protagonist.width);
	}
}

// FUNCAO DE EVENTO DE TECLA
int    ft_key(int key, void *param)
{
	components		*position = (components *)param;

	if(key == 'w' || key == 65362)
		move_horizontal(position, -1);
	else if(key == 'a' || key == 65361)
		move_vertical(position, -1);
	else if(key == 's' || key == 65364)
		move_horizontal(position, 1);
	else if(key == 'd' || key == 65363)
		move_vertical(position, 1);
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
	// 		draw_background(name_image("./img_xpm/fox/fox", i), 0, 0);
	// 		usleep(200000);
	// 		i++;
	// 	}
	// }
}

// FUNCAO DE EVENTO DE CLICK Q FECHA A JANELA CLICANDO NO X
int close_window(int key, void *param)
{
    // Sair do loop de eventos
    mlx_destroy_window(MLX_PTR, WIN_PTR);
	// exit();
    return (0);
}