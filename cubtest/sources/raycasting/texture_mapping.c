/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:29:36 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/10 08:29:40 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_texture_x(t_game *cub3d, t_dda *dda,
	float distance, int texture_id)
{
	float		wall_x;
	int			tex_x;
	t_texture	*texture;

	texture = &cub3d->tex[texture_id];
	if (dda->side == 0)
		wall_x = cub3d->player.pos.y + distance * dda->ray_dir.y;
	else
		wall_x = cub3d->player.pos.x + distance * dda->ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * texture->width);
	if (dda->side == 0 && dda->ray_dir.x > 0)
		tex_x = texture->width - tex_x - 1;
	if (dda->side == 1 && dda->ray_dir.y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}
