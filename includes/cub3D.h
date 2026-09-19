/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 09:49:58 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/18 19:33:13 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
//# include <stddef.h>
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

# define MOVE_SPEED 0.01
# define ROT_SPEED 0.01
# define MOUSE_SENSITIVITY 0.002

# define MINIMAP_TILE 8
# define MINIMAP_X 20
# define MINIMAP_Y 20

# define DOOR_FRAMES 5
# define DOOR_CLOSED 0
# define DOOR_OPENING 1
# define DOOR_OPEN 2

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
# define WIN_HEIGHT		720
//# define PI				3.14159265358979323846
# define FOV			1.0471975511965976f

/** ============================== ENUM TEXTURES =========================== **/

/*
** Permet d'accéder facilement aux textures.
**
** TEX_NO = Nord
** TEX_SO = Sud
** TEX_WE = Ouest
** TEX_EA = Est
** TEX_DO = Door
*/

typedef enum e_texture_id
{
	TEX_NO = 1,
	TEX_SO = 2,
	TEX_WE = 3,
	TEX_EA = 4,
	TEX_DO = 5
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

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

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
** do_path   : chemin de la texture Porte
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
	char	*do_path;
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
	void			*img_ptr;
	char			*addr;
	t_texture_id	id;
	int				width;
	int				height;
	int				line_length;
	int				endian;
	int				bpp;
}	t_texture;

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
	int		mouse_x;
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


// LES PORTES : chaque D aura son propre t_door
typedef struct s_door
{
	int				x;
	int				y;
	int				state;
	int				frame;
	int				timer;
	struct s_door	*next;
}	t_door;

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
	t_texture	tex[5];
	t_texture	door_tex[DOOR_FRAMES];
	t_door		*doors;
	t_color		floor;
	t_color		ceiling;
}	t_game;

// initialisation
t_game			*init_cub3d(void);
int				init_mlx_failed(t_game *cub3d);
int				load_textures_failed(t_game *cub3d);
void			init_player(t_game *cub3d);
int				game_loop(t_game *cub3d);

// debug
void			print_etat(t_game cub3d);
void			print_map(char **map);

//gestion erreurs et sorties
void			send_message(char *msg, char *arg);
void			close_cub3d(t_game	*cub3d, int code);
void			free_map_list(t_map_node *map_list);

// ft_fonctions
void			ft_bzero(void *s, size_t n);
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
char			*ft_substr2(const char *line, int start, int end);
char			*ft_strstr(const char *texte, const char *str);
void			*ft_calloc(size_t count, size_t size);

// verificateurs map
int				bad_extension(char *path, char *extension);
int				map_not_closed(char **map);
int				bad_player_count(char **map);
int				verificator_failed(t_game *cub3d);
int				line_map_valid(char *line, char *do_path);
int				texture_ready(t_map *map);
int				color_ready(t_color *plafond, t_color *sol);
int				is_empty_line(char *line);
int				ligne_max(char **map);
int				get_color(t_game *cub3d, char *line);
int				get_texture_path(t_game *cub3d, char *line);
int				ceiling_ready(t_color *plafond);
int				floor_ready(t_color *sol);
void			remove_newline(char *line);
int				bad_file(t_game *cub3d, char *path);
void			manage_line(t_game *cub3d, char *line, int fd);
int				is_texture_line(char *line);
int				is_color_line(char *line);
char			*pad_map_line(char *line, int max_width);

t_map_node		*new_map_node(char *line);
void			add_map_line(t_map_node **map_list, char *line);
int				map_list_size(t_map_node *map_list);
char			**map_list_to_grid(t_map_node *map_list, int max_width);

// events
int				key_presser(int val, void *param);
int				key_releaser(int val, void *param);
int				mouse_move(int x, int y, void *param);
void			move_forward(t_game *cub3d);
void			move_backward(t_game *cub3d);
void			move_left(t_game *cub3d);
void			move_right(t_game *cub3d);
void			rotate_left(t_game *cub3d);
void			rotate_right(t_game *cub3d);
int				worlds_collide(t_vector *current, t_game *cub,
					t_vector *move_dir);
int				ceiling_above(float x);
int				mattress_under(float x);

/* ============================= RAYCASTING ============================== */

void			rendu(t_game *cub3d);
void			reloc(t_vector *current, t_vector *new,
					t_game *cub, t_vector ray);
void			jack_on_the_magic_bean(t_vector *current,
					t_vector *new, t_game *cub, t_vector ray);
void			run_forrest(t_vector *current,
					t_vector *new, t_game *cub, t_vector ray);
void			init_ray(t_vector *current, t_vector *new,
					t_game *cub, t_vector ray);
int				get_brique(int brique, int h);
int				get_col(t_vector impact, t_texture tex);
int				hauteur_mur(t_game *cub, t_vector impact);
int				is_wall_or_door(t_vector *current, t_game *cub, t_vector *ray);

/* ============================== DRAWING ================================ */

void			remplir_fond(t_game *cub3d);
void			store_pixel(t_game *cub3d, int x, int y, int color);
void			put_column(t_texture tex, t_vector impact, int n, t_game *cub);

/* ======================= UTILS DE CALCUL ET RENDU ======================= */

float			y_moins_b_sur_a(t_vector *new, t_game *cub, t_vector ray);
void			matrix(t_vector *ray, t_game *cub, int n);
float			valeur_absolue(float n);
unsigned int	partie_entiere(float n);
int				is_pos_int(float x);

// MINIMAP
void			draw_minimap(t_game *cub3d);
void			draw_minimap_square(t_game *cub3d, int x, int y, int color);
void			draw_minimap_player(t_game *cub3d, int x, int y);

//DOOR
int				init_doors(t_game *cub3d);
t_door			*get_door(t_game *cub3d, int x, int y);
void			interact_door(t_game *cub3d);
void			update_door(t_game *cub3d, t_door *door);
void			update_doors(t_game *cub3d);
void			destroy_doors(t_game *cub3d);
void			destroy_door_textures(t_game *cub3d);

#endif
