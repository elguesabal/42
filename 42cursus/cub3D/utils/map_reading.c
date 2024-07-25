#include "./../cub3D.h"

/// @brief CONTA A QUANTIDADE DE COLUNAS QUE TEM NO ARQUIVO DO MAPA
/// @param file NOME DO ARQUIVO DO MAPA
/// @return RETORNA O NUMERO DE COLUNAS
int	n_columns(char *file)
{
	int		fd;
	int		i;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nArquivo de mapa invalido");
		exit(0);
	}
	i = 0;
	while (read(fd, &c, 1) && c != '\n')
		i++;
	close(fd);
	return (i);
}

/// @brief CONTA A QUANTIDADE DE LINHAS QUE TEM NO ARQUIVO DO MAPA
/// @param file NOME DO ARQUIVO DO MAPA
/// @return RETORNA O NUMERO DE LINHAS
int	n_lines(char *file)
{
	int		fd;
	int		i;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nArquivo de mapa invalido");
		exit(0);
	}
	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	close(fd);
	i++;
	return (i);
}