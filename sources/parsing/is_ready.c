/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ready.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:59:54 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/10 17:24:01 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	path_ready(t_map *map)
{
	return (map->ea_path != NULL && map->no_path != NULL \
&& map->so_path != NULL && map->we_path != NULL);
}

int	ceiling_ready(t_color *plafond)
{
	return (plafond->r != -1 && plafond->g != -1 && plafond->b != -1);
}

int	floor_ready(t_color *sol)
{
	return (sol->r != -1 && sol->g != -1 && sol->b != -1);
}

int	color_ready(t_color *plafond, t_color *sol)
{
	return (ceiling_ready(plafond) && floor_ready(sol));
}
