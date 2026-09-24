/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:26:20 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/24 16:44:22 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_game *cub3d)
{
	t_vector	new_pos;
	t_vector	move_dir;

	move_dir.x = cub3d->player.dir.x;
	move_dir.y = cub3d->player.dir.y;
	new_pos.x = cub3d->player.pos.x + move_dir.x * MOVE_SPEED;
	new_pos.y = cub3d->player.pos.y + move_dir.y * MOVE_SPEED;
	if (!worlds_collide(&new_pos, cub3d, &move_dir))
	{
		cub3d->player.pos.x = new_pos.x;
		cub3d->player.pos.y = new_pos.y;
	}
}

void	move_backward(t_game *cub3d)
{
	t_vector	new_pos;
	t_vector	move_dir;

	move_dir.x = -cub3d->player.dir.x;
	move_dir.y = -cub3d->player.dir.y;
	new_pos.x = cub3d->player.pos.x + move_dir.x * MOVE_SPEED;
	new_pos.y = cub3d->player.pos.y + move_dir.y * MOVE_SPEED;
	if (!worlds_collide(&new_pos, cub3d, &move_dir))
	{
		cub3d->player.pos.x = new_pos.x;
		cub3d->player.pos.y = new_pos.y;
	}
}

void	move_left(t_game *cub3d)
{
	t_vector	new_pos;
	t_vector	move_dir;

	move_dir.x = cub3d->player.dir.y;
	move_dir.y = -cub3d->player.dir.x;
	new_pos.x = cub3d->player.pos.x + move_dir.x * MOVE_SPEED;
	new_pos.y = cub3d->player.pos.y + move_dir.y * MOVE_SPEED;
	if (!worlds_collide(&new_pos, cub3d, &move_dir))
	{
		cub3d->player.pos.x = new_pos.x;
		cub3d->player.pos.y = new_pos.y;
	}
}

void	move_right(t_game *cub3d)
{
	t_vector	new_pos;
	t_vector	move_dir;

	move_dir.x = -cub3d->player.dir.y;
	move_dir.y = cub3d->player.dir.x;
	new_pos.x = cub3d->player.pos.x + move_dir.x * MOVE_SPEED;
	new_pos.y = cub3d->player.pos.y + move_dir.y * MOVE_SPEED;
	if (!worlds_collide(&new_pos, cub3d, &move_dir))
	{
		cub3d->player.pos.x = new_pos.x;
		cub3d->player.pos.y = new_pos.y;
	}
}
