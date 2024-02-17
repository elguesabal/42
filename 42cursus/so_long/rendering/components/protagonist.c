#include "../../so_long.h"

void	render_map_protagonist(components *position, int j, int i, int width, int height)
{
    position->protagonist.height = 72 * i;
    position->protagonist.width = 72 * j;
    position->protagonist_i = i;
    position->protagonist_j = j;
    draw_background("./img_xpm/protagonist/protagonist1.xpm", width, height);
}