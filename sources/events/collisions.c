/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:56:47 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/18 19:17:58 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	collision_haut(t_vector *current, t_game *cub, t_vector *move_dir)
{
	if (move_dir->y > 0 && ceiling_above(current->y))
	{
		if (cub->map.grid[(int)(current->y) + 1]
			[partie_entiere(current->x)] == '1')
			return (printf("collision par le haut\nx : %.2f\ny : %.2f\n",\
				current->x, current->y), printf("case : %d, %d\n",\
				partie_entiere(current->x), (int)(current->y) + 1), 1);
		if (cub->map.grid[(int)(current->y) + 1]
			[partie_entiere(current->x)] == 'D')
			return (printf("Porte fermeé par le haut\nx : %.2f\ny : %.2f\n",\
				current->x, current->y), printf("case : %d, %d\n",\
				partie_entiere(current->x), (int)(current->y) + 1), 1);
	}
	return (0);
}

static int	collision_bas(t_vector *current, t_game *cub, t_vector *move_dir)
{
	if (move_dir->y < 0 && mattress_under(current->y))
	{
		if (cub->map.grid[(int)(current->y) - 1]
			[partie_entiere(current->x)] == '1')
			return (printf("collision par le bas\nx : %.2f\ny : %.2f\n",\
				current->x, current->y), printf("case : %d, %d\n",\
				partie_entiere(current->x), (int)(current->y) - 1), 2);
		if (cub->map.grid[(int)(current->y) - 1]
			[partie_entiere(current->x)] == 'D')
			return (printf("Porte fermeé par le bas\nx : %.2f\ny : %.2f\n",\
				current->x, current->y), printf("case : %d, %d\n",\
				partie_entiere(current->x), (int)(current->y) - 1), 2);
	}
	return (0);
}

static int	collision_gauche(t_vector *current, t_game *cub, t_vector *move_dir)
{
	if (move_dir->x > 0 && ceiling_above(current->x))
	{
		if (cub->map.grid[partie_entiere(current->y)]
			[(int)(current->x) + 1] == '1')
			return (printf("collision par la gauche\nx : %.2f\ny : %.2f\n",\
				current->x, current->y), printf("case : %d, %d\n",\
				(int)(current->x) + 1, partie_entiere(current->y)), 3);
		if (cub->map.grid[partie_entiere(current->y)]
			[(int)(current->x) + 1] == 'D')
			return (printf("Porte fermeé par la gauche\nx : %.2f\ny : %.2f\n",\
				current->x, current->y), printf("case : %d, %d\n",\
				(int)(current->x) + 1, partie_entiere(current->y)), 3);
	}
	return (0);
}

static int	collision_droite(t_vector *current, t_game *cub, t_vector *move_dir)
{
	if (move_dir->x < 0 && mattress_under(current->x))
	{
		if (cub->map.grid[partie_entiere(current->y)]
			[(int)(current->x) - 1] == '1')
			return (printf("collision par la droite\n\nx : %.2f\ny : %.2f\n",\
				current->x, current->y), printf("case : %d, %d\n",\
				(int)(current->x) - 1, partie_entiere(current->y)), 4);
		if (cub->map.grid[partie_entiere(current->y)]
			[(int)(current->x) - 1] == 'D')
			return (printf("Porte fermeé par la droite\n\nx : %.2f\ny : %.2f\n",\
				current->x, current->y), printf("case : %d, %d\n",\
				(int)(current->x) - 1, partie_entiere(current->y)), 4);
	}
	return (0);
}

int	worlds_collide(t_vector *current, t_game *cub, t_vector *move_dir)
{
	if (collision_gauche(current, cub, move_dir) != 0)
		return (3);
	if (collision_droite(current, cub, move_dir) != 0)
		return (4);
	if (collision_haut(current, cub, move_dir) != 0)
		return (1);
	if (collision_bas(current, cub, move_dir) != 0)
		return (2);
	return (0);
}
