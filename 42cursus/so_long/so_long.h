
#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>  // printf

typedef struct
{
	int	height;
	int	width;
} width_height;

typedef struct
{
	int	j;
	int	i;
} j_i;

typedef struct
{
	int				n_coin;
	j_i				exit;
	j_i				protagonist;
} components;

extern void	*MLX_PTR;
extern void	*WIN_PTR;
extern char	MAP[100][100];


// ./rendering/components/wall.c
void	render_map_wall(int j, int i, int width, int height);
void	render_map_coin(components *position, int width, int height);
void	render_map_exit(components *position, int j, int i);
void	render_map_protagonist(components *position, int j, int i);

// ./rendering/map.c
width_height	*read_map(char *file);
void			render_map();

// ./rendering/aux_rendering.c
void			draw_background(char *image_path, int width, int height);


// ./events/aux_event1.c


// ./events/key_event.c
void	move_vertical(components *position, int direction);
void	move_horizontal(components *position, int direction);
int		ft_key(int key, void *param);
int		close_window(int key, void *param);


// ./ft_aux/utils1.c
size_t	ft_strlen(const char *str);


#endif