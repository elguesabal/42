COMPILER = c++
INCLUDE = -I ./includes
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = DiamondTrap
FILE = ./src/main.cpp\
		./src/ClapTrap.cpp\
		./src/ScavTrap.cpp\
		./src/FragTrap.cpp\
		./src/DiamondTrap.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re