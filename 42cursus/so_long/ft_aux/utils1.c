/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:24:47 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/23 16:46:43 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	putnbr(unsigned int n)
{
	if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

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

int	size_j(void)
{
	int	count;

	count = 0;
	while (MAP[count][0])
		count++;
	return (count);
}

int	size_i(void)
{
	int	count;

	count = 0;
	while (MAP[0][count])
		count++;
	return (count);
}

int	error(char *str)
{
	perror(str);
	return (1);
}

// void	copy_map(char **map)
// {
// 	int	j;
// 	int	i;

// 	j = 0;
// 	i = 0;
// 	while (MAP[j][i])
// 	{
// 		while (MAP[j][i])
// 		{
// 			map[j][i] = MAP[j][i];
// 			i++;
// 			// if (MAP[j][i] == '\0')
// 			// 	map[j][i] = MAP[j][i];
// 			map[j][i] = MAP[j][i];
// 		}
// 		i = 0;
// 		j++;
// 		// if (MAP[j][i] == '\0')
// 		// 	map[j][i] = MAP[j][i];
// 		map[j][i] = MAP[j][i];
// 	}
// }