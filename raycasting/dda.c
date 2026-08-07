/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 09:17:51 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/07 09:17:55 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	in_map(t_game *cub3d, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (y >= cub3d->map.height)
		return (0);
	if (x >= cub3d->map.width)
		return (0);
	return (1);
}

int	run_dda(t_game *cub3d, t_dda *dda)
{
	while (1)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (!in_map(cub3d, dda->map_x, dda->map_y))
			return (0);
		if (cub3d->map.grid[dda->map_y][dda->map_x] == '1')
			return (1);
	}
}
