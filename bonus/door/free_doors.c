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

void	destroy_doors(t_game *cub3d)
{
	t_door	*door;
	t_door	*next;

	door = cub3d->doors;
	while (door)
	{
		next = door->next;
		free(door);
		door = next;
	}
	cub3d->doors = NULL;
}

void	destroy_door_textures(t_game *cub3d)
{
	int	i;

	if (!cub3d->mlx.graphics)
		return ;
	i = 0;
	while (i < DOOR_FRAMES)
	{
		if (cub3d->door_tex[i].img_ptr)
		{
			mlx_destroy_image(cub3d->mlx.graphics,
				cub3d->door_tex[i].img_ptr);
			cub3d->door_tex[i].img_ptr = NULL;
		}
		i++;
	}
}
