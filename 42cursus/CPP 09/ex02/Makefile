COMPILER = c++
INCLUDE = -I ./includes -I ./src
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = PmergeMe
FILE = ./main.cpp\
		./PmergeMe.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re