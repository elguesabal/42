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

void	*ft_calloc(size_t n_elements, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	search(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	if (!str[i])
		return (0);
	i++;
	return (i);
}

size_t	copy_line(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (size > 0)
	{
		len = ft_strlen(dest);
		while (len + i < size - 1 && src[i] && src[i] != '\n')
		{
			dest[len++] = src[i++];
		}
		if (src[i] == '\n')
		{
			dest[len++] = '\n';
			dest[len] = '\0';
		}
		else
			dest[len] = '\0';
	}
	return (i);
}

static int	write_buffer(int fd, char *buffer)
{
	int	size_read;

	size_read = read(fd, buffer, BUFFER_SIZE);
	buffer[size_read] = '\0';
	return (size_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char	*backup;
	char		*line;
	int		size_read;
	static size_t	copied_lines;

	line = NULL;
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buffer)
		{
			backup = buffer;	// COPIA DO ENDERECO INICIAL PRA DPS DAR FREE
			size_read = write_buffer(fd, buffer);
		}
	}

	line = ft_calloc(100, sizeof(char));
	if (line)
	{
		//while (!search(line, '\n') && *buffer)	// TO PERDIDO QUANTO A COMO TRATAR CASOS ESPECIFICOS DE LINHA INCOMPLETA E ULTIMA LINHA
		while (1)
		{
			if (search(line, '\n') || (size_read < BUFFER_SIZE && ????))
			{
				return (line);
			}
			else
			{
				if (copied_lines == BUFFER_SIZE)
				{
					size_read = write_buffer(fd, buffer);
					copied_lines = 0;
				}
				if(copied_lines < BUFFER_SIZE)
				{
					copied_lines += copy_line(line, buffer + copied_lines, 100);
				}
			}
		}
	}
}
