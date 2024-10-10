COMPILER = c++
INCLUDE = -I ./includes -I ./src
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = Span
FILE = ./main.cpp\
		./Span.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re