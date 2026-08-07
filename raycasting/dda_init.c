/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 09:18:06 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/07 09:18:11 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_delta_dist(t_dda *dda)
{
	if (dda->ray_dir.x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1.0 / dda->ray_dir.x);
	if (dda->ray_dir.y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1.0 / dda->ray_dir.y);
}

static void	init_step_x(t_game *cub3d, t_dda *dda)
{
	if (dda->ray_dir.x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (cub3d->player.pos.x - dda->map_x)
			* dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - cub3d->player.pos.x)
			* dda->delta_dist_x;
	}
}

static void	init_step_y(t_game *cub3d, t_dda *dda)
{
	if (dda->ray_dir.y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (cub3d->player.pos.y - dda->map_y)
			* dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - cub3d->player.pos.y)
			* dda->delta_dist_y;
	}
}

void	init_dda(t_game *cub3d, t_dda *dda, int x)
{
	float	camera_x;

	camera_x = 2.0 * x / (float)WIN_WIDTH - 1.0;
	dda->ray_dir.x = cub3d->player.dir.x
		+ cub3d->player.plane.x * camera_x;
	dda->ray_dir.y = cub3d->player.dir.y
		+ cub3d->player.plane.y * camera_x;
	dda->map_x = (int)cub3d->player.pos.x;
	dda->map_y = (int)cub3d->player.pos.y;
	init_delta_dist(dda);
	init_step_x(cub3d, dda);
	init_step_y(cub3d, dda);
	dda->side = 0;
}
