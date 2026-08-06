# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/10 17:05:14 by sohollar          #+#    #+#              #
#    Updated: 2026/03/26 19:56:56 by sohollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nom du programme :
NAME			= so_long

#Compilation :
CC				= cc
CFLAGS			= -g3 -Wall -Wextra -Werror

# Dossiers :
LIBS_DIR		= ./Librairies/
SRCS_DIR		= ./Sources/
OBJS_DIR		= ./Objets/
INCS_DIR		= ./Includes/
LIBFT_DIR		= $(LIBS_DIR)Libft
PRINTF_FD_DIR	= $(LIBS_DIR)Printf_fd
MINILIB_DIR		= $(LIBS_DIR)minilibx-linux

#Fichiers
SRCS_RAW		= so_long.c map_manag.c suite_map.c hooks.c \
					textures.c mouvement.c game.c frees.c tools.c
OBJS_RAW		= $(SRCS_RAW:.c=.o) # so_long.o
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_RAW)) # ./Sources/so_long.c
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_RAW)) # ./Objets/so_long.o
# OBJ 			= $($(SRCS):%.c,$(OBJS_DIR)/%.o,)

#Wraps :
LIB				= -L$(LIBFT_DIR) -L$(MINILIB_DIR) -L$(PRINTF_FD_DIR) \
					-lft -lmlx -lftprintf_fd -lX11 -lXext
INCLUDES		= $(INCS_DIR) $(LIBFT_DIR) $(MINILIB_DIR) $(PRINTF_FD_DIR)
IFLAGS			= $(addprefix -I, $(INCLUDES))


all: libs $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIB)

libs:
	make -C $(LIBFT_DIR)
	make -C $(MINILIB_DIR)
	make -C $(PRINTF_FD_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIB_DIR) clean
	make -C $(PRINTF_FD_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_FD_DIR) fclean
	rm -rf $(NAME)

.PHONY: all clean fclean re



# O3 O2 O1  normal  g1 g2 g3
# <- opti++         opti--  ->
