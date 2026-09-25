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
	int	x;
	int	y;

	x = (int)(cub3d->player.pos.x
			+ cub3d->player.dir.x * DOOR_DISTANCE);
	y = (int)(cub3d->player.pos.y
			+ cub3d->player.dir.y * DOOR_DISTANCE);
	if (cub3d->map.grid[y][x] == 'D')
		cub3d->map.grid[y][x] = '2';
	else if (cub3d->map.grid[y][x] == '2')
		cub3d->map.grid[y][x] = 'D';
}
