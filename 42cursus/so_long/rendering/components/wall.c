/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:26:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/23 11:26:26 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// RENDERIZA A APREDE
void	render_map_wall(int j, int i, int width, int height)
{
	if (j == 0 && i == 0)
		draw_background("./img_xpm/wall/wall1.xpm", width, height);
	else if (j == 0 && i != 0 && MAP[j][i + 1] != '\0')
		draw_background("./img_xpm/wall/wall2.xpm", width, height);
	else if (j == 0 && MAP[j][i + 1] == '\0')
		draw_background("./img_xpm/wall/wall3.xpm", width, height);
	else if (j != 0 && MAP[j + 1][0] != '\0' && i == 0)
		draw_background("./img_xpm/wall/wall4.xpm", width, height);
	else if (j != 0 && MAP[j + 1][0] != '\0' && MAP[j][i + 1] == '\0')
		draw_background("./img_xpm/wall/wall6.xpm", width, height);
	else if (MAP[j + 1][0] == '\0' && i == 0)
		draw_background("./img_xpm/wall/wall7.xpm", width, height);
	else if (MAP[j + 1][0] == '\0' && i != 0 && MAP[j][i + 1] != '\0')
		draw_background("./img_xpm/wall/wall8.xpm", width, height);
	else if (MAP[j + 1][0] == '\0' && MAP[j][i + 1] == '\0')
		draw_background("./img_xpm/wall/wall9.xpm", width, height);
	else
		draw_background("./img_xpm/wall/block.xpm", width, height);
}