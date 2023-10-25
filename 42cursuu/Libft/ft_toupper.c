/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:35:55 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 16:35:57 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// A função `toupper()` em C é usada para converter um caractere minúsculo para
// maiúsculo. Se o caractere passado como argumento for uma letra minúscula, a
// função retorna a versão maiúscula da letra. Se o caractere não for uma letra
// minúscula, a função retorna o mesmo caractere sem modificação.
int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
	{
		c -= 32;
	}
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'a';
// 	printf("%c", ft_toupper(c));
// 	return (0);
// }