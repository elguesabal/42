/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protagonist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:25:32 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 17:10:26 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_map_protagonist(t_components *position, int j, int i)
{
	position->p.j = j;
	position->p.i = i;
	draw_background("./img/p/p1.xpm", i * 72, j * 72);
}
