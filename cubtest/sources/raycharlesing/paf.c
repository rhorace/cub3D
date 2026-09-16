/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:25:38 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/14 17:10:19 by sohollar         ###   ########.fr       */
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
			{
				ray->y = current->y;
				ray->x = partie_entiere(current->x);
				return (1);
			}
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
			{
				ray->x = partie_entiere(current->x);
				ray->y = current->y - 1;
				return (2);
			}
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
			{
				ray->x = current->x;
				ray->y = partie_entiere(current->y);
				return (3);
			}
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
			{
				ray->y = partie_entiere(current->y);
				ray->x = current->x - 1;
				return (4);
			}
		}
	}
	return (0);
}

int	is_wall(t_vector *current, t_game *cub, t_vector *ray)
{
	if (gauche(current, cub, ray) != 0)
		return (3);
	if (droite(current, cub, ray) != 0)
		return (4);
	if (haut(current, cub, ray) != 0)
		return (1);
	if (bas(current, cub, ray) != 0)
		return (2);
	return (0);
}
