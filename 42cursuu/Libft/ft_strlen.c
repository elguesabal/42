/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:54:27 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/16 15:54:31 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;
	
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	printf("teste: %ld", ft_strlen("teste"));
	return (0);
}
