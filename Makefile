# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/06 11:34:08 by rhorace           #+#    #+#              #
#    Updated: 2026/08/07 09:12:01 by rhorace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := cub3D

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Iincludes -Iminilibx-linux

MLX_DIR := minilibx-linux
MLX_A   := $(MLX_DIR)/libmlx.a
MLX_LNK := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS    := sources/main.c \
	checks/check_map_closed.c \
	checks/check_player_count.c \
	checks/check_extension.c \
	cleanup/close_cub3d.c \
	utils/ft_utils_2.c \
	utils/ft_utils.c \
	sources/is_ready.c \
	events/key_press.c \
	events/key_release.c \
	sources/get_next_line_utils.c \
	sources/get_next_line.c \
	debug/print_etat.c \
	debug/print_map.c \
	sources/read_line.c \
	sources/map_node.c \
	utils/utils.c \
	utils/utils_2.c \
	sources/get_the_color.c \
	sources/get_the_path.c \
	sources/get_the_map.c \
	sources/pad_map_line.c \
	sources/the_verificator.c

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
