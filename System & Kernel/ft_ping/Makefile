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

FILE =	ft_ping.c\
	./src/info.c\
	./src/help.c\
	./src/host.c\
	./src/checksum.c\
	./src/icmp.c\
	./src/socket.c\
	./src/send.c\
	./src/receive.c
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

test: $(NAME)
		chmod +x test.sh
		sudo bash ./test.sh

.PHONY: all clean re