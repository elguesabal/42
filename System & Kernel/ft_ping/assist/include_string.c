/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 19:35:10 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/07 19:35:10 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

unsigned int	include_string(char **array, char *str)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (strcmp(array[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}
