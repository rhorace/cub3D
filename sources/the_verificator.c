/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_verificator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 11:29:15 by rhorace           #+#    #+#             */
/*   Updated: 2026/07/21 08:20:23 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	go_map(char **map)
{
	int	i;

	printf("... in go_map()\n");
	i = 0;
	while (map[i])
	{
		if (is_empty_line(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	the_verificator(t_game *cub3d)
{
	if (!path_ready(&cub3d->map) || !color_ready(&cub3d->ceiling, \
&cub3d->floor) || (cub3d->map.height < 3))
		close_cub3d(cub3d, 1);
	if (!go_map(cub3d->map.grid))
		close_cub3d(cub3d, 1);
	if (!check_player_count(cub3d->map.grid))
		close_cub3d(cub3d, 1);
	if (!check_map_closed(cub3d->map.grid))
		close_cub3d(cub3d, 1);
	return (1);
}
