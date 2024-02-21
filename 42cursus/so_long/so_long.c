/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:15:02 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/21 17:14:39 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*MLX_PTR;
void	*WIN_PTR;
// char	MAP[100][100];
char	**MAP;

// void	*ft_calloc(size_t n_elements, size_t size)

static int	allocate_memory()
{
	int	i;

	// MAP = (char **)malloc(100 * sizeof(char *));
	MAP = (char **)ft_calloc(100, sizeof(char *));
	if (MAP == NULL)
	{
		perror("Erro ao alocar memoria");
		return (1);
	}
	i = 0;
	while (i < 100)
	{
		// MAP[i] = (char *)malloc(100 * sizeof(char));
		MAP[i] = (char *)ft_calloc(100, sizeof(char));
		if (MAP[i] == NULL)
		{
			perror("Erro ao alocar memoria");
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int				i;
	int				j;
	j_i				*resolution;
	components		position;

	if (allocate_memory())
		return (0);
	position.n_coin = 0;	// TEMPORARIAMENTE INICIANDO AKI
	resolution = read_map(argv[1]);
	if (!resolution)
		return (0);



								// FAZER UMA VERIFICACAO PARA VER SE O MAPA E VALIDO
if (check_components())
	return (0);
if (count_components())
	return (0);
if (rectangular_map())
	return (0);


// j = 0;
// while (MAP[j][0])
// {
// 	i = 0;
// 	while (MAP[j][i])
// 	{
// 		printf("%d", MAP[j][i]);
// 		if (MAP[j][i + 1] == '\0')
// 			printf("a");
// 		i++;
// 	}
// 	printf("\n");
// 	j++;
// }
// printf("%c", MAP[1][0]);
// char teste = MAP[1][0];
// write(1, &teste, 1);
								// FAZER UMA VERIFICACAO PARA VER SE O MAPA E VALIDO



	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, 72 * resolution->i, 72 * resolution->j, "segmentation fault (core dumped)");
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


