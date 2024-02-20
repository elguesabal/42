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

#include "so_long.h"

void	*MLX_PTR;
void	*WIN_PTR;
char	MAP[100][100];


int main(int argc, char **argv)
{
	int				i;
	int				j;
	width_height	*resolution;
	components		position;

	position.n_coin = 0;	// TEMPORARIAMENTE INICIANDO AKI
	resolution = read_map(argv[1]);
	if (!resolution)
		return (0);


								// FAZER UMA VERIFICACAO PARA VER SE O MAPA E VALIDO

								// FAZER UMA VERIFICACAO PARA VER SE O MAPA E VALIDO



	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, 72 * resolution->height, 72 * resolution->width, "Minha janela");
	mlx_key_hook(WIN_PTR, ft_key, &position);
	mlx_hook(WIN_PTR, 17, 0, close_window, NULL);


	render_map(&position);


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


