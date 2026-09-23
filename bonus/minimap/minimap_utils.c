/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:13:54 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/18 02:01:32 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	put_pixel(t_game *cub3d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = cub3d->mlx.image_add
		+ (y * cub3d->mlx.line_length
			+ x * (cub3d->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
