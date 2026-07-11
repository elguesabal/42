/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:10:16 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/17 07:27:08 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>

# define SUCCESS 0
# define ERROR 1
# define USAGE_ERROR 2

typedef struct s_info
{
	char	*host;
	char	ip[INET_ADDRSTRLEN];
	int		verbose;
	int		help;
}	t_info;

// ./assist/include_string.c

// ./info/info.c
void			find_options(t_info *info, char **argv);
void			find_host(t_info *info, char **argv);
void			info_args(t_info *info, int argc, char **argv);

// ./help/help.c
void			help(void);

// ./resolve/host.c
void			resolve_host(t_info *info);

// ./socket/socket.c
void			test_socket(void);

#endif