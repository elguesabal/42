# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 09:25:54 by joseanto          #+#    #+#              #
#    Updated: 2024/02/23 11:21:07 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUX = ./ft_aux/
VERIFICATION = ./verification/
RENDERING = ./rendering/
COMPONENTS = $(RENDERING)components/
EVENTS = ./events/
FILE =	so_long.c\
	$(VERIFICATION)verification1.c\
	$(VERIFICATION)verification2.c\
	$(RENDERING)aux_rendering.c\
	$(RENDERING)map.c\
	$(COMPONENTS)wall.c\
	$(COMPONENTS)coin.c\
	$(COMPONENTS)exit.c\
	$(COMPONENTS)protagonist.c\
	$(EVENTS)key_event.c\
	$(AUX)utils1.c\
	$(AUX)utils2.c
CC = cc
FLAGS = -Wall -Wextra -Werror -o
NAME = so_long
LIB = ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm
RM = rm

all: $(NAME)

$(NAME):
		$(CC) -o $(NAME) $(FILE) $(LIB)

clean:
		$(RM) $(NAME)

re: clean all

.PHONY: all clean re

# cc -o so_long so_long.c ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm ./rendering/map.c ./ft_aux/utils1.c