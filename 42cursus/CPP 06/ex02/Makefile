# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 01:40:29 by joseanto          #+#    #+#              #
#    Updated: 2024/11/14 01:40:30 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++
INCLUDE = -I ./
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = Identify
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