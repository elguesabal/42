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
	int	return_read;

// while (1)
// {
// 	read(fd, &c, 1);	// CASO O READ CONTINUE SE REPETINDO MESMO APOR O ARQUIVO CHEGAR AO FIM ELE REPETE INFINITAMENTE O ULTIMO CARACTER
// 	printf("%c", c);
// }
	i = 0;
	while (i < BUFFER_SIZE && (return_read = read(fd, &c, 1)) == 1)
	{
		if (c == '\n')
		{
			line[i] = '\n';
			return (i);
		}
		if (!return_read)	// UM ARQUIVO TXT NAO TERMINA COM '\0'
		{
			line[i] = '\0';
			return (i);
		}
		line[i] = c;
// printf("%d ", return_read);
		i++;
	}
// printf("%d", return_read);
	while (c != '\n' && read(fd, &c, 1) == 1) // AINDA NAO SEI SE DEVO TRATAR SE O BUFFER FOR MENOR Q A LINHA
	{
		// read(fd, &c, 1);
		if (c == '\n') // DEVO COLOCAR '\n' SE O BUFFER NAO PERMITIR LER ATE O FIM DA LINA?
		{
			line[i] = '\n';
			i++;
		}
//printf("a");	// UM ARQUIVO TXT NAO TERMINA COM '\0'
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