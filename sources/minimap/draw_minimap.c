/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:02:17 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/18 02:26:52 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_tile_color(char tile)
{
	if (tile == '1')
		return (0x555555);
	if (tile == '0')
		return (0xEEEEEE);
	if (tile == 'N' || tile == 'S')
		return (0xEEEEEE);
	if (tile == 'E' || tile == 'W')
		return (0xEEEEEE);
	if (tile == 'D')
		return (0x888888);
	return (-1);
}

static void	draw_tile(t_game *cub3d, int x, int y)
{
	int	color;

	color = get_tile_color(cub3d->map.grid[y][x]);
	if (color == -1)
		return ;
	draw_minimap_square(cub3d, x, y, color);
}

static void	draw_player(t_game *cub3d)
{
	int	x;
	int	y;

	x = MINIMAP_X
		+ (int)(cub3d->player.pos.x * MINIMAP_TILE);
	y = MINIMAP_Y
		+ (int)(cub3d->player.pos.y * MINIMAP_TILE);
	draw_minimap_square(cub3d,
		(x - MINIMAP_X) / MINIMAP_TILE,
		(y - MINIMAP_Y) / MINIMAP_TILE,
		0xFF0000);
}

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
	draw_player(cub3d);
}
