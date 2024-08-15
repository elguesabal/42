COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -o
NAME = ex05
FILE = ./main.cpp\
		./harl.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re