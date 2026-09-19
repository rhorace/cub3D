/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:26:30 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/17 18:32:12 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_left(t_game *cub3d)
{
	float	old_dir_x;

	old_dir_x = cub3d->player.dir.x;
	cub3d->player.dir.x = cub3d->player.dir.x * cos(-ROT_SPEED)
		- cub3d->player.dir.y * sin(-ROT_SPEED);
	cub3d->player.dir.y = old_dir_x * sin(-ROT_SPEED)
		+ cub3d->player.dir.y * cos(-ROT_SPEED);
}

void	rotate_right(t_game *cub3d)
{
	float	old_dir_x;

	old_dir_x = cub3d->player.dir.x;
	cub3d->player.dir.x = cub3d->player.dir.x * cos(ROT_SPEED)
		- cub3d->player.dir.y * sin(ROT_SPEED);
	cub3d->player.dir.y = old_dir_x * sin(ROT_SPEED)
		+ cub3d->player.dir.y * cos(ROT_SPEED);
}
