/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:29:20 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/10 08:29:23 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cast_ray(t_game *cub3d, int x)
{
	t_dda	dda;
	t_wall	wall;
	float	distance;
	int		texture_id;

	init_dda(cub3d, &dda, x);
	if (!run_dda(cub3d, &dda))
		return ;
	distance = get_wall_distance(cub3d, &dda);
	get_wall_limits(&wall, distance);
	texture_id = get_texture_id(&dda);
	wall.tex_x = get_texture_x(cub3d, &dda, distance, texture_id);
	draw_wall(cub3d, x, &dda, &wall, texture_id);
}
