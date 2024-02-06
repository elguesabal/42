/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:15:02 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/06 18:57:01 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	*MLX_PTR;
void	*WIN_PTR;

typedef struct
{
	int	height;
	int	width;
} width_height;

void draw_background(void *mlx_ptr, void *win_ptr, char *image_path, int width, int height)
{
    void	*img_ptr;
    int		img_width;
	int		img_height;

    // CARREGA A IMAGEM
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, image_path, &img_width, &img_height);

    // DESENHA A IMAGEM NA JANELA
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, width, height);
}

int    ft_key(int key, void *param)
{
	width_height	*gojo = (width_height *)param;

	if(key == 'w' || key == 65362)
		gojo->width -= 100;
	else if(key == 'a' || key == 65361)
		gojo->height -= 100;
	else if(key == 's' || key == 65364)
		gojo->width += 100;
	else if(key == 'd' || key == 65363)
		gojo->height += 100;


	draw_background(MLX_PTR, WIN_PTR, "image.xpm", gojo->height, gojo->width);

	// if(key == 65307)	// ESC
	// {
	// 	// mlx_destroy_window((void *)param);
	// 	printf("ESC\n");
	// }


	// printf("%d\n", key);
}

int close_window(void *mlx_ptr, void *win_ptr)
{
    // Sair do loop de eventos
    mlx_destroy_window(mlx_ptr, win_ptr);
    return (0);
}

int main()
{
    // void *mlx_ptr;
    // void *win_ptr;
	width_height	location;

    // mlx_ptr = mlx_init();
    // win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Minha janela");

	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, 800, 600, "Minha janela");

	// location->mlx_ptr = mlx_ptr;
	// location->win_ptr = win_ptr;
	location.height = 400;
	location.width = 300;
// draw_background(MLX_PTR, WIN_PTR, "image.xmp", 0, 0);

// printf("%ld\n", (long int)MLX_PTR);
// printf("%p\n", location->win_ptr);
// printf("%d\n", location->width);
// printf("%d\n", location->height);

	mlx_key_hook(WIN_PTR, ft_key, &location);
	// mlx_hook(win_ptr, 17, 0, close_window, win_ptr);

// draw_background(mlx_ptr, win_ptr, "image.xpm", 0, 0);

// sleep(1);
// // location.width = 10;
// // location.height = 20;
// // printf("%d\n", location.width);
// 	draw_background(mlx_ptr, win_ptr, "image.xpm", 0, 0);
// sleep(1);
// 	mlx_clear_window(mlx_ptr, win_ptr);
// sleep(1);
// 	draw_background(mlx_ptr, win_ptr, "image.xpm", 400, 0);
// 	draw_background(mlx_ptr, win_ptr, "image.xpm", 200, 100);
// sleep(1);
// 	mlx_clear_window(mlx_ptr, win_ptr);



    mlx_loop(MLX_PTR);
    mlx_destroy_window(MLX_PTR, WIN_PTR);
}