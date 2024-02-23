/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:24:54 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/23 11:24:55 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_map_coin(components *position, int width, int height)
{
	position->n_coin++;
	draw_background("./img_xpm/coin/coin1.xpm", width, height);
}