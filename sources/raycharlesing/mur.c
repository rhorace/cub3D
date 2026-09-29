/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mur.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:11:56 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/29 21:28:50 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* le vecteur impact = current - player.pos */
int	hauteur_mur(t_game *cub, t_vector current)
{
	int			h;
	t_vector	impact;

	impact.x = current.x - cub->player.pos.x;
	impact.y = current.y - cub->player.pos.y;
	h = WIN_HEIGHT / (2 * (((float)impact.x * (float)cub->player.dir.x)
				+ ((float)impact.y * (float)cub->player.dir.y)) * tan(FOV / 2));
	return (h);
}

int	get_col(t_vector impact, t_wall_hit *wall)
{
	float	k;
	int		arrondi;

	if (impact.x - partie_entiere(impact.x) != 0)
	{
		if (wall->side == SI_NO)
			k = (partie_entiere(impact.x) + 1 - impact.x) * BLOCK;
		else
			k = (impact.x - partie_entiere(impact.x)) * BLOCK;
	}
	else
	{
		if (wall->side == SI_EA)
			k = (partie_entiere(impact.y) + 1 - impact.y) * BLOCK;
		else
			k = (impact.y - partie_entiere(impact.y)) * BLOCK;
	}
	if (k - partie_entiere(k) < 0.5 || k > BLOCK - 1)
		arrondi = 0;
	else
		arrondi = 1;
	return (partie_entiere(k) + arrondi);
}

int	get_brique(int brique, int h)
{
	float	j;
	int		arrondi;

	j = (BLOCK * brique) / h;
	if (j - partie_entiere(j) < 0.5 || j > BLOCK - 1)
		arrondi = 0;
	else
		arrondi = 1;
	return (partie_entiere(j) + arrondi);
}

static char	*get_pixel_addr(t_point pix, t_texture tex)
{
	char	*pixel;

	pixel = tex.addr + (pix.y * tex.line_length) + (pix.x * tex.bpp / 8);
	return (pixel);
}

/* on place chaque pixel de la colonne de mur dans l'image,
avec k le numero de la colonne de pixel de la texture a prelever
et j le pixel de cette colonne sur la texture,
calcule aussi en fonction de la hauteur du mur.
Brique est le numero du pixel que l'on positionne dans l'image,
allant de 0 a h, la hauteur dudit mur.
Les textures, carrees, font BLOCK = 64 pixels de cote. */
void	put_column(t_wall_hit *wall, t_vector current, int n, t_game *cub)
{
	t_point			pix;
	int				brique;
	int				h;
	unsigned int	color;
	char			*pixel;

	brique = 0;
	h = hauteur_mur(cub, current);
	pix.x = get_col(current, wall);
	while (brique < h)
	{
		pix.y = get_brique(brique, h);
		if (wall->is_anim == -1)
			pixel = get_pixel_addr(pix, cub->tex[wall->tex]);
		else
			pixel = get_pixel_addr(pix, cub->door_animation[wall->is_anim]);
		color = *(unsigned int *)pixel;
		store_pixel(cub, n, partie_entiere((WIN_HEIGHT / 2))
			- (partie_entiere(0.5 * h)) + brique, color);
		brique++;
	}
}
