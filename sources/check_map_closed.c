/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 19:20:41 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/06 15:52:28 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	get_map_char(char **map, int y, int x)
{
	int	i;

	if (y < 0 || x < 0)
		return (' ');
	i = 0;
	while (map[i])
		i++;
	if (y >= i)
		return (' ');
	i = 0;
	while (map[y][i])
		i++;
	if (x >= i)
		return (' ');
	return (map[y][x]);
}

static int	check_cell_closed(char **map, int y, int x)
{
	if (get_map_char(map, y - 1, x) == ' ')
		return (0);
	if (get_map_char(map, y + 1, x) == ' ')
		return (0);
	if (get_map_char(map, y, x - 1) == ' ')
		return (0);
	if (get_map_char(map, y, x + 1) == ' ')
		return (0);
	return (1);
}

static int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	check_map_closed(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!is_valid_map_char(map[y][x]))
			{
				printf("Invalid map char %d, %d %c\n", x, y, map[y][x]);
				return (0);
			}
			if (is_walkable(map[y][x]))
			{
				if (!check_cell_closed(map, y, x))
				{
					printf("x:%d y: %d\n", x, y);
					return (send_message("Map not closed !", NULL), 0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}
