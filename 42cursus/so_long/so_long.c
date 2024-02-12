/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:15:02 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/08 18:08:16 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	*MLX_PTR;
void	*WIN_PTR;

typedef struct
{
	int	height;
	int	width;
} width_height;

void draw_background(char *image_path, int width, int height)	// FUNCAO PARA PEGAR O NOME DA IMAGEM E POSICAO PARA RENDERIZAR A IMAGEM
{
    void	*img_ptr;
    int		img_width;
	int		img_height;

    // CARREGA A IMAGEM
    img_ptr = mlx_xpm_file_to_image(MLX_PTR, image_path, &img_width, &img_height);

    // DESENHA A IMAGEM NA JANELA
    mlx_put_image_to_window(MLX_PTR, WIN_PTR, img_ptr, width, height);
}

int    ft_key(int key, void *param)	// FUNCAO DE EVENTO DE TECLA
{
	int				move;
	width_height	*gojo = (width_height *)param;
	int				i;

	if(key == 'w' || key == 65362)
		gojo->width -= 100;
	else if(key == 'a' || key == 65361)
		gojo->height -= 100;
	else if(key == 's' || key == 65364)
		gojo->width += 100;
	else if(key == 'd' || key == 65363)
		gojo->height += 100;

	draw_background("image.xpm", gojo->height, gojo->width);

	if(key == 65307)	// ESC
	{
		mlx_destroy_window(MLX_PTR, WIN_PTR);
		// exit();
	}

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

	move++;
	printf("%d\n", move);
}

int close_window(int key, void *param)	// FUNCAO DE EVENTO DE CLICK Q FECHA A JANELA CLICANDO NO X
{
    // Sair do loop de eventos
    mlx_destroy_window(MLX_PTR, WIN_PTR);
	// exit();
    return (0);
}

int main(int argc, char **argv)
{
	int				fd;
	char			c;
	int				i;
	int				j;
	char			map[100][100];
	width_height	location;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Erro\n");
		return (0);
	}

	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, 936, 288, "Minha janela");

	location.height = 0;
	location.width = 0;

	mlx_key_hook(WIN_PTR, ft_key, &location);
	mlx_hook(WIN_PTR, 17, 0, close_window, NULL);


	// PASSAR O MAPA .ber PARA MATRIZ
	i = 0;
	j = 0;
	while (read(fd, &c, 1))
	{
		if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		{
			map[j][i] = c;
			i++;
		}
		else if (c == '\n')
		{
			// map[j][i] = '\n';
			// map[j][i + 1] = '\0';
			map[j][i] = '\0';
			i = 0;
			j++;
		}
		// printf("%c", c);
	}
	// j++;
	// map[j][0] = '\0';
// printf("%d\n", j);
// 	map[j][i + 1] = '\0';
	map[j + 1][0] = '\0';
	close(fd);
// draw_background("./img_xpm/wall/wall1.xpm", 0, 0);


// i = 0;
// j = 0;
// while(map[j][0]) {
// 	i = 0;
// 	while(map[j][i]) {
// 		printf("%c", map[j][i]);
// 		i++;
// 	}
// 	j++;
// }


	// DESENHAR O MAPA COM A MATRIZ
	i = 0;
	j = 0;
	static int	width = 0;
	static int	height = 0;
	while (map[j][0])	// QUANDO O ARQUIVO TEM UM 0 E SALVO EM UMA VARIAVEL COMO CHAR O TESTE CONSIDERA O CHAR '0' COMO FALSE
	{
		width = 0;
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '0')
			{
			}
			else if (map[j][i] == '1')
			{
				draw_background("./img_xpm/wall/wall1.xpm", width, height);
			}
			else if (map[j][i] == 'C')
			{
				// draw_background("", width, height);
			}
			else if (map[j][i] == 'E')
			{
				// draw_background("", width, height);
			}
			else if (map[j][i] == 'P')
			{
				// draw_background("", width, height);
			}
			width += 72;
			i++;
printf("%c", map[j][i]);
		}
		// else if (map[j][i] == '\n')
		// {
		// 	width = 0;
		// 	height += 72;
		// 	i = 0;
		// 	j++;
		// }
		height += 72;
		j++;
		// printf("%c", c);
printf("\n");
	}



// draw_background("./img_xpm/wall/wall1.xpm", 0, 0);
// draw_background("./img_xpm/wall/wall4.xpm", 72, 0);
// draw_background("./img_xpm/wall/wall1.xpm", 144, 0);
// draw_background("./img_xpm/wall/wall3.xpm", 216, 0);

// draw_background("./img_xpm/void.xpm", 0, 0);


    mlx_loop(MLX_PTR);
    mlx_destroy_window(MLX_PTR, WIN_PTR);
	return (0);
}










// char	*name_image(char *name, int frame)	// FUNCAO CRIADA PRA RETORNAR O NOME DO PROXIMO SPRITE
// {
// 	int		i;
// 	char	*name_img;

// 	i = 0;
// 	while(name[i])
// 		i++;
// 	name_img = malloc((i + 6) * sizeof(char));
// 	i = 0;
// 	while (name[i])
// 	{
// 		name_img[i] = name[i];
// 		i++;
// 	}
// 	name_img[i] = frame + 48;
// 	name_img[i + 1] = '.';
// 	name_img[i + 2] = 'x';
// 	name_img[i + 3] = 'p';
// 	name_img[i + 4] = 'm';
// 	name_img[i + 5] = '\0';
// 	return (name_img);
// }