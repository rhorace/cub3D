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

static int	load_door_texture(t_game *cub3d, int index, char *path)
{
	t_texture	*tex;

	tex = &cub3d->door_tex[index];
	tex->img_ptr = mlx_xpm_file_to_image(cub3d->mlx.graphics,
			path, &tex->width, &tex->height);
	if (!tex->img_ptr)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img_ptr,
			&tex->bpp,
			&tex->line_length,
			&tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}

int	load_doors_textures_and_init_doors(t_game *cub3d)
{
	if (!load_door_texture(cub3d, 0, "textures/doors/door_0.xpm"))
		return (0);
	if (!load_door_texture(cub3d, 1, "textures/doors/door_1.xpm"))
		return (0);
	if (!load_door_texture(cub3d, 2, "textures/doors/door_2.xpm"))
		return (0);
	if (!load_door_texture(cub3d, 3, "textures/doors/door_3.xpm"))
		return (0);
	if (!load_door_texture(cub3d, 4, "textures/doors/door_4.xpm"))
		return (0);
	if (!init_doors(cub3d))
		return (0);
	return (1);
}
