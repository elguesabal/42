/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protagonist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:25:32 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 10:03:09 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_map_protagonist(components *position, int j, int i)
{
	position->p.j = j;
	position->p.i = i;
	draw_background("./img/p/p1.xpm", i * 72, j * 72);
}
