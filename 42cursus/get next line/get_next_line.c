/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:21:10 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/14 17:17:52 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (!c)
		return ((char *)str);
	return (NULL);
}

size_t	finish_line(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

// static void move_and_remove(char *destination, char *source, size_t count)
// {
// 	size_t	len;
// 	size_t	i;
// 	size_t	rest;

// 	if (!destination || !source)
// 		return;
// 	len = 0;
// 	while (source[len])
// 		len++;
// 	if (count > len)
// 		return;
// 	i = 0;
// 	while (i < count) {
// 		destination[i] = source[i];
// 		i++;
// 	}
// 	destination[count] = '\0';
// 	rest = 0;
// 	while (source[rest + count] != '\0')
// 	{
// 		if (source[rest + count] == '\0')
// 			return;
// 		rest++;
// 	}
// 	i = 0;
// 	while (i <= rest)
// 	{
// 		source[i] = source[i + count];
// 		i++;
// 	}
// }

static int	get_line(int fd, char *line)
{
	int			size;
	static char	*buffer;

	if (!line)
		return (0);
	if (!buffer)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		// buffer[size] = '\0';
		// next_line = malloc((finish_line(line) + 1) * sizeof(char));
		// printf("%ld", finish_line(line));
		line = ft_strchr(line, '\n');
		line++;
		// *next_line = 'w';
		// printf("entro aki\n%s", line);
		// printf("entro aki\n'%s'\n", line);
		printf("%p\n", &buffer);
		printf("%p", &line);
	}
	// else if (next_line)
	// {
	// 	// PAREI AKI E TO MEIO PERDIDO
	// 	// COMO VOU PEGAR UM ENDERECO DE MEMORIA E CONTINUAR DPS Q ACHAR O '\n' E IR ATE O COMECO DA STRING?
	// 	// TENHO Q RETORNAR SO O COMECO ATE O FIM DA STRING
	// 	printf("teste: '%s'", next_line);
	// 	//move_and_remove(search, line, 100);
	// }
	return (0);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (!(line = malloc(1000 + 1 * sizeof(char))))
		return (NULL);
	get_line(fd, line);
	return (line);
}