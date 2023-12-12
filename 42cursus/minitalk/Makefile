# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:24:54 by joseanto          #+#    #+#              #
#    Updated: 2023/12/12 14:25:26 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE =	client.c\
	server.c
OBJS = $(FILE:.c=.o)
NAME = libminitalk.a
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