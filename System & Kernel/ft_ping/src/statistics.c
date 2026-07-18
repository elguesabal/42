/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:02:59 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/17 17:02:59 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

void	update_statistics(t_info *info)
{
	double	rtt;

	rtt = get_rtt(info);
	info->received++;
	if (info->received == 1)
	{
		info->min_time = rtt;
		info->max_time = rtt;
	}
	else
	{
		if (rtt < info->min_time)
			info->min_time = rtt;
		if (rtt > info->max_time)
			info->max_time = rtt;
	}
	info->total_time += rtt;
	info->total_time_square += rtt * rtt;
}

void	print_statistics(t_info *info)
{
	printf("--- %s ping statistics ---\n", "google.com");
	printf("%i packets transmitted, ", info->transmitted);
	printf("%i packets received, ", info->received);
	printf("%.0f%% packet loss\n", ((info->transmitted - info->received) * 100.0) / info->transmitted);
	printf("round-trip min/avg/max/stddev = 2.373/4.204/5.139/1.295 ms");
	// printf("/");
	// printf("/");
	// printf("/");
	// printf(" ms");
	printf("\n");
}
