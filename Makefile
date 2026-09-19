# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/06 11:34:08 by rhorace           #+#    #+#              #
#    Updated: 2026/09/18 17:28:45 by sohollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3D

CC			:= cc
CFLAGS		:= -g -Wall -Wextra -Werror
INCLUDES	:= -Iincludes -Iminilibx-linux

MLX_DIR		:= minilibx-linux
MLX_A		:= $(MLX_DIR)/libmlx.a
MLX_LNK		:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# ============================================================================ #
#                              COMMON SOURCES                                  #
# ============================================================================ #

COMMON_SRCS	:= \
	sources/checks/check_extension.c \
	sources/checks/check_map_closed.c \
	sources/checks/check_player_count.c \
	sources/checks/the_verificator.c \
	sources/cleanup/close_cub3d.c \
	sources/debug/print_info.c \
	sources/events/game_loop.c \
	sources/events/movement.c \
	sources/events/collisions.c \
	sources/events/anticipate_collision.c \
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
	sources/raycharlesing/tarzan_utils.c \
	sources/utils/ft_utils_2.c \
	sources/utils/ft_utils.c \
	sources/utils/utils_2.c \
	sources/utils/utils_maths.c \
	sources/utils/utils.c

# ============================================================================ #
#                             MANDATORY SOURCES                                #
# ============================================================================ #

MANDATORY_SRCS	:= \
	sources/main.c \
	sources/parsing/is_texture_line.c \
	sources/raycharlesing/rendu.c \
	$(COMMON_SRCS)

# ============================================================================ #
#                               BONUS SOURCES                                  #
# ============================================================================ #

BONUS_SRCS	:= \
	sources/main_bonus.c \
	bonus/parsing/is_texture_line_bonus.c \
	bonus/raycharlesing/rendu_bonus.c \
	$(COMMON_SRCS) \
	bonus/door/door_utils.c \
	bonus/door/free_doors.c \
	bonus/door/init_doors.c \
	bonus/door/interact_door.c \
	bonus/minimap/draw_minimap.c \
	bonus/minimap/minimap_utils.c

# ============================================================================ #
#                                  OBJECTS                                     #
# ============================================================================ #

MANDATORY_OBJS	:= $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS		:= $(BONUS_SRCS:.c=.bonus.o)

# ============================================================================ #
#                                  RULES                                       #
# ============================================================================ #

all: $(NAME)

$(NAME): $(MLX_A) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(MLX_LNK) -o $(NAME)

bonus: $(MLX_A) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_LNK) -o $(NAME)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c includes/cub3D.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.bonus.o: %.c includes/cub3D.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS)
	rm -f $(BONUS_OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
