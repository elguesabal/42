EVENTS = ./events/
UTILS = ./utils/
FILE =	cub3D.c\
	$(EVENTS)keyboard.c\
	$(EVENTS)close_win.c\
	$(UTILS)map_reading.c\
	$(UTILS)memory.c
CC = cc
FLAGS = -Wall -Wextra -Werror -o
NAME = cub3D
LIB = ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm
RM = rm

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(NAME) $(FILE) $(LIB)

clean:
		$(RM) $(NAME)

re: clean all

fclean:	clean

.PHONY: all clean re
