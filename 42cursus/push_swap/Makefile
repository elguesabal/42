# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 12:34:30 by joseanto          #+#    #+#              #
#    Updated: 2024/01/30 10:37:49 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUX = ./'auxiliary functions'/
STACK = ./'stack operations'/
CHECK = ./check/
FILE =	push_swap.c\
	$(AUX)insert_stack.c\
	$(AUX)remove_stack.c\
	$(STACK)operations_part1.c\
	$(STACK)operations_part2.c\
	$(STACK)operations_part3.c\
	$(CHECK)stack_check.c\
	$(AUX)func_assist.c\
	$(AUX)utils.c
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -o
RM = rm

all: $(NAME) $(OBJS)

$(NAME):
		$(CC) $(CFLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

.PHONY: all clean re

# gcc -o push_swap push_swap.c ./'auxiliary functions'/insert_stack.c ./'auxiliary functions'/remove_stack.c ./'stack operations'/operations_part1.c ./'stack operations'/operations_part2.c ./'stack operations'/operations_part3.c ./'stack operations'/stack_check.c ./'auxiliary functions'/func_assist.c ./'auxiliary functions'/utils.c