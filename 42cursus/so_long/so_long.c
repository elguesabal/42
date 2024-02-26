/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:15:02 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 15:39:12 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*g_mlx_prt;
void	*g_win_ptr;
char	**g_map;
char	**g_copy_map;
int		g_n_c;
int		g_n_e;

int	main(int argc, char **argv)
{
	j_i				resolution;
	components		position;

	(void)argc;
	position.n_c = 0;
	g_map = allocate_memory(count_columns(argv[1]), count_lines(argv[1]));
	g_copy_map = allocate_memory(count_columns(argv[1]), count_lines(argv[1]));
	if(result_of_checks(argv[1], &resolution, &position))
		return (0);
	g_mlx_prt = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_prt, resolution.i * 72, resolution.j * 72,
			"segmentation fault (core dumped)");
	mlx_key_hook(g_win_ptr, ft_key, &position);
	mlx_hook(g_win_ptr, 17, 0, close_window, NULL);
	render_map(&position);
	mlx_loop(g_mlx_prt);
	return (0);
}
