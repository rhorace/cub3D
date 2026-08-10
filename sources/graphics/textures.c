/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:27:17 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/10 15:06:21 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	load_texture(t_game *cub3d, t_texture *texture, char *path)
{
	texture->img_ptr = mlx_xpm_file_to_image(
			cub3d->mlx.graphics,
			path,
			&texture->width,
			&texture->height);
	if (!texture->img_ptr)
		return (0);
	texture->addr = mlx_get_data_addr(
			texture->img_ptr,
			&texture->bpp,
			&texture->line_length,
			&texture->endian);
	if (!texture->addr)
		return (0);
	return (1);
}

int	load_textures(t_game *cub3d)
{
	if (!load_texture(cub3d, &cub3d->tex[TEX_NO],
			cub3d->map.no_path))
		return (send_message("Invalid TEX_NO !", NULL), 0);
	if (!load_texture(cub3d, &cub3d->tex[TEX_SO],
			cub3d->map.so_path))
		return (send_message("Invalid TEX_SO !", NULL), 0);
	if (!load_texture(cub3d, &cub3d->tex[TEX_WE],
			cub3d->map.we_path))
		return (send_message("Invalid TEX_WE !", NULL), 0);
	if (!load_texture(cub3d, &cub3d->tex[TEX_EA],
			cub3d->map.ea_path))
		return (send_message("Invalid TEX_EA !", NULL), 0);
	return (1);
}
