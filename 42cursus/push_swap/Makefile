# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 12:34:30 by joseanto          #+#    #+#              #
#    Updated: 2024/03/01 18:21:52 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUX = ./'auxiliary functions'/
STACK = ./'stack operations'/
ALGORITHM = ./algorithm/
FILE =	push_swap.c\
	$(AUX)insert_stack.c\
	$(AUX)remove_stack.c\
	$(STACK)operations_part1.c\
	$(STACK)operations_part2.c\
	$(STACK)operations_part3.c\
	$(ALGORITHM)algorithm1.c\
	$(ALGORITHM)algorithm2.c\
	$(AUX)func_assist1.c\
	$(AUX)func_assist2.c\
	$(AUX)utils1.c\
	$(AUX)utils2.c\
	$(AUX)utils3.c
NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -o
RM = rm

all: $(NAME) $(OBJS)

$(NAME):
		$(CC) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

.PHONY: all clean re

# gcc -o push_swap push_swap.c ./'auxiliary functions'/insert_stack.c ./'auxiliary functions'/remove_stack.c ./'stack operations'/operations_part1.c ./'stack operations'/operations_part2.c ./'stack operations'/operations_part3.c ./check/stack_check_part1.c ./check/stack_check_part2.c ./'auxiliary functions'/func_assist.c ./'auxiliary functions'/utils1.c ./'auxiliary functions'/utils2.c ./'auxiliary functions'/utils3.c