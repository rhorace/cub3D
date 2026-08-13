/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 09:49:58 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/13 14:11:11 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <math.h>
# include <X11/X.h> // KeyPress, KeyPressMask, KeyRelease, KeyReleaseMask
# include <X11/keysym.h> // XK_Escape, XK_w, XK_s, XK_a, XK_d

# define RESET "\e[0m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define RED "\e[31m"

/** =============================== CONSTANTES ============================= **/

/*
** BLOCK       : taille d'une case de la carte (64x64 pixels)
** WIN_WIDTH   : largeur de la fenêtre
** WIN_HEIGHT  : hauteur de la fenêtre
** PI          : constante mathématique π
** FOV         : champ de vision du joueur (60° en radians)
*/

# define BLOCK			64
# define WIN_WIDTH		1280
# define WIN_HEIGHT	720
# define PI				3.14159265358979323846
# define FOV			1.0471975511965976f

/** ============================== ENUM TEXTURES =========================== **/

/*
** Permet d'accéder facilement aux textures.
**
** TEX_NO = Nord
** TEX_SO = Sud
** TEX_WE = Ouest
** TEX_EA = Est
*/

typedef enum e_texture_id
{
	TEX_NO = 0,
	TEX_SO = 1,
	TEX_WE = 2,
	TEX_EA = 3
}	t_texture_id;

/** ============================== VECTEUR 2D ============================== **/

/*
** x : coordonnée horizontale
** y : coordonnée verticale
**
** Utilisé pour représenter une position ou une direction.
*/

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

/** ============================== COULEUR RGB ============================= **/

/*
** r : composante rouge (0-255)
** g : composante verte (0-255)
** b : composante bleue (0-255)
**
** Utilisé pour les couleurs du sol et du plafond.
*/

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

/** ================================ JOUEUR ================================ **/

/*
** pos        : position actuelle du joueur dans la carte
** dir        : vecteur indiquant la direction du regard
** plane      : plan de la caméra (détermine le champ de vision)
** angle      : angle du joueur en radians
*/

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	float		angle;
	int			key_up;
	int			key_down;
	int			key_left;
	int			key_right;
	int			key_rot_left;
	int			key_rot_right;
}	t_player;

/** ============================== MUR RENDU =============================== **/

/*
** start   : premier pixel vertical du mur
** end     : dernier pixel vertical du mur
** tex_x   : colonne de la texture à afficher
** height  : hauteur projetée du mur à l'écran
*/

typedef struct s_wall
{
	int		start;
	int		end;
	int		tex_x;
	float	height;
}	t_wall;

/** ================================= CARTE ================================ **/

/*
** grid      : tableau contenant la carte (.cub)
** width     : largeur maximale de la carte
** height    : nombre de lignes de la carte
** line_len  : longueur réelle de chaque ligne
**
** no_path   : chemin de la texture Nord
** so_path   : chemin de la texture Sud
** we_path   : chemin de la texture Ouest
** ea_path   : chemin de la texture Est
*/

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_map;

/** =============================== TEXTURE ================================ **/

/*
** img_ptr   : image MLX
** addr      : adresse du premier pixel
** width     : largeur de la texture
** height    : hauteur de la texture
** line_len  : nombre d'octets par ligne
** endian    : ordre des octets
** bpp       : bits par pixel
*/

typedef struct s_texture
{
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		line_length;
	int		endian;
	int		bpp;
}	t_texture;

/** ================================= DDA ================================= **/

/*
** ray_dir       : direction du rayon
** map_x/y       : case actuellement traversée
**
** side_dist_x/y : distance jusqu'à la prochaine frontière
** delta_dist_x/y: distance entre deux frontières successives
**
** step_x/y      : direction de déplacement dans la grille
** side          : côté du mur touché
**                 0 = mur vertical
**                 1 = mur horizontal
*/

typedef struct s_dda
{
	t_vector	ray_dir;
	int			map_x;
	int			map_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			step_x;
	int			step_y;
	int			side;
}	t_dda;

/** ============================== DONNÉES MLX ============================= **/

/*
** graphics        : connexion MLX
** window_id       : fenêtre créée par MLX
** image           : image utilisée pour le rendu
** image_add       : adresse du premier pixel
** bits_per_pixel  : profondeur de couleur
** line_length     : taille d'une ligne en mémoire
** endian          : ordre des octets
*/

