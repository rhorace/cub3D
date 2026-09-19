/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:17:38 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/19 22:01:11 by rhorace          ###   ########.fr       */
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

static int	load_doors_textures(t_game *cub3d)
{
	if (!load_door_texture(cub3d, 0, "textures/door_0.xpm"))
		return (0);
	if (!load_door_texture(cub3d, 1, "textures/door_1.xpm"))
		return (0);
	if (!load_door_texture(cub3d, 2, "textures/door_2.xpm"))
		return (0);
	if (!load_door_texture(cub3d, 3, "textures/door_3.xpm"))
		return (0);
	if (!load_door_texture(cub3d, 4, "textures/door_4.xpm"))
		return (0);
	return (1);
}

static t_door	*new_door(int x, int y)
{
	t_door	*door;

	door = malloc(sizeof(t_door));
	if (!door)
		return (NULL);
	door->x = x;
	door->y = y;
	door->state = DOOR_CLOSED;
	door->frame = 0;
	door->timer = 0;
	door->next = NULL;
	return (door);
}

static void	add_door(t_door **doors, t_door *new)
{
	t_door	*current;

	if (!*doors)
	{
		*doors = new;
		return ;
	}
	current = *doors;
	while (current->next)
		current = current->next;
	current->next = new;
}

int	init_doors(t_game *cub3d)
{
	t_door	*door;
	int		x;
	int		y;

	cub3d->doors = NULL;
	if (!load_doors_textures(cub3d))
		return (0);
	y = 0;
	while (y < cub3d->map.height)
	{
		x = 0;
		while (cub3d->map.grid[y][x])
		{
			if (cub3d->map.grid[y][x] == 'D')
			{
				door = new_door(x, y);
				if (!door)
					return (0);
				add_door(&cub3d->doors, door);
			}
			x++;
		}
		y++;
	}
	return (1);
}
