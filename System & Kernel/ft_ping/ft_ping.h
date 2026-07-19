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
# include <netinet/ip_icmp.h>
# include <unistd.h>
# include <errno.h>
# include <signal.h>
# include <sys/time.h>
# include <math.h>

# define ICMP_PAYLOAD_SIZE 56
# define ICMP_PACKET_SIZE 64
# define RECEIVE_BUFFER_SIZE 1500
# define SUCCESS 0
# define ERROR 1
# define USAGE_ERROR 2
# define WAIT 3

typedef struct s_info
{
	uint16_t			pid;
	char				*host;
	struct sockaddr_in	addr;
	char				ip[INET_ADDRSTRLEN];
	int					verbose;
	int					help;
	uint16_t			sequence;
	struct timeval		send_time;
	struct timeval		receive_time;
	unsigned int		transmitted;
	unsigned int		received;
	unsigned int		lost_packets;
	double				min_time;
	double				max_time;
	double				total_time;
	double				total_time_square;
	char				packet[ICMP_PACKET_SIZE];
	int					sockfd;
	char				recv_buffer[RECEIVE_BUFFER_SIZE];
	struct iphdr		*recv_ip;
	struct icmphdr		*recv_icmp;
}	t_info;

// ./src/info.c
void		init_info(t_info *info);
void		find_options(t_info *info, char **argv);
void		find_host(t_info *info, char **argv);
void		info_args(t_info *info, int argc, char **argv);

// ./src/help.c
void		help(void);

// ./src/host.c
void		resolve_host(t_info *info);

// ./src/checksum.c
uint16_t	checksum(void *data, size_t len);

// ./src/icmp.c
void		build_icmp(t_info *info);

// ./src/socket.c
void		create_sockfd(t_info *info);
void		close_sockfd(t_info *info);

// ./src/ping.c
void		start_ping(t_info *info);

// ./src/send.c
ssize_t		send_ping(t_info *info);

// ./src/receive.c
void		error_verbose(t_info *info);
int			is_our_echo(t_info *info, struct icmphdr *icmp);
int			validate_icmp(t_info *info);
int			validate_bytes(t_info *info, ssize_t bytes);
int			receive_ping(t_info *info);

// ./src/print_ping.c
double		get_rtt(t_info *info);
void		print_ping(t_info *info);

// ./src/signal.c
void		stop_ping(int sig);
int			stop_requested(void);

// ./src/statistics.c
void		update_statistics(t_info *info);
void		print_statistics(t_info *info);

#endif