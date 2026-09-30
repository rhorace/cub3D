/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:25:22 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/29 22:25:32 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	destroy_texture(t_game *cub3d, t_texture *tex)
{
	if (tex->img_ptr)
	{
		mlx_destroy_image(cub3d->mlx.graphics, tex->img_ptr);
		tex->img_ptr = NULL;
	}
}

void	destroy_door_textures(t_game *cub3d)
{
	int	i;

	if (!cub3d->mlx.graphics)
		return ;
	i = 0;
	while (i < ANIM_FRAME_NUMBER)
	{
		destroy_texture(cub3d, &cub3d->door_animation[i]);
		i++;
	}
	destroy_texture(cub3d, &cub3d->door_tex);
	destroy_texture(cub3d, &cub3d->open_door_tex);
}
