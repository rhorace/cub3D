# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/06 11:34:08 by rhorace           #+#    #+#              #
#    Updated: 2026/08/07 11:03:53 by rhorace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := cub3D

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Iincludes -Iminilibx-linux

MLX_DIR := minilibx-linux
MLX_A   := $(MLX_DIR)/libmlx.a
MLX_LNK := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS    := sources/main.c \
	sources/checks/check_map_closed.c \
	sources/checks/check_player_count.c \
	sources/checks/check_extension.c \
	sources/cleanup/close_cub3d.c \
	sources/utils/ft_utils_2.c \
	sources/utils/ft_utils.c \
	sources/parsing/is_ready.c \
	sources/events/key_press.c \
	sources/events/key_release.c \
	sources/get_next_line/get_next_line_utils.c \
	sources/get_next_line/get_next_line.c \
	sources/debug/print_etat.c \
	sources/debug/print_map.c \
	sources/parsing/read_line.c \
	sources/parsing/map_node.c \
	sources/utils/utils.c \
	sources/utils/utils_2.c \
	sources/parsing/get_the_color.c \
	sources/parsing/get_the_path.c \
	sources/parsing/get_the_map.c \
	sources/parsing/pad_map_line.c \
	sources/checks/the_verificator.c

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
