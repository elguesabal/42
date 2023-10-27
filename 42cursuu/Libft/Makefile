# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 17:45:30 by joseanto          #+#    #+#              #
#    Updated: 2023/10/27 17:45:32 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE =	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c
OBJS = $(FILE:.c=.o)
NAME = libft.a
FLAGS = -Wall -Wextra -Werror

all:	$(NAME) $(OBJS)

$(OBJS): $(FILE)
	cc $(FLAGS) -c $(FILE)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# NAO SEI PQ MAS O PRIMEIRO NAO TAVA FUNCIONANDO E VOLTO DO NADA

# # Lista de arquivos de origem
# FILE =	ft_isalpha.c\
# 	ft_isdigit.c\
# 	ft_isalnum.c\
# 	ft_isascii.c\
# 	ft_isprint.c\
# 	ft_strlen.c\
# 	ft_memset.c\
# 	ft_bzero.c\
# 	ft_memcpy.c\
# 	ft_memmove.c\
# 	ft_strlcpy.c\
# 	ft_strlcat.c\
# 	ft_toupper.c\
# 	ft_tolower.c\
# 	ft_strchr.c\
# 	ft_strrchr.c\
# 	ft_strncmp.c\
# 	ft_memchr.c\
# 	ft_memcmp.c\
# 	ft_strnstr.c\
# 	ft_atoi.c\
# 	ft_calloc.c\
# 	ft_strdup.c\
# 	ft_substr.c\
# 	ft_strjoin.c\
# 	ft_strtrim.c\
# 	ft_split.c\
# 	ft_itoa.c\
# 	ft_strmapi.c\
# 	ft_striteri.c\
# 	ft_putchar_fd.c\
# 	ft_putstr_fd.c\
# 	ft_putendl_fd.c\
# 	ft_putnbr_fd.c

# # Lista de objetos correspondentes aos arquivos de origem
# OBJS = $(FILE:.c=.o)

# # Nome da biblioteca
# NAME = libft.a

# # Flags do compilador
# FLAGS = -Wall -Wextra -Werror

# # Regra padrão para compilar todos os objetos
# all: $(NAME)

# # Regra para compilar cada arquivo de origem individualmente
# %.o: %.c
# 	cc $(FLAGS) -c $< -o $@

# # Regra para criar a biblioteca
# $(NAME): $(OBJS)
# 	ar rcs $(NAME) $(OBJS)

# # Regra para limpar os arquivos de objeto
# clean:
# 	rm -f $(OBJS)

# # Regra para limpar os arquivos de objeto e a biblioteca
# fclean: clean
# 	rm -f $(NAME)

# # Regra para recompilar tudo
# re: fclean all