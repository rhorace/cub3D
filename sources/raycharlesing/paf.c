/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:25:38 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/23 20:01:22 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* static int	haut(t_vector *current, t_game *cub, t_vector *ray,
	t_wall_hit *wall)
{
	char	c;

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
} */

static void	haut(t_vector *current, t_game *cub, t_vector *ray,
	t_wall_hit *wall)
{
	char	c;

	if (is_pos_int(current->y))
	{
		c = cub->map.grid[(int)(current->y)][partie_entiere(current->x)];
		if (ray->y > 0)
		{
			if (c == '1' || c == 'D')
			{
				wall->side = SI_NO;
				if (c == '1')
					wall->tex = TEX_NO;
				else
					wall->tex = TEX_DO;
			}
		}
	}
}

static void	bas(t_vector *current, t_game *cub, t_vector *ray,
	t_wall_hit *wall)
{
	char	c;

	if (is_pos_int(current->y))
	{
		c = cub->map.grid[(int)(current->y) - 1][partie_entiere(current->x)];
		if (ray->y < 0)
		{
			if (c == '1' || c == 'D')
			{
				wall->side = SI_SO;
				if (c == '1')
					wall->tex = TEX_SO;
				else
					wall->tex = TEX_DO;
			}
		}
	}
}

/* static int	bas(t_vector *current, t_game *cub, t_vector *ray,
	t_wall_hit *wall)
{
	char	c;

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
} */

static void	gauche(t_vector *current, t_game *cub, t_vector *ray,
	t_wall_hit *wall)
{
	char	c;

	if (is_pos_int(current->x))
	{
		c = cub->map.grid[partie_entiere(current->y)][(int)(current->x)];
		if (ray->x > 0)
		{
			if (c == '1' || c == 'D')
			{
				wall->side = SI_WE;
				if (c == '1')
					wall->tex = TEX_WE;
				else
					wall->tex = TEX_DO;
			}
		}
	}
}

static void	droite(t_vector *current, t_game *cub, t_vector *ray,
	t_wall_hit *wall)
{
	char	c;

	if (is_pos_int(current->x))
	{
		c = cub->map.grid[partie_entiere(current->y)][(int)(current->x) - 1];
		if (ray->x < 0)
		{
			if (c == '1' || c == 'D')
			{
				wall->side = SI_EA;
				if (c == '1')
					wall->tex = TEX_EA;
				else
					wall->tex = TEX_DO;
			}
		}
	}
}

/* static int	droite(t_vector *current, t_game *cub, t_vector *ray,
	t_wall_hit *wall)
{
	char	c;

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
} */

/* t_wall_hit	is_wall_or_door(t_vector *current, t_game *cub)
{
	if (gauche(current, cub, ray) != 0)
		return (gauche(current, cub, ray));
	if (droite(current, cub, ray) != 0)
		return (droite(current, cub, ray));
	if (haut(current, cub, ray) != 0)
		return (haut(current, cub, ray));
	if (bas(current, cub, ray) != 0)
		return (bas(current, cub, ray));
	return (wall);
} */

t_wall_hit	is_wall_or_door(t_vector *current, t_game *cub, t_vector *ray)
{
	t_wall_hit	wall;

	wall.tex = 0;
	wall.side = 0;
	gauche(current, cub, ray, &wall);
	droite(current, cub, ray, &wall);
	haut(current, cub, ray, &wall);
	bas(current, cub, ray, &wall);
	return (wall);
}
