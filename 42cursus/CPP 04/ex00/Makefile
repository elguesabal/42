COMPILER = c++
INCLUDE = -I ./includes
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = Animal
FILE = ./src/main.cpp\
		./src/Animal.cpp\
		./src/Dog.cpp\
		./src/Cat.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re