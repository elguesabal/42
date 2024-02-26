/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:24:47 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/26 18:07:25 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	putnbr(unsigned int n)
{
	if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

void	*ft_calloc(size_t n_elements, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(n_elements * size);
	if (ptr)
	{
		i = 0;
		while (i < n_elements * size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}

void	*allocate_memory(int map_j, int map_i)
{
	char	**memory;
	int		i;

	memory = ft_calloc(map_j, sizeof(char *));
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (i < map_i)
	{
		memory[i] = ft_calloc(map_i, sizeof(char));
		if (memory[i] == NULL)
			return (NULL);
		i++;
	}
	return (memory);
}

int	count_lines(char *file)
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
	i += 2;
	return (i);
}

int	count_columns(char *file)
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
	i++;
	return (i);
}
