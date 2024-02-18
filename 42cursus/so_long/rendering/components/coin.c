#include "../../so_long.h"

void	render_map_coin(components *position, int width, int height)
{
	position->n_coin++;
	draw_background("./img_xpm/coin/coin1.xpm", width, height);
}