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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc((len1 + len2 + 1) * sizeof(char *));
	if (new_str)
	{
		new_str[len1 + len2] = '\0';
		while (len2--)
		{
			new_str[len1 + len2] = s2[len2];
		}
		while (len1--)
		{
			new_str[len1] = s1[len1];
		}
	}
	return (new_str);
}

// size_t	search(const char *str, char c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] && str[i] != c)
// 	{
// 		i++;
// 	}
// 	// if (!str[i])
// 	// 	return (0);
// 	i++;
// 	return (i);
// }

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
// 	// if (count > len)
// 	// 	return;
// 	i = 0;
// 	while (i < count)
// 	{
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

// static void	move_and_remove(char *line, char *buffer)
// {
// 	size_t	len_line;	// ARMAZENA O TAMANHO
// 	size_t	line_break;	// ARMAZENA QUANTOS CARACTERES TEM ATE O '\n' OU '\0'
// 	size_t	i;

// 	if (!line || !buffer)	// VERIFICA SE FOI ALOCADO ESPACO DE MEMORIA
// 		return;

// 	len_line = ft_strlen(line);	// RETORNA O TAMANHO
// 	line_break = search(buffer, '\n');	// RETORNA A QUANTIDADES DE CARACTERES DO COMECO ATE '\n' OU '\0'

// 	i = 0;
// 	while (*buffer && *buffer != '\n')
// 	{
// 		line[len_line] = *buffer;
// 		len_line++;
// 		buffer++;
// 	}
// 	line[len_line] = *buffer;
// //printf("%s", line);
// }

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char	*backup;
	char		*line;
	int		size_read;

	line = NULL;
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buffer)
		{
			backup = buffer;	// COPIA DO ENDERECO INICIAL PRA DPS DAR FREE
			size_read = read(fd, buffer, BUFFER_SIZE);
			buffer[size_read] = '\0';
		}
	}

	line = ft_calloc(100, sizeof(char));
	if (line)
	{
		// move_and_remove(line, buffer, size_line(buffer));
		// move_and_remove(line, buffer);
		
	}

	// while (1)
	// {
	// 	if (!*buffer)
	// 	{
	// 		size_read = read(fd, buffer, BUFFER_SIZE);
	// 		buffer[size_read] = '\0';
	// 		if (size_read && !search(line) && !*line)
	// 		{
	// 			move_and_remove(line, buffer, size_line(buffer));
	// 		}
	// 	}

	// 	if (!*line || !search(line))
	// 	{
	// 		move_and_remove(line, buffer, size_line(buffer));	// APARENTEMENTE QUANDO CHEGA NA ULTIMA LINHA E ELA TEM SO '\n' ELA NAO RETORNA NADA
	// 	}

	// 	if (search(line) || (!search(line) && size_read < BUFFER_SIZE))
	// 	{
	// 		return (line);	// NA ULTIMA SE FOR APENAS UM '\n' ELA NAO RETORNA NADA
	// 	}
	// }
	return (line);
}
