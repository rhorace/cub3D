/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:25:22 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/19 16:10:32 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_door_texture(t_game *cub3d)
{
	if (!cub3d->mlx.graphics)
		return ;
	if (cub3d->door_tex.img_ptr)
	{
		mlx_destroy_image(cub3d->mlx.graphics,
			cub3d->door_tex.img_ptr);
		cub3d->door_tex.img_ptr = NULL;
	}
}
