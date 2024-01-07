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

FLAGS = -Wall -Wextra -Werror -o

all:	compilation

compilation: $(FILE)
	cc $(FLAGS) server server.c 'bat signal.c'
	cc $(FLAGS) client client.c

clean:
	rm -f server client

re: clean all

.PHONY: all clean re 