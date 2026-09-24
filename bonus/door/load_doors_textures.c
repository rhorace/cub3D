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

int	load_door_texture(t_game *cub3d)
{
	t_texture	*tex;

	printf("cub3d->map.do_path: %s\n", cub3d->map.do_path);
	tex = &cub3d->door_tex;
	tex->img_ptr = mlx_xpm_file_to_image(cub3d->mlx.graphics,
			cub3d->map.do_path, &tex->width, &tex->height);
	if (!tex->img_ptr)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img_ptr,
			&tex->bpp, &tex->line_length, &tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}
