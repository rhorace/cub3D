/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_verificator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 11:29:15 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/14 13:11:39 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_texture(t_game *cub3d)
{
	if (!check_extension(cub3d->map.no_path, ".xpm"))
		return (0);
	if (!check_extension(cub3d->map.so_path, ".xpm"))
		return (0);
	if (!check_extension(cub3d->map.we_path, ".xpm"))
		return (0);
	if (!check_extension(cub3d->map.ea_path, ".xpm"))
		return (0);
	return (1);
}

static int	check_empty_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_empty_line(map[i]))
			return (send_message("Empty line in the map !", NULL), 0);
		i++;
	}
	return (1);
}

int	the_verificator(t_game *cub3d)
{
	if (!texture_ready(&cub3d->map) || !color_ready(&cub3d->ceiling, \
&cub3d->floor) || (cub3d->map.height < 3))
		return (0);
	if (!check_texture(cub3d))
		return (0);
	if (!check_empty_line(cub3d->map.grid))
		return (0);
	if (!check_player_count(cub3d->map.grid))
		return (0);
	if (!check_map_closed(cub3d->map.grid))
		return (0);
	return (1);
}
