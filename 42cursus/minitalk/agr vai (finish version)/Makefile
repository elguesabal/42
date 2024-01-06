# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:24:54 by joseanto          #+#    #+#              #
#    Updated: 2023/12/12 14:25:26 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE =	client\
	server
OBJS = $(FILE:.c)
NAME = libminitalk.a
FLAGS = -Wall -Wextra -Werror -c

all:	$(NAME) $(OBJS)

$(OBJS): $(FILE)
	cc $(FLAGS) $(FILE) $(FILE)

clean:
	rm -f server client

re: fclean all

.PHONY: all clean fclean re 