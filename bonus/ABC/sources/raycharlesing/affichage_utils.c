/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:08:55 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/15 21:39:18 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	store_pixel(t_game *cub3d, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = cub3d->mlx.image_add + y * cub3d->mlx.line_length
		+ (x * cub3d->mlx.bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

static int	rgb_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

void	remplir_fond(t_game *cub3d)
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

/* on place chaque pixel de la colonne de mur dans l'image,
avec k le numero de la colonne de pixel de la texture a prelever
et j le pixel de cette colonne sur la texture,
calcule aussi en fonction de la hauteur du mur.
Brique est le numero du pixel que l'on positionne dans l'image,
allant de 0 a h, la hauteur dudit mur.
Les textures, carrees, font BLOCK = 64 pixels de cote. */
void	put_column(t_texture tex, t_vector current, int n, t_game *cub)
{
	t_point			pix;
	int				brique;
	int				h;
	unsigned int	color;
	char			*pixel;

	brique = 0;
	h = hauteur_mur(cub, current);
	pix.x = get_col(current, tex);
	while (brique < h)
	{
		pix.y = get_brique(brique, h);
		pixel = tex.addr + (pix.y * tex.line_length) + (pix.x * tex.bpp / 8);
		color = *(unsigned int *)pixel;
		store_pixel(cub, n, partie_entiere((WIN_HEIGHT / 2))
			- (partie_entiere(0.5 * h)) + brique, color);
		brique++;
	}
}
