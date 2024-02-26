/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:33:21 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 17:58:03 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	aux_valid_path(int *num, int j, int i)
{
	g_copy_map[j][i] = 'X';
	if (num)
		(*num)--;
	valid_path(j, i);
}

int	valid_path(int j, int i)
{
	if (g_copy_map[j][i + 1] == '0')
		aux_valid_path(NULL, j, i + 1);
	else if (g_copy_map[j][i + 1] == 'C')
		aux_valid_path(&g_n_c, j, i + 1);
	else if (g_copy_map[j][i + 1] == 'E')
		aux_valid_path(&g_n_e, j, i + 1);
	if (g_copy_map[j + 1][i] == '0')
		aux_valid_path(NULL, j + 1, i);
	else if (g_copy_map[j + 1][i] == 'C')
		aux_valid_path(&g_n_c, j + 1, i);
	else if (g_copy_map[j + 1][i] == 'E')
		aux_valid_path(&g_n_e, j + 1, i);
	if (g_copy_map[j][i - 1] == '0')
		aux_valid_path(NULL, j, i - 1);
	else if (g_copy_map[j][i - 1] == 'C')
		aux_valid_path(&g_n_c, j, i - 1);
	else if (g_copy_map[j][i - 1] == 'E')
		aux_valid_path(&g_n_e, j, i - 1);
	if (g_copy_map[j - 1][i] == '0')
		aux_valid_path(NULL, j - 1, i);
	else if (g_copy_map[j - 1][i] == 'C')
		aux_valid_path(&g_n_c, j - 1, i);
	else if (g_copy_map[j - 1][i] == 'E')
		aux_valid_path(&g_n_e, j - 1, i);
	return (g_n_c || g_n_e);
}

int	result_of_checks(int n, char *f, t_j_i *resol, t_components *position)
{
	if (n != 2)
		return (error("Error\nNumero de argumentos invalidos", 0));
	if (g_map == NULL || g_copy_map == NULL)
		return (error("Error\nMemoria do mapa nao alocada", 1));
	if (read_map(f, resol))
		return (error("Error\nErro ao abrir mapa", 1));
	if (check_components())
		return (error("Error\nMapa contem mais elementos inesistentes", 1));
	if (count_components(position))
		return (error("Error\nSaidas, protagonistas ou moedas invalidas", 1));
	if (vertical_check() || horizontal_check())
		return (error("Error\nMapa nao retangular", 1));
	if (wall_on_the_sides())
		return (error("Error\nLateral nao esta totalmente fechada", 1));
	if (valid_path(position->p.j, position->p.i))
		return (error("Error\nNao existe caminho valido no mapa", 1));
	return (0);
}
