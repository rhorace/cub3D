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

void	destroy_door_texture(t_game *cub3d)
{
	int	i;

	if (!cub3d->mlx.graphics)
		return ;
	i = 0;
	while (cub3d->map.anim_path[i] && cub3d->map.anim_path[i][0] != '\0')
	{
		mlx_destroy_image(cub3d->mlx.graphics,
			cub3d->door_animation[i].img_ptr);
		cub3d->door_animation[i].img_ptr = NULL;
		i++;
	}
	if (cub3d->door_tex.img_ptr)
	{
		mlx_destroy_image(cub3d->mlx.graphics,
			cub3d->door_tex.img_ptr);
		cub3d->door_tex.img_ptr = NULL;
	}
	if (cub3d->open_door_tex.img_ptr)
	{
		mlx_destroy_image(cub3d->mlx.graphics,
			cub3d->open_door_tex.img_ptr);
		cub3d->open_door_tex.img_ptr = NULL;
	}
}
