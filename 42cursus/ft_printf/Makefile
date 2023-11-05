# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 14:44:34 by joseanto          #+#    #+#              #
#    Updated: 2023/11/05 18:37:43 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE =	ft_printf.c\
	ft_printc.c\
	ft_prints.c\
	ft_printp.c\
	ft_printd.c\
	ft_printu.c\
	ft_printx.c
OBJS = $(FILE:.c=.o)
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

all:	$(NAME) $(OBJS)

$(OBJS): $(FILE)
	cc $(FLAGS) -c $(FILE)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 