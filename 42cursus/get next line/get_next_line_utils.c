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
