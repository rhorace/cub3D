/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:39:21 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/19 11:57:11 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_door	*get_door(t_game *cub3d, int x, int y)
{
	t_door	*door;

	door = cub3d->doors;
	while (door)
	{
		if (door->x == x && door->y == y)
			return (door);
		door = door->next;
	}
	return (NULL);
}
