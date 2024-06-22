#include "./../cub3D.h"

int	close_win(int key, void *param)
{
	(void)key;
	(void)param;
	if (g_mlx && g_win)
		mlx_destroy_window(g_mlx, g_win);
	if (g_mlx)
		mlx_destroy_display(g_mlx);
	if (g_mlx)
		free(g_mlx);
	exit(0);
	return (0);
}