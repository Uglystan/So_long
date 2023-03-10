# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 10:21:20 by lgirault          #+#    #+#              #
#    Updated: 2023/01/18 10:21:23 by lgirault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf
SRC =		ft_strlenn.c \
	ft_strjoin.c \
	ft_split.c \
	ft_itoa.c \
	get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line.c \
	printf/ft_printf.c \
	printf/ft_putchar.c \
	printf/ft_putnb_base.c \
	printf/ft_putnbr_unsi.c \
	printf/ft_putnbr.c \
	printf/ft_putstr.c \
	printf/ft_putvoid.c \
	
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re