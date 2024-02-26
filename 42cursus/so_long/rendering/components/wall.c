/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:26:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 10:34:43 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_map_wall(int j, int i, int width, int height)
{
	if (j == 0 && i == 0)
		draw_background("./img/1/wall1.xpm", width, height);
	else if (j == 0 && i != 0 && g_map[j][i + 1] != '\0')
		draw_background("./img/1/wall2.xpm", width, height);
	else if (j == 0 && g_map[j][i + 1] == '\0')
		draw_background("./img/1/wall3.xpm", width, height);
	else if (j != 0 && g_map[j + 1][0] != '\0' && i == 0)
		draw_background("./img/1/wall4.xpm", width, height);
	else if (j != 0 && g_map[j + 1][0] != '\0' && g_map[j][i + 1] == '\0')
		draw_background("./img/1/wall6.xpm", width, height);
	else if (g_map[j + 1][0] == '\0' && i == 0)
		draw_background("./img/1/wall7.xpm", width, height);
	else if (g_map[j + 1][0] == '\0' && i != 0 && g_map[j][i + 1] != '\0')
		draw_background("./img/1/wall8.xpm", width, height);
	else if (g_map[j + 1][0] == '\0' && g_map[j][i + 1] == '\0')
		draw_background("./img/1/wall9.xpm", width, height);
	else
		draw_background("./img/1/block.xpm", width, height);
}
