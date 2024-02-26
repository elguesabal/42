/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:26:48 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 16:44:51 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_background(char *image_path, int width, int height)
{
	void	*img_ptr;
	int		img_width;
	int		img_height;

	img_ptr = mlx_xpm_file_to_image(g_mlx_prt,
			image_path, &img_width, &img_height);
	mlx_put_image_to_window(g_mlx_prt, g_win_ptr, img_ptr, width, height);
	free(img_ptr);
}
