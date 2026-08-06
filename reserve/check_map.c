/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 19:20:28 by rhorace           #+#    #+#             */
/*   Updated: 2026/07/07 19:20:31 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map(char **map)
{
	if (!map || !map[0])
		return (0);
	if (!check_player_count(map))
		return (0);
	if (!check_map_closed(map))
		return (0);
	return (1);
}
