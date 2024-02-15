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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	width_height	*protagonist = (width_height *)param;
	int				i;

	draw_background("./img_xpm/void.xpm", protagonist->height, protagonist->width);

	if(key == 'w' || key == 65362)
		protagonist->width -= 72;
	else if(key == 'a' || key == 65361)
		protagonist->height -= 72;
	else if(key == 's' || key == 65364)
		protagonist->width += 72;
	else if(key == 'd' || key == 65363)
		protagonist->height += 72;
	else if(key == 65307)	// ESC
	{
		mlx_destroy_window(MLX_PTR, WIN_PTR);
		// exit();
	}

	draw_background("./img_xpm/protagonist/protagonist1.xpm", protagonist->height, protagonist->width);



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

width_height	*read_map(char *file, char (*map)[100])
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
			map[j][i] = c;
			i++;
		}
		else if (c == '\n')
		{
			map[j][i] = '\0';
			i = 0;
			j++;
		}
	}
	map[j + 1][0] = '\0';
	close(fd);
	resolution->height = ft_strlen(map[0]);
	resolution->width = j + 1;
	return (resolution);
}

int main(int argc, char **argv)
{
	// int				fd;
	// char			c;
	int				i;
	int				j;
	char			map[100][100];
	width_height	*resolution;
	width_height	protagonist;

	resolution = read_map(argv[1], map);
	if (!resolution)
		return (0);
	// fd = open(argv[1], O_RDONLY);
	// if (fd == -1)
	// {
	// 	printf("Erro\n");
	// 	return (0);
	// }

	// // PASSAR O MAPA .ber PARA MATRIZ
	// i = 0;
	// j = 0;
	// while (read(fd, &c, 1))
	// {
	// 	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
	// 	{
	// 		map[j][i] = c;
	// 		i++;
	// 	}
	// 	else if (c == '\n')
	// 	{
	// 		map[j][i] = '\0';
	// 		i = 0;
	// 		j++;
	// 	}
	// }
	// map[j + 1][0] = '\0';
	// close(fd);



								// FAZER UMA VERIFICACAO PARA VER SE O MAPA E VALIDO

								// FAZER UMA VERIFICACAO PARA VER SE O MAPA E VALIDO



	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, 72 * resolution->height, 72 * resolution->width, "Minha janela");
	mlx_key_hook(WIN_PTR, ft_key, &protagonist);
	mlx_hook(WIN_PTR, 17, 0, close_window, NULL);


	// DESENHAR O MAPA COM A MATRIZ
	i = 0;
	j = 0;
	static int	width = 0;
	static int	height = 0;
	while (map[j][0])
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
				if (j == 0 && i == 0)
					draw_background("./img_xpm/wall/wall1.xpm", width, height);
				else if (j == 0 && i != 0 && map[j][i + 1] != '\0')
					draw_background("./img_xpm/wall/wall2.xpm", width, height);
				else if (j == 0 && map[j][i + 1] == '\0')
					draw_background("./img_xpm/wall/wall3.xpm", width, height);
				else if (j != 0 && map[j + 1][0] != '\0' && i == 0)
					draw_background("./img_xpm/wall/wall4.xpm", width, height);
				else if (j != 0 && map[j + 1][0] != '\0' && map[j][i + 1] == '\0')
					draw_background("./img_xpm/wall/wall6.xpm", width, height);
				else if (map[j + 1][0] == '\0' && i == 0)
					draw_background("./img_xpm/wall/wall7.xpm", width, height);
				else if (map[j + 1][0] == '\0' && i != 0 && map[j][i + 1] != '\0')
					draw_background("./img_xpm/wall/wall8.xpm", width, height);
				else if (map[j + 1][0] == '\0' && map[j][i + 1] == '\0')
					draw_background("./img_xpm/wall/wall9.xpm", width, height);
				else
					draw_background("./img_xpm/wall/block.xpm", width, height);
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
				protagonist.height = 72 * i;
				protagonist.width = 72 * j;
				draw_background("./img_xpm/protagonist/protagonist1.xpm", width, height);
			}
			width += 72;
			i++;
		}
		height += 72;
		j++;
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

