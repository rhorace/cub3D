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

static void	draw_player_direction(t_game *cub3d)
{
	t_vector	start;
	t_vector	end;

	start.x = MINIMAP_X
		+ cub3d->player.pos.x * MINIMAP_TILE;
	start.y = MINIMAP_Y
		+ cub3d->player.pos.y * MINIMAP_TILE;
	end.x = start.x
		+ cub3d->player.dir.x * MINIMAP_DIR_LEN;
	end.y = start.y
		+ cub3d->player.dir.y * MINIMAP_DIR_LEN;
	draw_line(cub3d, start, end);
}

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
		return (0x0000FF);
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
	int	px;
	int	py;

	x = MINIMAP_X + cub3d->player.pos.x * MINIMAP_TILE;
	y = MINIMAP_Y + cub3d->player.pos.y * MINIMAP_TILE;
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
