# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 08:43:32 by joseanto          #+#    #+#              #
#    Updated: 2024/03/04 09:04:20 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUX = ./func_aux/
FILE =	philosophers.c\
	$(AUX)utils1.c
CC = cc
FLAGS = -Wall -Wextra -Werror -o
NAME = philosophers
RM = rm

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re