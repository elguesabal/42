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

/**
 * @author VAMPETA
 * @brief INICIA A VARIAVEL info LIMPANDO LIXO DE MEMORIA
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	init_info(t_info *info)
{
	memset(info, 0, sizeof(*info));
	info->pid = (getpid() & 0xFFFF);
	info->sockfd = -1;
}

/**
 * @author VAMPETA
 * @brief PROCURA AS OPCOES DENTRO DOS ARGUMENTOS E MARCA NO STRUCT t_info
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @param argv ARGUMENTOS DO PROGRAMA
*/
void	find_options(t_info *info, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			j = 1;
			while (argv[i][j])
			{
				if (argv[i][j] == 'v')
					info->verbose = 1;
				else if (argv[i][j] == '?')
					info->help = 1;
				else
				{
					printf("ft_ping: invalid option -- '%c'\n", argv[i][j]);
					help();
				}
				j++;
			}
		}
		i++;
	}
}

/**
 * @author VAMPETA
 * @brief PROCURA O HOST DENTRO DOS ARGUMENTOS E PASSA PARA O STRUCT t_info
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @param argv ARGUMENTOS DO PROGRAMA
*/
void	find_host(t_info *info, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			i++;
			continue ;
		}
		if (info->host)
		{
			printf("ft_ping: usage error: Invalid argument count\n");
			exit(USAGE_ERROR);
		}
		info->host = argv[i];
		i++;
	}
	if (!info->host && !info->help)
	{
		printf("ft_ping: usage error: Destination address required\n");
		exit(USAGE_ERROR);
	}
}

/**
 * @author VAMPETA
 * @brief RECEBE OS ARGUMENTOS E ORGANIZA NO PONTEIRO DO STRUCT t_info RECEBIDO
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @param argc NUMERO DE ARGUMENTOS DO PROGRAMA
 * @param argv ARGUMENTOS DO PROGRAMA
*/
void	info_args(t_info *info, int argc, char **argv)
{
	init_info(info);
	if (argc == 1)
	{
		printf("ft_ping: usage error: Destination address required\n");
		exit(USAGE_ERROR);
	}
	find_options(info, argv);
	find_host(info, argv);
}
