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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest_line = read_rest_line(fd, rest_line);
	if (!rest_line)
		return (NULL);
	line = get_line(rest_line);
	rest_line = new_line(rest_line);
	return (line);
}