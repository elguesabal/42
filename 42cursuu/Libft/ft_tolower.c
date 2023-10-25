/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:11:28 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 18:11:29 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// A função `tolower()` em C é usada para converter um caractere maiúsculo para
// minúsculo. Se o caractere passado como argumento for uma letra maiúscula, a
// função retorna a versão minúscula da letra. Se o caractere não for uma letra
// maiúscula, a função retorna o mesmo caractere sem modificação.
int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		c += 32;
	}
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'A';
// 	printf("%c", ft_tolower(c));
// 	return (0);
// }