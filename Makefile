# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/06 11:34:08 by rhorace           #+#    #+#              #
#    Updated: 2026/09/11 17:28:20 by sohollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := cub3D

CC      := cc
CFLAGS  := -g -Wall -Wextra -Werror -Iincludes -Iminilibx-linux

MLX_DIR := minilibx-linux
MLX_A   := $(MLX_DIR)/libmlx.a
MLX_LNK := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS    := sources/main.c \
	sources/checks/check_extension.c \
	sources/checks/check_map_closed.c \
	sources/checks/check_player_count.c \
	sources/checks/the_verificator.c \
	sources/cleanup/close_cub3d.c \
	sources/debug/print_info.c \
	sources/events/game_loop.c \
	sources/events/movement.c \
	sources/events/rotation.c \
	sources/get_next_line/get_next_line.c \
	sources/get_next_line/gnl_utils.c \
	sources/graphics/textures.c \
	sources/init/init_cub3d.c \
	sources/init/init_mlx.c \
	sources/init/init_player.c \
	sources/parsing/get_texture_path.c \
	sources/parsing/get_the_color.c \
	sources/parsing/manage_line.c \
	sources/parsing/is_ready.c \
	sources/parsing/map_node.c \
	sources/parsing/pad_map_line.c \
	sources/parsing/read_file.c \
	sources/raycharlesing/affichage_utils.c \
	sources/raycharlesing/mur.c \
	sources/raycharlesing/paf.c \
	sources/raycharlesing/rendu.c \
	sources/raycharlesing/tarzan_utils.c \
	sources/utils/ft_utils_2.c \
	sources/utils/ft_utils.c \
	sources/utils/utils_2.c \
	sources/utils/utils_maths.c \
	sources/utils/utils.c
 	
#	sources/graphics/pixel.c \
# 	sources/graphics/background.c \
# 	sources/graphics/draw_wall.c \

OBJS    := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MLX_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) -o $(NAME)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c includes/cub3D.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
