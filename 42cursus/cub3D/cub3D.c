#include "cub3D.h"

int	g_x;
int	g_y;
void	*g_mlx;
void	*g_win;
char	**g_map;
char	**g_copy_map;

int	main(int argc, char **argv)
{
(void)argc;
	g_x = n_columns(argv[1]);
	g_y = n_lines(argv[1]);
	g_map = allocate_memory(g_x + 1, g_y + 1);
	g_copy_map = allocate_memory(g_x + 1, g_y + 1);

// printf("x: %d\ty: %d\n", g_x, g_y);
// int	i = 0, j = 0;
// while (i < g_y)
// {
// 	j = 0;
// 	while (j < g_x)
// 	{
// 		g_map[i][j] = 'a';
// 		j++;
// 	}
// 	i++;
// }
// g_map[1][1] = 'w';
// i = 0;
// while (i < g_y)
// {
// 	j = 0;
// 	while (j < g_x)
// 	{
// 		printf("%c", g_map[i][j]);
// 		j++;
// 	}
// 	printf("\n");
// 	i++;
// }

	g_mlx = mlx_init();
	g_win = mlx_new_window(g_mlx, 200, 200, "cub3D");

	mlx_hook(g_win, 17, 0, close_win, NULL);
	mlx_hook(g_win, KeyPress, KeyPressMask, keyboard, NULL);

	mlx_loop(g_mlx);
	return (0);
}
