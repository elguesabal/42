/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:08:50 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/27 09:08:52 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	check_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	len_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] != '\0' && check_char(s1[start], set))
		start++;
	return (start);
}

static size_t	len_end(size_t e, size_t s, char const *s1, char const *set)
{
	while (e > s && check_char(s1[e - 1], set))
		e--;
	return (e);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*r;

	if (!s1 || !set)
		return (NULL);
	start = len_start(s1, set);
	end = len_end(ft_strlen(s1), start, s1, set);
	r = malloc(sizeof(char) * (end - start + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (start < end)
	{
		r[i] = s1[start];
		i++;
		start++;
	}
	r[i] = '\0';
	return (r);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("return: %s\n", ft_strtrim("ehjjtestehje", "ejh"));
// 	return (0);
// }