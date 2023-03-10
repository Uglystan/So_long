# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 11:23:58 by lgirault          #+#    #+#              #
#    Updated: 2023/01/18 16:47:26 by lgirault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
Ldflags = -lmlx -lX11 -lXext -lz -lm
LIBFT_PATH = ./libft/
MLX_PATH = ./mlx_linux/
Libs = -L./mlx_linux
LIBFT = libft/libft.a
RM = rm -rf

SRC =	main.c \
	fonctions/map.c \
	fonctions/render.c \
	fonctions/move_ennemi_player.c \
	fonctions/check.c \
	fonctions/event.c \
	fonctions/utils.c \
	fonctions/backtracking.c \
	fonctions/backtracking_col.c \
	fonctions/free.c \
	fonctions/lst_collect.c \

OBJ = $(SRC:.c=.o)

$(NAME): init $(OBJ)
	$(CC) $(CFLAGS) $(Libs) $(OBJ) $(LIBFT) -o $(NAME) $(Ldflags)

all: $(NAME)

init: 
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)


clean: $(clean)
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: init all clean fclean re