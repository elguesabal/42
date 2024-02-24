/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:15:02 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/23 17:14:07 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*MLX_PTR;
void	*WIN_PTR;
char	**MAP;
char	**COPY_MAP;
int		N_COIN;
int		N_EXIT;


int main(int argc, char **argv)
{
	j_i				resolution;
	components		position;

	position.n_coin = 0;
	MAP = allocate_memory(100, 100);
	COPY_MAP = allocate_memory(100, 100);

	if(result_of_checks(argv[1], &resolution, &position))
		return (0);

	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, resolution.i * 72, resolution.j * 72, "segmentation fault (core dumped)");
	mlx_key_hook(WIN_PTR, ft_key, &position);
	mlx_hook(WIN_PTR, 17, 0, close_window, NULL);

	render_map(&position);

    mlx_loop(MLX_PTR);
    mlx_destroy_window(MLX_PTR, WIN_PTR);
	free(MLX_PTR);
	free_map();
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


