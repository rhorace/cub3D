/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:02:17 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/24 16:46:47 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Calcule le point de départ et le point d'arrivée de la ligne
   En convertissant la position du joueur dans la map en coordonnées
   en pixels sur la minimap.
*/
static void	draw_player_direction(t_game *cub3d)
{
	t_vector	start;
	t_vector	end;

	start.x = DECALAGE_X
		+ cub3d->player.pos.x * TAILLE_CARRE;
	start.y = DECALAGE_Y
		+ cub3d->player.pos.y * TAILLE_CARRE;
	end.x = start.x
		+ cub3d->player.dir.x * LONGUEUR_LIGNE;
	end.y = start.y
		+ cub3d->player.dir.y * LONGUEUR_LIGNE;
	draw_line(cub3d, start, end);
}

/* On associe une couleur à la case (x, y)
   On déssine un carré plein de cette couleur avec draw_minimap_square() */
static void	draw_tile(t_game *cub3d, int x, int y)
{
	char	tile;
	int		color;

	tile = cub3d->map.grid[y][x];
	if (tile == '1')
		color = 0x555555;
	else if (tile == '0' || tile == 'N' || tile == 'S'
		|| tile == 'E' || tile == 'W')
		color = 0xEEEEEE;
	else if (tile == 'D')
		color = 0x0000FF;
	else if (tile == '2')
		color = 0x00FF00;
	else
		return ;
	draw_minimap_square(cub3d, x, y, color);
}

// On déssine un carré rouge plein de taille : 2
static void	draw_player(t_game *cub3d)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = DECALAGE_X + cub3d->player.pos.x * TAILLE_CARRE;
	y = DECALAGE_Y + cub3d->player.pos.y * TAILLE_CARRE;
	py = -2;
	while (py <= 2)
	{
		px = -2;
		while (px <= 2)
		{
			put_pixel(cub3d, x + px, y + py, 0xFF0000);
			px++;
		}
		py++;
	}
}

/* On parcourt la map
   Une case (x, y) de la map sera déssinée avec draw_tile() 
   On dessine une ligne pour la direction du joueur avec draw_player_direction()
   On déssine le joueur avec draw_player() */
void	draw_minimap(t_game *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			draw_tile(cub3d, x, y);
			x++;
		}
		y++;
	}
	draw_player_direction(cub3d);
	draw_player(cub3d);
}
