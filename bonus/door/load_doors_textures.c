/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_doors_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 16:46:06 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/24 17:14:27 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	load_texture(t_game *cub3d, t_texture *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(cub3d->mlx.graphics,
			path, &tex->width, &tex->height);
	if (!tex->img_ptr)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img_ptr,
			&tex->bpp, &tex->line_length, &tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}

int	load_door_texture(t_game *cub3d)
{
	if (!load_texture(cub3d, &cub3d->door_tex,
			cub3d->map.do_path))
		return (0);
	if (!load_texture(cub3d, &cub3d->open_door_tex,
			cub3d->map.od_path))
		return (0);
	return (1);
}
