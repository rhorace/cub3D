/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:27:50 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/09 20:48:27 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 2 manieres de l'ecrire : le cast en int fonctionne,
mais uniquement pour les nombres positifs.
Ce qui n'est pas genant vu que nos coordonnees sont positives dans notre repere.
Mais pour la forme et la rapidite du programme, pour prend l'autre ecriture. */
unsigned int	partie_entiere(float n)
{
	return (n / 1);
}

float	abs(float n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

void	store_pixel(t_game *cub3d, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return (0);
	pixel = cub3d->mlx.image_add + y * cub3d->mlx.line_length
		+ x * cub3d->mlx.bits_per_pixel;
	*(unsigned int *)pixel = color;
}

int	rgb_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

/* attention gerer la division par 0 (rayon horizontal) */
void	reloc(t_vector *current, t_vector *new, t_game *cub, t_vector ray)
{
	/* if (ray.y < 0)
	{ */
	if (ray.x < 0)
	{
		if (new->x < partie_entiere(current->x))
		{
			new->x = partie_entiere(current->x);
			//new->x = partie_entiere(new->x) + 1;
			new->y = (new->x * ray.x / ray.y)
				+ cub->player.pos.y - (cub->player.pos.x * ray.y / ray.x);
		}
	}
	if (ray.x > 0)
	{
		if (new->x > partie_entiere(current->x) + 1)
		{
			new->x = partie_entiere(current->x) + 1;
			//new->x = partie_entiere(new->x);
			new->y = (new->x * ray.x / ray.y)
				+ cub->player.pos.y - (cub->player.pos.x * ray.y / ray.x);
		}
	}
/* 	}
	else
	{
	if (ray.x < 0)
	{
		if (new->x < partie_entiere(current->x))
		{
			new->x = partie_entiere(new->x) + 1;
			new->y = (new->x * ray.x / ray.y)
				+ cub->player.pos.y - (cub->player.pos.x * ray.y / ray.x);
		}
	}
	if (ray.x > 0)
	{
		if (new->x > partie_entiere(current->x) + 1)
		{
			new->x = partie_entiere(new->x);
			new->y = (new->x * ray.x / ray.y)
				+ cub->player.pos.y - (cub->player.pos.x * ray.y / ray.x);
		}
	}
	}
	if (ray.x < 0 && ray.y < 0)
	{
		if (new.x < partie_entiere(current.x))
	}
	if (ray.x > 0 && ray.y < 0)
	{
		if (new.x > partie_entiere(current.x) + 1)
	}
	if (ray.x < 0 && ray.y > 0)
	{
		if (new.x < partie_entiere(current.x))
	}
	if (ray.x > 0 && ray.y > 0)
	{
		if (new.x > partie_entiere(current.x) + 1)
	} */
}

/* on se deplace dans la direction du rayon vers le y entier le plus proche,
puis on calcule x en restant sur la droite du rayon,
de formule x = (y - b) / a, ou a est la pente et b l'ordonnee a l'origine.
Si x a depasse un entier en premier,
on se repositionne en recalculant y a partir de lui */
void	tarzan(t_vector *current, t_vector *new, t_game *cub, t_vector ray)
{
	if (current->y == 0)
	{
		new->y = cub->player.pos.y + 0.5 * (ray.y / abs(ray.y));
		new->x = (new->y - cub->player.pos.y
				+ (cub->player.pos.x * ray.y / ray.x)) * (ray.y / ray.x);
	}
	else
	{
		if (current->y - partie_entiere(current->y) == 0)
			new->y = current->y + (ray.y / abs(ray.y));
		else
		{
			if (ray.y > 0)
				new->y = partie_entiere(current->y) + 1;
			else
				new->y = partie_entiere(current->y);
		}
		new->x = (new->y - cub->player.pos.y
				+ (cub->player.pos.x * ray.y / ray.x)) * (ray.y / ray.x);
	}
	reloc(&current, &new, cub, ray);
}

/* le rayon a une  direction tournee de theta par rapport a l'orientation du
joueur, avec theta = FOV * (-0.5 + (n / WIN_WIDTH)),
soit un decalage d'un demi FOV + n * le pas angulaire separant chaque rayon.
On calcule les coordonnees du vecteur tourne
en multipliant par la matrice de rotation */
void	matrix(t_vector *ray, t_game *cub, int n)
{
	ray->x = cub->player.dir.x * cos(FOV * (-0.5 + (n / WIN_WIDTH)))
		- cub->player.dir.y * sin(FOV * (-0.5 + (n / WIN_WIDTH)));
	ray->y = cub->player.dir.x * sin(FOV * (-0.5 + (n / WIN_WIDTH)))
		+ cub->player.dir.y * cos(FOV * (-0.5 + (n / WIN_WIDTH)));
}

int	hauteur_mur(t_game *cub, t_vector impact)
{
	int		h;

	h = WIN_HEIGHT / (2 * ((impact.x * cub->player.dir.x)
				+ (impact.y * cub->player.dir.y)) * tan(FOV / 2));
	return (h);
}

int	get_col(t_vector impact)
{
	float	k;
	int		arrondi;

	k = (impact.x - partie_entiere(impact.x)) * BLOCK;
	if (k - partie_entiere(k) < 0.5)
		arrondi = 0;
	else
		arrondi = 1;
	return (partie_entiere(k) + arrondi);
}

int	get_brique(int	brique, int	h)
{
	float	j;
	int		arrondi;

	j = (BLOCK * brique) / h;
	if (j - parie_entiere(j) < 0.5)
		arrondi = 0;
	else
		arrondi = 1;
	return (partie_entiere(j) + arrondi);
}

/* on place chaque pixel de la colonne de mur dans l'image,
avec k le numero de la colonne de pixel de la texture a prelever
et j le pixel de cette colonne sur la texture,
calcule aussi en fonction de la hauteur du mur.
Brique est le numero du pixel que l'on positionne dans l'image,
allant de 0 a h, la hauteur dudit mur.
Les textures, carrees, font BLOCK = 64 pixels de cote. */
void	put_column(t_texture tex, t_vector impact, int n, t_game *cub)
{
	int	k;
	int	j;
	int	brique;
	int	h;
	int	color;

	brique = 0;
	h = hauteur_mur(cub, impact);
	k = get_col(impact);
	while (brique < h)
	{
		j = get_brique(brique, h);
		color = tex.addr[(tex.line_length * j) + (k * tex.bpp)];
		store_pixel(cub, n,
			(WIN_HEIGHT / 2) - (0.5 * h) + brique, color);
		brique++;
	}
}

void	hit_the_wall_jack(t_game *cub, int n)
{
	t_vector	ray;
	t_vector	current;
	t_vector	new;
	t_texture	wall;
	int			tex;

	matrix(&ray, cub, n);
	current.y = 0;
	tex = 0;
	while (!tex)
	{
		tarzan(&current, &new, cub, ray);
		current.x = new.x;
		current.y = new.y;
		tex = is_wall(&current, cub, &ray);
	}
	put_column(cub->tex[tex - 1], current, n, cub);
}

int	remplir_fond(t_game *cub3d)
{
	int	y;
	int	x;
	int	ceiling;
	int	floor;

	ceiling = rgb_to_int(cub3d->ceiling);
	floor = rgb_to_int(cub3d->floor);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				store_pixel(cub3d, x, y, ceiling);
			else
				store_pixel(cub3d, x, y, floor);
			x++;
		}
		y++;
	}
}

int	rendu(t_game *cub3d)
{
	int	x;

	x = 0;
	remplir_fond(cub3d);
	while (x < WIN_WIDTH)
	{
		hit_the_wall_jack(cub3d, x);
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx.graphics, cub3d->mlx.window,
		cub3d->mlx.image, 0, 0);
}
