/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 09:19:05 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/07 09:19:07 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_texture_id(t_dda *dda)
{
	if (dda->side == 0)
	{
		if (dda->ray_dir.x > 0)
			return (TEX_WE);
		return (TEX_EA);
	}
	if (dda->ray_dir.y > 0)
		return (TEX_NO);
	return (TEX_SO);
}

void	get_wall_limits(t_wall *wall, float distance)
{
	wall->height = WIN_HEIGHT / distance;
	wall->start = -wall->height / 2 + WIN_HEIGHT / 2;
	wall->end = wall->height / 2 + WIN_HEIGHT / 2;
	if (wall->start < 0)
		wall->start = 0;
	if (wall->end >= WIN_HEIGHT)
		wall->end = WIN_HEIGHT - 1;
}
