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