/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:19:23 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/16 15:19:25 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// A função isascii() em C verifica se um caractere está dentro do conjunto
// ASCII (códigos de 0 a 127) e retorna verdadeiro (diferente de zero) se
// estiver, e falso (zero) caso contrário.
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int	main(void)
// {
// 	printf("'a': %d", ft_isascii('a'));
// 	// printf("\n'': %d", ft_isascii(''));
// 	return (0);
// }