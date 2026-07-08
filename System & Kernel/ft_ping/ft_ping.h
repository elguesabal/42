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

# define SUCCESS 0
# define ERROR 1
# define USAGE_ERROR 2

typedef struct s_args
{
	char	*host;
	int		verbose;
	int		help;
}	t_args;

// ./assist/include_string.c

// ./args/info.c
void			find_options(t_args *info, char **argv);
void			find_host(t_args *info, char **argv);
void			info_args(t_args *info, int argc, char **argv);

// ./help/help.c
void			help(void);

#endif