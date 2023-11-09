# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 10:55:16 by joseanto          #+#    #+#              #
#    Updated: 2023/11/09 12:10:37 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE =	get_next_line.c
OBJS = $(FILE:.c=.o)
NAME = libgetnextline.a
FLAGS = -Wall -Wextra -Werror

all:	$(NAME) $(OBJS)

$(OBJS): $(FILE)
	cc $(FLAGS) -D BUFFER_SIZE=1 $(FILE) -c

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 