#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

extern int	g_x;
extern int	g_y;
extern void	*g_mlx;
extern void	*g_win;
extern char	**g_map;
extern char	**g_copy_map;

// ./events/close_win.c
int	close_win(int key, void *param);

// ./events/keyboard.c
int keyboard(int key, void *param);

// ./utils/memory.c
void	*ft_calloc(size_t n_elements, size_t size);
void	*allocate_memory(int x, int y);
void	free_map();

// ./utils/map_reading.c
int	n_columns(char *file);
int	n_lines(char *file);


#endif