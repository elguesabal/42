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

/**
 * @author VAMPETA
 * @brief ATUALIZA OS DADOS USADOS PARA ESTATISTICAS
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	update_statistics(t_info *info)
{
	double	rtt;

	gettimeofday(&info->receive_time, NULL);
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

/**
 * @author VAMPETA
 * @brief PRINTA AS ESTATISTICAS FORMATADA
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	print_statistics(t_info *info)
{
	double	loss;
	double	avg;
	double	variance;

	printf("--- %s ping statistics ---\n", info->host);
	printf("%i packets transmitted, ", info->transmitted);
	printf("%i packets received, ", info->received);
	if (info->received == 0)
	{
		printf("100%% packet loss\n");
		return ;
	}
	loss = (info->transmitted - info->received) * 100.0 / info->transmitted;
	printf("%.0f%% packet loss\n", loss);
	avg = info->total_time / info->received;
	variance = (info->total_time_square / info->received) - (avg * avg);
	if (variance < 0)
		variance = 0;
	printf("round-trip min/avg/max/stddev = ");
	printf("%.3f/", info->min_time);
	printf("%.3f/", avg);
	printf("%.3f/", info->max_time);
	printf("%.3f ms", sqrt(variance));
	printf("\n");
}
