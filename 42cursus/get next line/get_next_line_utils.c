/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:21:34 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/09 11:21:35 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (!c)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *rest_line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!rest_line)
	{
		rest_line = (char *)malloc(1 * sizeof(char));
		rest_line[0] = '\0';
	}
	if (!rest_line || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(rest_line) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (rest_line)
		while (rest_line[++i])
			str[i] = rest_line[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[ft_strlen(rest_line) + ft_strlen(buffer)] = '\0';
	free(rest_line);
	return (str);
}

char	*get_line(char *rest_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!rest_line[i])
		return (NULL);
	while (rest_line[i] && rest_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest_line[i] && rest_line[i] != '\n')
	{
		str[i] = rest_line[i];
		i++;
	}
	if (rest_line[i] == '\n')
	{
		str[i] = rest_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_line(char *rest_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rest_line[i] && rest_line[i] != '\n')
		i++;
	if (!rest_line[i])
	{
		free(rest_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rest_line[i])
		str[j++] = rest_line[i++];
	str[j] = '\0';
	free(rest_line);
	return (str);
}

char	*read_rest_line(int fd, char *rest_line)
{
	char	*buffer;
	int		rd_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(rest_line, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd_bytes] = '\0';
		rest_line = ft_strjoin(rest_line, buffer);
	}
	free(buffer);
	return (rest_line);
}