typedef struct s_mlx
{
	void	*graphics;
	void	*window;
	void	*image;
	char	*image_add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

/** ============================ GESTION COLLISION ========================= **/

/*
** new_x   : future position en X
** new_y   : future position en Y
**
** perp_x  : déplacement sur l'axe X
** perp_y  : déplacement sur l'axe Y
*/

typedef struct s_collision
{
	float	new_x;
	float	new_y;
	float	perp_x;
	float	perp_y;
}	t_collision;

/** ========================== LISTE CHAINEE =============================== **/
typedef struct s_map_node
{
	char				*line;
	struct s_map_node	*next;
}	t_map_node;

/** =============================== JEU ==================================== **/

/*
** player          : informations du joueur
** map             : carte chargée
** mlx             : données MLX
** tex             : tableau des 4 textures
** floor           : couleur RGB du sol
** ceiling         : couleur RGB du plafond
** floor_color     : couleur du sol convertie en entier
** ceiling_color   : couleur du plafond convertie en entier
*/

typedef struct s_game
{
	t_player	player;
	t_map_node	*map_list;
	t_map		map;
	t_mlx		mlx;
	t_texture	tex[4];
	t_color		floor;
	t_color		ceiling;
}	t_game;

// debug
void			print_etat(t_game cub3d);
void			print_map(char **map);

// ft_fonctions
void			ft_bzero(void *s, size_t n);
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
char			*ft_substr2(const char *line, int start, int end);
char			*ft_strstr(const char *texte, const char *str);

// verificateurs
int				check_extension(char *path, char *extension);
int				check_map_closed(char **map);
int				check_player_count(char **map);
int				the_verificator(t_game *cub3d);
int				check_player_count(char **map);

void			ft_init(t_game	*cub3d);
void			send_message(char *msg, char *arg);
int				path_ready(t_map *map);
int				color_ready(t_color *plafond, t_color *sol);
int				is_empty_line(char *line);

// events
int				key_presser(int val, void *param);
int				key_releaser(int val, void *param);

void			close_cub3d(t_game	*cub3d, int code);
int				ligne_max(char **map);
int				get_color(t_game *cub3d, char *line);
int				get_path(t_game *cub3d, char *line);
//int				get_map(t_game *cub3d, char *line, int in_map);
int				ceiling_ready(t_color *plafond);
int				floor_ready(t_color *sol);

int				read_file(t_game *cub3d, char *path);

t_map_node		*new_map_node(char *line);
void			add_map_line(t_map_node **map_list, char *line);
int				map_list_size(t_map_node *map_list);
char			**map_list_to_array(t_map_node *map_list, int max_width);
void			free_map_list(t_map_node *map_list);

char			*pad_map_line(char *line, int max_width);

int				is_texture_line(char *line);
int				is_color_line(char *line);

/* ============================= RAYCASTING ============================== */

void			render_frame(t_game *cub3d);
void			cast_ray(t_game *cub3d, int x);
void			init_dda(t_game *cub3d, t_dda *dda, int x);
int				run_dda(t_game *cub3d, t_dda *dda);
float			get_wall_distance(t_game *cub3d, t_dda *dda);
void			get_wall_limits(t_wall *wall, float distance);
int				get_texture_id(t_dda *dda);
int				get_texture_x(t_game *cub3d, t_dda *dda, float distance, \
int texture_id);

/* ============================== DRAWING ================================ */

void			put_pixel(t_game *cub3d, int x, int y, int color);
int				get_texture_pixel(t_texture *texture, int x, int y);
int				rgb_to_int(t_color color);
void			draw_background(t_game *cub3d);
void			draw_wall(t_game *cub3d, int x, t_dda *dda, t_wall *wall, \
int texture_id);

int				init_mlx(t_game *cub3d);
int				load_textures(t_game *cub3d);
void			init_player(t_game *cub3d);

void			move_forward(t_game *cub3d);
void			move_backward(t_game *cub3d);
void			move_left(t_game *cub3d);
void			move_right(t_game *cub3d);

void			rotate_left(t_game *cub3d);
void			rotate_right(t_game *cub3d);

int				game_loop(t_game *cub3d);

#endif
