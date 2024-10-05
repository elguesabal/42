COMPILER = c++
INCLUDE = -I ./includes
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = array
FILE = ./src/main.cpp\
		./src/
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re