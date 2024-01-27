# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 12:34:30 by joseanto          #+#    #+#              #
#    Updated: 2024/01/26 13:56:39 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE =	push_swap.c\
	insert_stack.c\
	remove_stack.c\
	func_assist.c\
	utils.c
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -o
RM = rm -rf

all: $(NAME) $(OBJS)

$(NAME):
		$(CC) $(CFLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

.PHONY: all clean re

# gcc -o push_swap push_swap.c insert_stack.c remove_stack.c func_assist.c utils.c