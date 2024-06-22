#include "./../cub3D.h"

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
	i++;
	return (i);
}

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
	i += 2;
	return (i);
}