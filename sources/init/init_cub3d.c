/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:49:38 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/17 14:01:11 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_colors(t_game *cub3d)
{
	cub3d->floor.r = -1;
	cub3d->floor.g = -1;
	cub3d->floor.b = -1;
	cub3d->ceiling.r = -1;
	cub3d->ceiling.g = -1;
	cub3d->ceiling.b = -1;
}

t_game	*init_cub3d(void)
{
	t_game	*cub3d;

	cub3d = ft_calloc(1, sizeof(t_game));
	if (!cub3d)
		return (NULL);
	init_colors(cub3d);
	return (cub3d);
}
