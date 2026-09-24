/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_verificator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 11:29:15 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/24 17:19:00 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	bad_texture_extension(t_game *cub3d)
{
	if (bad_extension(cub3d->map.no_path, ".xpm"))
		return (1);
	if (bad_extension(cub3d->map.so_path, ".xpm"))
		return (1);
	if (bad_extension(cub3d->map.we_path, ".xpm"))
		return (1);
	if (bad_extension(cub3d->map.ea_path, ".xpm"))
		return (1);
	return (0);
}

static int	map_have_empty_line(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (send_message("No map !", NULL), 1);
	while (map[i])
	{
		if (is_empty_line(map[i]))
			return (send_message("Empty line in the map !", NULL), 1);
		i++;
	}
	return (0);
}

int	verificator_failed(t_game *cub3d)
{
	if (!texture_ready(&cub3d->map) || !color_ready(&cub3d->ceiling, \
&cub3d->floor) || (cub3d->map.height < 3))
		return (send_message("map, texture or color !", NULL), 1);
	if (bad_texture_extension(cub3d))
		return (1);
	if (map_have_empty_line(cub3d->map.grid))
		return (1);
	if (bad_player_count(cub3d->map.grid))
		return (1);
	if (map_not_closed(cub3d->map.grid))
		return (1);
	return (0);
}
