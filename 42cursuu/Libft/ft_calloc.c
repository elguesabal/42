/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:54:25 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/25 11:54:27 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>	// TESTAR SE ESSA BIBLIOTECA DECLAR size_t

// A função `calloc()` em C é usada para alocar e inicializar uma área contígua
// de memória para um número específico de elementos, inicializando todos os
//bytes com zero. É útil para alocar memória para arrays ou estruturas de dados
//em tempo de execução.
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

// int	main(void)
// {
// 	int	*n;

// 	n = ft_calloc(1, sizeof(int));
// 	printf("n: %d", *n);
// 	free(n);
// 	return (0);
// }