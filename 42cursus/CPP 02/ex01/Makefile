# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 01:27:32 by joseanto          #+#    #+#              #
#    Updated: 2024/11/14 01:27:33 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -o
NAME = ex01
FILE = ./main.cpp\
		./Fixed.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re