/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:21:10 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/16 18:15:08 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	search(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	if (!str[i])
		return (0);
	i++;
	return (i);
}

static void move_and_remove(char *destination, char *source, size_t count)
{
	size_t	len;
	size_t	i;
	size_t	rest;

	if (!destination || !source)
		return;
	len = 0;
	while (source[len])
		len++;
	if (count > len)
		return;
	i = 0;
	while (i < count)
	{
		destination[i] = source[i];
		i++;
	}
	destination[count] = '\0';
	rest = 0;
	while (source[rest + count] != '\0')
	{
		if (source[rest + count] == '\0')
			return;
		rest++;
	}
	i = 0;
	while (i <= rest)
	{
		source[i] = source[i + count];
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int		size_read;

	line = NULL;
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer)
		{
			size_read = read(fd, buffer, BUFFER_SIZE);
			buffer[size_read] = '\0';
		}
	}

	if (!*buffer)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		buffer[size_read] = '\0';
	}

	while (1)
	{
		if (!line)
		{
			line = malloc((100 * sizeof(char)));
			move_and_remove(line, buffer, search(buffer));	// ACHO Q O PROBLEMA DE NAO LER A ULTIMA LINHA ESTA AKI PQ NA ULTIMA LINHA A FUNCAO search() RETORNA 0
		}

		if (search(line) || (!search(line) && size_read < BUFFER_SIZE))
			return (line);
		else if (!*buffer)
		{
		 	size_read = read(fd, buffer, BUFFER_SIZE);
		 	buffer[size_read] = '\0';
		}
	}
}