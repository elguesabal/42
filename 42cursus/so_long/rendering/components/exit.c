/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:25:29 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 10:02:49 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_map_exit(components *position, int j, int i)
{
	position->e.j = j;
	position->e.i = i;
	draw_background("./img/e/e1.xpm", i * 72, j * 72);
}
