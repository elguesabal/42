/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:24:54 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 17:10:20 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_map_coin(t_components *position, int width, int height)
{
	position->n_c++;
	draw_background("./img/c/c1.xpm", width, height);
}
