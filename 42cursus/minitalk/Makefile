# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:24:54 by joseanto          #+#    #+#              #
#    Updated: 2024/01/08 12:21:09 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAMEC = client
NAMES = server
CC = cc
CFLAGS = -Wall -Wextra -Werror -o
RM = rm -rf

all: $(NAME)

$(NAME): $(NAMEC) $(NAMES)

$(NAMEC):
		$(CC) $(CFLAGS) $(NAMEC) client.c

$(NAMES):
		$(CC) $(CFLAGS) $(NAMES) server.c 'bat signal.c'

clean:
		$(RM) $(NAMEC) && $(RM) $(NAMES)

fclean: clean
		clear

re: fclean all

.PHONY: all clean fclean re	