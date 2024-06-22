#include "./../cub3D.h"

int keyboard(int key, void *param)
{
	(void)param;
	if (key == 65307)
		close_win(0, NULL);
	printf("%c\n", key);
	return (0);
}
