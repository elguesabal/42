COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -o
NAME = PhoneBook
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(NAME).cpp

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re