# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 13:34:48 by joseanto          #+#    #+#              #
#    Updated: 2023/10/12 15:22:45 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -c -Wall -Wextra -Werror ./srcs/ft_putchar.c -o ./srcs/ft_putchar.o
	gcc -c -Wall -Wextra -Werror ./srcs/ft_swap.c -o ./srcs/ft_swap.o
	gcc -c -Wall -Wextra -Werror ./srcs/ft_putstr.c -o ./srcs/ft_putstr.o
	gcc -c -Wall -Wextra -Werror ./srcs/ft_strlen.c -o ./srcs/ft_strlen.o
	gcc -c -Wall -Wextra -Werror ./srcs/ft_strcmp.c -o ./srcs/ft_strcmp.o
	ar rc libft.a ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o
	gcc main.c -I./includes -L. -lft

clean:
	rm ./srcs/ft_putchar.o
	rm ./srcs/ft_swap.o
	rm ./srcs/ft_putstr.o
	rm ./srcs/ft_strlen.o
	rm ./srcs/ft_strcmp.o

fclean:	clean
	rm ./libft.a

re:	fclean all

libft.a:	all
