/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:46:28 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/16 15:46:30 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int c)
{
	// if (c > 31 && c < 127)
	// {
	//	return (1);
	// }
	//return (0);
	return (c > 31 && c < 127);
}

int	main(void)
{
	printf("'a': %d", ft_isprint('a'));
	printf("\n'\t (tab)': %d", ft_isprint('\t'));
	printf("\n'': %d", ft_isprint(''));
	return (0);
}
