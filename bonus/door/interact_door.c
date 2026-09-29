/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 12:02:29 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/29 21:13:19 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	snapshot(t_game *cub, int x, int y, struct timeval time)
{
	cub->anim_encours.x = x;
	cub->anim_encours.y = y;
	cub->anim_encours.start = time;
}

// 2.0 -> distance d'interaction
void	interact_door(t_game *cub3d)
{
	int				x;
	int				y;
	struct timeval	time;

	x = (int)(cub3d->player.pos.x
			+ cub3d->player.dir.x * DOOR_DISTANCE);
	y = (int)(cub3d->player.pos.y
			+ cub3d->player.dir.y * DOOR_DISTANCE);
	if (gettimeofday(&time, NULL) == -1)
		return ;
	if (cub3d->map.grid[y][x] == 'D' && cub3d->anim_encours.opening == 0
		&& cub3d->anim_encours.closing == 0)
	{
		cub3d->map.grid[y][x] = 'A';
		cub3d->anim_encours.opening = 1;
		snapshot(cub3d, x, y, time);
	}
	else if (cub3d->map.grid[y][x] == '2' && cub3d->anim_encours.opening == 0
		&& cub3d->anim_encours.closing == 0)
	{
		cub3d->map.grid[y][x] = 'Z';
		cub3d->anim_encours.closing = 1;
		snapshot(cub3d, x, y, time);
	}
}
