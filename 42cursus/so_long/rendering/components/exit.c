#include "../../so_long.h"

void	render_map_exit(components *position, int j, int i)
{
	position->exit.j = j;
	position->exit.i = i;
	draw_background("./img_xpm/exit/exit1.xpm", i * 72, j * 72);
}