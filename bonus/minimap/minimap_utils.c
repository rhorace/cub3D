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

void	draw_minimap_square(t_game *cub3d, int x, int y, int color)
{
	int	px;
	int	py;

	py = 0;
	while (py < MINIMAP_TILE)
	{
		px = 0;
		while (px < MINIMAP_TILE)
		{
			put_pixel(cub3d, MINIMAP_X + x * MINIMAP_TILE + px,
				MINIMAP_Y + y * MINIMAP_TILE + py, color);
			px++;
		}
		py++;
	}
}

void	draw_minimap_player(t_game *cub3d, int x, int y)
{
	int	px;
	int	py;

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
