/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 12:02:29 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/24 16:40:13 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// 1.0 -> distance d'interaction
void	interact_door(t_game *cub3d)
{
	t_door	*door;
	int		x;
	int		y;

	x = (int)(cub3d->player.pos.x
			+ cub3d->player.dir.x * DOOR_INTERACT);
	y = (int)(cub3d->player.pos.y
			+ cub3d->player.dir.y * DOOR_INTERACT);
	if (cub3d->map.grid[y][x] != 'D')
		return ;
	door = get_door(cub3d, x, y);
	if (!door)
		return ;
	if (door->state == DOOR_CLOSED)
		door->state = DOOR_OPENING;
}

void	update_door(t_game *cub3d, t_door *door)
{
	if (door->state != DOOR_OPENING)
		return ;
	door->timer++;
	if (door->timer < 5)
		return ;
	door->timer = 0;
	door->frame++;
	if (door->frame >= DOOR_FRAMES - 1)
	{
		door->frame = DOOR_FRAMES - 1;
		door->state = DOOR_OPEN;
		cub3d->map.grid[door->y][door->x] = '0';
	}
}

void	update_doors(t_game *cub3d)
{
	t_door	*door;

	door = cub3d->doors;
	while (door)
	{
		update_door(cub3d, door);
		door = door->next;
	}
}
