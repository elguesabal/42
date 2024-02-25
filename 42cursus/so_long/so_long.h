/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:06:41 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/23 16:38:07 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct
{
	int	j;
	int	i;
} j_i;

typedef struct
{
	int	n_coin;
	j_i	exit;
	j_i	protagonist;
} components;

extern void	*MLX_PTR;
extern void	*WIN_PTR;
extern char	**MAP;
extern char	**COPY_MAP;
extern int	N_COIN;
extern int	N_EXIT;


// ./verification/verification1.c
int		check_components(void);
void	count(int *coin, j_i *position, int *protagonist, int *exit);
int		count_components(components *position);
int		vertical_check(void);
int		horizontal_check(void);
// int		rectangular_map(void);

// ./verification/verification2.c
int		first_line(int *i);
int		last_column(int *j, int *i);
int		first_column(int *j);
int		last_line(int *j, int *i);
int		wall_on_the_sides(void);

// ./verification/verification3.c
void	aux_valid_path(int *num, int j, int i);
int		valid_path(int j, int i);
int 	result_of_checks(char *file, j_i *resolution, components *position);

// ./rendering/aux_rendering.c
void	draw_background(char *image_path, int width, int height);

// ./rendering/components/wall.c
void	render_map_wall(int j, int i, int width, int height);
void	render_map_coin(components *position, int width, int height);
void	render_map_exit(components *position, int j, int i);
void	render_map_protagonist(components *position, int j, int i);

// ./rendering/map.c
void	creat_map(int *fd);
int		read_map(char *file, j_i *resolution);
void	render_map(components *position);

// ./events/key_event.c
void	aux_move(components *position, j_i *protagonist, int *movements);
void	move_horizontal(int *movements, components *position, int direction);
void	move_vertical(int * movements, components *position, int direction);
int		ft_key(int key, void *param);
int		close_window(int key, void *param);

// ./ft_aux/utils1.c
void	putnbr(unsigned int n);
void	*ft_calloc(size_t n_elements, size_t size);
void	*allocate_memory(int map_j, int map_i);
int		count_lines(char *file);
int		count_columns(char *file);

// ./ft_aux/utils2.c
int		size_j(void);
int		size_i(void);
int		error(char *str);
void	free_map(void);
//void	copy_map(char **map);


#endif