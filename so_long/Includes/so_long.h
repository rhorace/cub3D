/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:29:40 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/28 18:53:47 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf_fd.h"

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define LARGEUR_MAX 1200
# define HAUTEUR_MAX 800
# define IMG_PIX 32

typedef struct s_map
{
	char	*map;
	size_t	hauteur;
	size_t	largeur;
	size_t	collec;
	size_t	temp_collec;
	int		ijoueur;
	size_t	nbjoueur;
	int		flagp;
	size_t	sortie;
}			t_map;

typedef struct s_textures
{
	void	*joueur;
	void	*joueur_out;
	void	*collec;
	void	*sortie;
	void	*visite;
	void	*mur;
	void	*chemin;
}			t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_textures	*set;
}			t_game;

size_t	count_assets(char *line, t_map *map);
int		finishable(t_map *map);
int		milieu_map(char **line, char **temp, t_map *map, int fd);
int		so_so_long(t_game *g);
int		display(t_game *g);
void	free_graphics(t_game *g);
void	free_textures(t_game *g);
int		close_win(void *mlx);
int		handle_key(int keycode, t_game *g);
t_game	*init_game(t_map *map);
void	bouger(t_game *g, int move, int keycode);
int		get_x(t_game *g, int i);
int		get_y(t_game *g, int i);
char	*ft_strendstr(const char *big, const char *little, size_t len);

#endif
