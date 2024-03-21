# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 08:43:32 by joseanto          #+#    #+#              #
#    Updated: 2024/03/21 14:38:36 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO = ./philosopher/
AUX = ./func_aux/
FILE =	philosophers.c\
	$(PHILO)philosopher.c\
	$(PHILO)assistant.c\
	$(AUX)verification.c\
	$(AUX)utils1.c\
	$(AUX)utils2.c
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