/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:51:08 by joseanto          #+#    #+#             */
/*   Updated: 2023/12/19 19:40:20 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t		i;
	char		*d;
	char		*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str && *str > 47 && *str < 58)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}




void	send_signal(unsigned long long p, int pid)
{
	int	i;
	int	bi;

	printf("%llu", p);
	while (p > 0) {
		bi = p % 2;
		p = p / 2;
		if (bi)
		{
			// kill(SIGUSR1, pid);
printf("%d", bi);
		}
		else
		{
			// kill(SIGUSR2, pid);
printf("%d", bi);
		}
    }
}

int	main(int argc, char **argv)
{
	char	*str;
	int	i;

	str = malloc(ft_strlen(argv[2]) * sizeof(char));
	ft_memcpy(str, argv[2], ft_strlen(argv[2]));
	send_signal((unsigned long long)str, ft_atoi(argv[1]));
//printf("%s", str);
	// sleep(5);
	return (0);
}