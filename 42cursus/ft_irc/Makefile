COMPILER = c++
INCLUDE = -I ./includes
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = ircserv
FILE = ./ft_irc.cpp\
		./src/verification.cpp\
		./src/signal.cpp\
		./src/new_client.cpp\
		./src/password.cpp\
		./class/client.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re