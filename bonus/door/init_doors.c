/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 16:45:31 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/24 16:45:32 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
