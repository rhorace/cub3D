/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:13:54 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/24 16:54:20 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Déssine une ligne de pixels entre start et end
   delta.x : distance à parcourir sur X
   delta.y : distance à parcourir sur Y */
void	draw_line(t_game *cub3d, t_vector start, t_vector end)
{
	t_vector	delta;
	t_vector	pos;
	int			steps;
	int			i;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	steps = fmax(fabs(delta.x), fabs(delta.y));
	pos = start;
	i = 0;
	while (i <= steps)
	{
		put_pixel(cub3d, (int)pos.x, (int)pos.y, 0xFF0000);
		pos.x += delta.x / steps;
		pos.y += delta.y / steps;
		i++;
	}
}

// On déssine un carré plein de taille : TAILLE_CARRE
void	draw_minimap_square(t_game *cub3d, int x, int y, int color)
{
	int	px;
	int	py;

	py = 0;
	while (py < TAILLE_CARRE)
	{
		px = 0;
		while (px < TAILLE_CARRE)
		{
			put_pixel(cub3d, DECALAGE_X + x * TAILLE_CARRE + px,
				DECALAGE_Y + y * TAILLE_CARRE + py, color);
			px++;
		}
		py++;
	}
}
