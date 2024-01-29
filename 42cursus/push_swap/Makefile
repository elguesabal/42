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
	./'auxiliary functions'/insert_stack.c\
	./'stack operations'/operations_part1.c\	# ASSIM Q FAZ NO MAKE??
	./'stack operations'/operations_part2.c\
	./'stack operations'/operations_part3.c\
	./'auxiliary functions'/remove_stack.c\
	./'auxiliary functions'/func_assist.c\
	./'auxiliary functions'/utils.c
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

# gcc -o push_swap push_swap.c ./'auxiliary functions'/insert_stack.c ./'auxiliary functions'/remove_stack.c ./'stack operations'/operations_part1.c ./'stack operations'/operations_part2.c ./'stack operations'/operations_part3.c ./'auxiliary functions'/func_assist.c ./'auxiliary functions'/utils.c