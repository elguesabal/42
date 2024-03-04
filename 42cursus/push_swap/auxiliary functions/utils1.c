/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:08:47 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/04 09:08:48 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	len_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] != '\0' && check_char(s1[start], set))
	{
		start++;
	}
	return (start);
}

size_t	len_end(size_t e, size_t s, char const *s1, char const *set)
{
	while (e > s && check_char(s1[e - 1], set))
	{
		e--;
	}
	return (e);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1 || !set)
	{
		return (NULL);
	}
	start = len_start(s1, set);
	end = len_end(ft_strlen(s1), start, s1, set);
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
