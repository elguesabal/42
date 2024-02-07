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

	// draw_background(MLX_PTR, WIN_PTR, "image.xpm", gojo->height, gojo->width);

	if(key == 65307)	// ESC
		mlx_destroy_window(MLX_PTR, WIN_PTR);

	if(key == 'p')
	{
		while(1)
		{
			draw_background(MLX_PTR, WIN_PTR, "./img_xpm/protagonist/protagonist1.xpm", 0, 0);
			sleep(1);
			draw_background(MLX_PTR, WIN_PTR, "./img_xpm/protagonist/protagonist2.xpm", 0, 0);
			sleep(1);
			draw_background(MLX_PTR, WIN_PTR, "./img_xpm/protagonist/protagonist3.xpm", 0, 0);
			sleep(1);
			draw_background(MLX_PTR, WIN_PTR, "./img_xpm/protagonist/protagonist4.xpm", 0, 0);
			sleep(1);
			draw_background(MLX_PTR, WIN_PTR, "./img_xpm/protagonist/protagonist5.xpm", 0, 0);
		}
	}

	printf("%d\n", key);
}

int close_window(int key, void *param)
{
    // Sair do loop de eventos
    mlx_destroy_window(MLX_PTR, WIN_PTR);
    return (0);
}

int main()
{
	width_height	location;

	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, 800, 600, "Minha janela");

	location.height = 0;
	location.width = 0;

	mlx_key_hook(WIN_PTR, ft_key, &location);
	mlx_hook(WIN_PTR, 17, 0, close_window, NULL);

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