/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:21:10 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/13 19:17:19 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (!c)
	{
		return ((char *)str);
	}
	return (NULL);
}

static int	get_line(int fd, char *line)
{
	int	size;
	static char	*search;

	if (!line)
		return (0);
	size = read(fd, line, BUFFER_SIZE);
	search = ft_strchr(line, '\n');
	if (size == BUFFER_SIZE && search)
	{
		// PAREI AKI E TO MEIO PERDIDO
		// COMO VOU PEGAR UM ENDERECO DE MEMORIA E CONTINUAR DPS Q ACHAR O '\n' E IR ATE O COMECO DA STRING?
		// TENHO Q RETORNAR SO O COMECO ATE O FIM DA STRING
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*line;
	
	if (!(line = malloc(BUFFER_SIZE + 1 * sizeof(char))))
		return (NULL);
	get_line(fd, line);
	return (line);
}