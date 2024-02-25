#include "../so_long.h"

void	aux_valid_path(int *num, int j, int i)
{
	(*num)--;
	valid_path(j, i);
}

// VERIFICA SE O CAMINHO DO MAPA E VALIDO
int	valid_path(int j, int i)
{
	COPY_MAP[j][i] = '1';
	if (COPY_MAP[j][i + 1] == '0')
		valid_path(j, i + 1);
	else if (COPY_MAP[j][i + 1] == 'C')
		aux_valid_path(&N_COIN, j, i + 1);
	else if (COPY_MAP[j][i + 1] == 'E')
		aux_valid_path(&N_EXIT, j, i + 1);
	if (COPY_MAP[j + 1][i] == '0')
		valid_path(j + 1, i);
	else if (COPY_MAP[j + 1][i] == 'C')
		aux_valid_path(&N_COIN, j + 1, i);
	else if (COPY_MAP[j + 1][i] == 'E')
		aux_valid_path(&N_EXIT, j + 1, i);
	if (COPY_MAP[j][i - 1] == '0')
		valid_path(j, i - 1);
	else if (COPY_MAP[j][i - 1] == 'C')
		aux_valid_path(&N_COIN, j, i - 1);
	else if (COPY_MAP[j][i - 1] == 'E')
		aux_valid_path(&N_EXIT, j, i - 1);
	if (COPY_MAP[j - 1][i] == '0')
		valid_path(j - 1, i);
	else if (COPY_MAP[j - 1][i] == 'C')
		aux_valid_path(&N_COIN, j - 1, i);
	else if (COPY_MAP[j - 1][i] == 'E')
		aux_valid_path(&N_EXIT, j - 1, i);
	return (N_COIN || N_EXIT);
}

int	result_of_checks(char *file, j_i *resolution, components *position)
{
	if (MAP == NULL || COPY_MAP == NULL)
		return (error("Error\nMemoria do mapa nao alocada"));
	if (read_map(file, resolution))
		return (error("Error\nErro ao abrir mapa"));
	if (check_components())
		return (error("Error\nMapa contem mais elementos inesistentes"));
	if (count_components(position))
		return (error("Error\nSaidas, protagonistas ou moedas invalidas"));
	if (vertical_check() || horizontal_check())
		return (error("Error\nMapa nao retangular"));
	if (wall_on_the_sides())
		return (error("Error\nLateral nao esta totalmente fechada"));
	if (valid_path(position->protagonist.j, position->protagonist.i))
		return (error("Error\nNao existe caminho valido no mapa"));
	return (0);
}
