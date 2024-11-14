# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 01:39:20 by joseanto          #+#    #+#              #
#    Updated: 2024/11/14 01:39:21 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++
INCLUDE = -I ./includes
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = Bureaucrat
FILE = ./src/main.cpp\
		./src/Bureaucrat.cpp\
		./src/AForm.cpp\
		./src/ShrubberyCreationForm.cpp\
		./src/RobotomyRequestForm.cpp\
		./src/PresidentialPardonForm.cpp\
		./src/Intern.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re