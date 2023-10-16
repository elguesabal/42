/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:27:33 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/11 19:52:10 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	//printf("%s", str);
	int	i;
	
	while (str)
	{
		printf("%c", str[i]);
		i++;
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;
	t_stock_str	*stock;

	stock = malloc(sizeof(t_stock_str) * ac);

	i = 0;
	while (i < ac)
	{
		// stock->size = 
		ft_strlen(av[i]);
		// printf("%s ", av[i]);
		i++;
	}

	// stock.size = ac;
	// stock.str = *av[1];
	// stock.copy = *av[1];
	// return (stock);
}

int	main(int argc, char *argv[])
{
	t_stock_str	*stock;
	
	stock = malloc(sizeof(t_stock_str) * argc);
	
	// *stock = 
	ft_strs_to_tab(argc, argv);
	//printf("%s", argv[0]);

	// printf("%d", ft_strs_to_tab(argc, argv).size);
	
	// free(stock);
	return (0);
}
