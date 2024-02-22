
#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>  // printf

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
// extern char	MAP[100][100];
extern char	**MAP;


// ./rendering/components/wall.c
void	render_map_wall(int j, int i, int width, int height);
void	render_map_coin(components *position, int width, int height);
void	render_map_exit(components *position, int j, int i);
void	render_map_protagonist(components *position, int j, int i);

// ./rendering/verification.c
int		check_components(void);
int		count_components(void);
int		rectangular_map(void);
int		wall_on_the_sides(void);
int		valid_path(components *position);

// ./rendering/aux_rendering.c
void			draw_background(char *image_path, int width, int height);

// ./rendering/map.c
j_i		*read_map(char *file);
void	render_map(components *position);

// ./events/aux_event1.c


// ./events/key_event.c
void	move_vertical(components *position, int direction);
void	move_horizontal(components *position, int direction);
int		ft_key(int key, void *param);
int		close_window(int key, void *param);


// ./ft_aux/utils1.c
void	*ft_calloc(size_t n_elements, size_t size);
int		size_j(void);
int		size_i(void);
void	*allocate_memory(int map_j, int map_i);
void	copy_map(char **map);

#endif