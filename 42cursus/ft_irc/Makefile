COMPILER = c++
INCLUDE = -I ./includes
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDE) -o
NAME = ircserv
FILE = ./ft_irc.cpp\
		./src/verification.cpp\
		./src/signal.cpp\
		./class/Server/Server.cpp\
		./class/Server/cmdsServer.cpp\
		./class/Server/getServer.cpp\
		./class/Server/utils/nick.cpp\
		./class/Server/utils/utils.cpp\
		./class/Client/Client.cpp\
		./class/Client/getClient.cpp
RM = rm

all: $(NAME)

$(NAME):
		$(COMPILER) $(FLAGS) $(NAME) $(FILE)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re