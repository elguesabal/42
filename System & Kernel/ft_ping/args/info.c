/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:28:57 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/07 18:28:57 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

void	info_args(t_args *info, int argc, char **argv)
{
	info->host = NULL;
	info->verbose = 0;
	info->help = 0;
	if (argc == 1)
	{
		printf("ft_ping: usage error: Destination address required\n");
		exit(USAGE_ERROR);
	}
	if (argc > 3)
	{
		printf("ft_ping: usage error: Invalid argument count\n");
		exit(USAGE_ERROR);
	}
	if (include_string(argv, "-?"))
		info->help = 1;
	if (include_string(argv, "-v"))
		info->verbose = 1;
}
