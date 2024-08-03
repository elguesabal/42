COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -o
NAME = UnnecessaryViolence
FILE = ./src/main.cpp\
		./src/Weapon.cpp
		# ./src/HumanA.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re