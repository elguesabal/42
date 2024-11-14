# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 01:41:26 by joseanto          #+#    #+#              #
#    Updated: 2024/11/14 01:41:27 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++
INCLUDE = -I ./
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = iter
FILE = ./main.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re