/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:49:38 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/11 18:30:14 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_colors(t_game *cub3d)
{
	cub3d->floor.r = -1;
	cub3d->floor.g = -1;
	cub3d->floor.b = -1;
	cub3d->ceiling.r = -1;
	cub3d->ceiling.g = -1;
	cub3d->ceiling.b = -1;
}

/*
cub3d->player.pos.x = 0;
cub3d->player.pos.y = 0;
cub3d->player.dir.x = 0;
cub3d->player.dir.y = 0;
cub3d->player.plane.x = 0;
cub3d->player.plane.y = 0;
cub3d->player.angle = 0;

cub3d->player.key_up = 0;
cub3d->player.key_down = 0;
cub3d->player.key_left = 0;
cub3d->player.key_right = 0;
cub3d->player.key_rot_left = 0;
cub3d->player.key_rot_right = 0;

cub3d->map_list = NULL;

cub3d->map.grid = NULL;
cub3d->map.width = 0;
cub3d->map.height = 0;
cub3d->map.no_path = NULL;
cub3d->map.so_path = NULL;
cub3d->map.we_path = NULL;
cub3d->map.ea_path = NULL;
cub3d->map.do_path = NULL;

cub3d->mlx.graphics = NULL;
cub3d->mlx.window = NULL;
cub3d->mlx.image = NULL;
cub3d->mlx.image_add = NULL;
cub3d->mlx.bits_per_pixel = 0;
cub3d->mlx.line_length = 0;
cub3d->mlx.endian = 0;

cub3d->floor.r = 0;
cub3d->floor.g = 0;
cub3d->floor.b = 0;

cub3d->ceiling.r = 0;
cub3d->ceiling.g = 0;
cub3d->ceiling.b = 0;
*/
t_game	*init_cub3d(void)
{
	t_game	*cub3d;

	cub3d = ft_calloc(1, sizeof(t_game));
	if (!cub3d)
		return (NULL);
	init_colors(cub3d);
	return (cub3d);
}
