# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 01:42:58 by joseanto          #+#    #+#              #
#    Updated: 2024/11/14 01:42:59 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++
INCLUDE = -I ./includes -I ./src
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = BitcoinExchange
FILE = ./main.cpp\
		./BitcoinExchange.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re