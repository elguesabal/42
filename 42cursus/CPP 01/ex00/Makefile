COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -o
NAME = BraiiiiiiinnnzzzZ
FILE = ./src/main.cpp\
		./src/Zombie.cpp\
		./src/newZombie.cpp\
		./src/randomChump.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re