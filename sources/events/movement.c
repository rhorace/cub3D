/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:26:20 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/10 08:26:25 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define MOVE_SPEED 0.05

//C'est moi qui gère les collisions !
static int	can_move(t_game *cub3d, float x, float y)
{
	if (cub3d->map.grid[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

void	move_forward(t_game *cub3d)
{
	float	new_x;
	float	new_y;

	new_x = cub3d->player.pos.x
		+ cub3d->player.dir.x * MOVE_SPEED;
	new_y = cub3d->player.pos.y
		+ cub3d->player.dir.y * MOVE_SPEED;
	if (can_move(cub3d, new_x, cub3d->player.pos.y))
		cub3d->player.pos.x = new_x;
	if (can_move(cub3d, cub3d->player.pos.x, new_y))
		cub3d->player.pos.y = new_y;
}

void	move_backward(t_game *cub3d)
{
	float	new_x;
	float	new_y;

	new_x = cub3d->player.pos.x
		- cub3d->player.dir.x * MOVE_SPEED;
	new_y = cub3d->player.pos.y
		- cub3d->player.dir.y * MOVE_SPEED;
	if (can_move(cub3d, new_x, cub3d->player.pos.y))
		cub3d->player.pos.x = new_x;
	if (can_move(cub3d, cub3d->player.pos.x, new_y))
		cub3d->player.pos.y = new_y;
}

void	move_left(t_game *cub3d)
{
	float	new_x;
	float	new_y;

	new_x = cub3d->player.pos.x
		+ cub3d->player.dir.y * MOVE_SPEED;
	new_y = cub3d->player.pos.y
		- cub3d->player.dir.x * MOVE_SPEED;
	if (can_move(cub3d, new_x, cub3d->player.pos.y))
		cub3d->player.pos.x = new_x;
	if (can_move(cub3d, cub3d->player.pos.x, new_y))
		cub3d->player.pos.y = new_y;
}

void	move_right(t_game *cub3d)
{
	float	new_x;
	float	new_y;

	new_x = cub3d->player.pos.x
		- cub3d->player.dir.y * MOVE_SPEED;
	new_y = cub3d->player.pos.y
		+ cub3d->player.dir.x * MOVE_SPEED;
	if (can_move(cub3d, new_x, cub3d->player.pos.y))
		cub3d->player.pos.x = new_x;
	if (can_move(cub3d, cub3d->player.pos.x, new_y))
		cub3d->player.pos.y = new_y;
}
