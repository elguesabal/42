/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:26:48 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/23 15:55:42 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_background(char *image_path, int width, int height)
{
	void	*img_ptr;
	int		img_width;
	int		img_height;

	img_ptr = mlx_xpm_file_to_image(MLX_PTR,
			image_path, &img_width, &img_height);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, img_ptr, width, height);
}
