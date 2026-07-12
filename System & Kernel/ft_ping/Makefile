# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/07 16:33:11 by joseanto          #+#    #+#              #
#    Updated: 2026/07/07 16:33:11 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASSIST = ./assist/
ARGS = ./args/
HELP = ./help/
RESOLVE = ./resolve/
SOCKET = ./socket/
CHECKSUM = ./checksum/
ICMP = ./icmp/
FILE =	ft_ping.c\
	$(ARGS)info.c\
	$(HELP)help.c\
	$(RESOLVE)host.c\
	$(CHECKSUM)checksum.c\
	$(SOCKET)socket.c\
	$(ICMP)icmp.c
CC = cc
FLAGS = -Wall -Wextra -Werror -o
NAME = ft_ping
RM = rm

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re