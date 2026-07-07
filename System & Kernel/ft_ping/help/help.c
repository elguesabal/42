/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:47:46 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/07 18:47:46 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

void	help(void)
{
	printf("\n");
	printf("Usage\n");
	printf("  ping [options] <destination>\n");
	printf("\n");
	printf("Options:\n");
	printf("  <destination>      dns name or ip address\n");
	printf("  -v                 verbose output\n");
	exit(0);
}