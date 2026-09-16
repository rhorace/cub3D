/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:28:21 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/14 10:47:20 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir.x = 0.0;
		player->dir.y = -1.0;
	}
	else if (direction == 'S')
	{
		player->dir.x = 0.0;
		player->dir.y = 1.0;
	}
	else if (direction == 'E')
	{
		player->dir.x = 1.0;
		player->dir.y = 0.0;
	}
	else if (direction == 'W')
	{
		player->dir.x = -1.0;
		player->dir.y = 0.0;
	}
}

static void	set_player_plane(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->plane.x = 0.57735026919;
		player->plane.y = 0.0;
	}
	else if (direction == 'S')
	{
		player->plane.x = -0.57735026919;
		player->plane.y = 0.0;
	}
	else if (direction == 'E')
	{
		player->plane.x = 0.0;
		player->plane.y = 0.57735026919;
	}
	else if (direction == 'W')
	{
		player->plane.x = 0.0;
		player->plane.y = -0.57735026919;
	}
}

static void	set_player_position(t_game *cub3d, int x, int y, char direction)
{
	cub3d->player.pos.x = x + 0.5;
	cub3d->player.pos.y = y + 0.5;
	set_player_direction(&cub3d->player, direction);
	set_player_plane(&cub3d->player, direction);
}

void	init_player(t_game *cub3d)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (cub3d->map.grid[y])
	{
		x = 0;
		while (cub3d->map.grid[y][x])
		{
			c = cub3d->map.grid[y][x];
			if (is_player(c))
			{
				set_player_position(cub3d, x, y, c);
				cub3d->map.grid[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
