/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:21:10 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/09 19:42:22 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	get_line(int fd, char *line)
{
	char	c;
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && read(fd, &c, 1) == 1)
	{
		if (c == '\n')
		{
			line[i] = '\n';
			return (i);
		}
		if (c == '\0')
		{
			line[i] = '\0';
			return (i);
		}
		line[i] = c;
		i++;
	}
	if (i == 0)
		return (0);
	else
	{
		line[i] = '\0';
		return (i + 1);
	}
}

char	*get_next_line(int fd)
{
	char		*line;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	if (!get_line(fd, line))
		return (NULL);
	return (line);
}