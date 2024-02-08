# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 09:25:54 by joseanto          #+#    #+#              #
#    Updated: 2024/02/08 10:04:53 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE =	so_long.c
LIB = ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -o
RM = rm

all: $(NAME)

$(NAME):
		$(CC) -o $(NAME) $(FILE) $(LIB)

clean:
		$(RM) $(NAME)

re: clean all

.PHONY: all clean re

# cc -o so_long so_long.c ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm