/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:25:38 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/18 19:30:59 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	haut(t_vector *current, t_game *cub, t_vector *ray)
{
	if (is_pos_int(current->y))
	{
		if (ray->y > 0)
		{
			if (cub->map.grid[(int)(current->y)]
				[partie_entiere(current->x)] == '1')
				return (TEX_NO);
			else if (cub->map.grid[(int)(current->y)]
				[partie_entiere(current->x)] == 'D')
				return (TEX_DO);
		}
	}
	return (0);
}

static int	bas(t_vector *current, t_game *cub, t_vector *ray)
{
	if (is_pos_int(current->y))
	{
		if (ray->y < 0)
		{
			if (cub->map.grid[(int)(current->y) - 1]
				[partie_entiere(current->x)] == '1')
				return (TEX_SO);
			else if (cub->map.grid[(int)(current->y) - 1]
				[partie_entiere(current->x)] == 'D')
				return (TEX_DO);
		}
	}
	return (0);
}

static int	gauche(t_vector *current, t_game *cub, t_vector *ray)
{
	if (is_pos_int(current->x))
	{
		if (ray->x > 0)
		{
			if (cub->map.grid[partie_entiere(current->y)]
				[(int)(current->x)] == '1')
				return (TEX_WE);
			else if (cub->map.grid[partie_entiere(current->y)]
				[(int)(current->x)] == 'D')
				return (TEX_DO);
		}
	}
	return (0);
}

static int	droite(t_vector *current, t_game *cub, t_vector *ray)
{
	if (is_pos_int(current->x))
	{
		if (ray->x < 0)
		{
			if (cub->map.grid[partie_entiere(current->y)]
				[(int)(current->x) - 1] == '1')
				return (TEX_EA);
			else if (cub->map.grid[partie_entiere(current->y)]
				[(int)(current->x) - 1] == 'D')
				return (TEX_DO);
		}
	}
	return (0);
}

int	is_wall_or_door(t_vector *current, t_game *cub, t_vector *ray)
{
	if (gauche(current, cub, ray) != 0)
		return (gauche(current, cub, ray));
	if (droite(current, cub, ray) != 0)
		return (droite(current, cub, ray));
	if (haut(current, cub, ray) != 0)
		return (haut(current, cub, ray));
	if (bas(current, cub, ray) != 0)
		return (bas(current, cub, ray));
	return (0);
}
