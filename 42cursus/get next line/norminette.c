/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:15:40 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/16 11:19:44 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_index;
	static int	buffer_size;
	char		*line;
	int			line_size;
	char		current_char;

	line = NULL;
	line_size = 0;
	while (1)
	{
		if (buffer_index == buffer_size)
		{
			buffer_size = read(fd, buffer, BUFFER_SIZE);
			if (buffer_size == 0 && line_size > 0)
				return (line);
			buffer_index = 0;
		}
		while (buffer_index < buffer_size)
		{
			current_char = buffer[buffer_index++];
			if (current_char == '\n')
			{
				line = realloc(line, line_size + 1);
				line[line_size] = '\0';
				return (line);
			}
			else
			{
				line = realloc(line, line_size + 1);
				line[line_size++] = current_char;
			}
		}
	}
}
