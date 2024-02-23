/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protagonist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:25:32 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/23 11:25:33 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_map_protagonist(components *position, int j, int i)
{
    position->protagonist.j = j;
    position->protagonist.i = i;
    draw_background("./img_xpm/protagonist/protagonist1.xpm", i * 72, j * 72);
}