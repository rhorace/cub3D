/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tarzan_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 17:20:05 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/23 23:27:01 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	reloc(t_vector *current, t_vector *new, t_game *cub, t_vector ray)
{
	if (ray.x < 0)
	{
		if (new->x < partie_entiere(current->x)
			&& !(current->x == partie_entiere(new->x) + 1))
		{
			if (!(current->x == partie_entiere(current->x)))
				new->x = partie_entiere(current->x);
			else
				new->x = partie_entiere(current->x) - 1;
			new->y = (new->x * ray.y / ray.x)
				+ cub->player.pos.y - (cub->player.pos.x * ray.y / ray.x);
		}
	}
	else if (ray.x > 0)
	{
		if (new->x > partie_entiere(current->x) + 1)
		{
			new->x = partie_entiere(current->x) + 1;
			new->y = (new->x * ray.y / ray.x)
				+ cub->player.pos.y - (cub->player.pos.x * ray.y / ray.x);
		}
	}
}

void	jack_on_the_magic_bean(t_vector *current, t_vector *new,
	t_game *cub, t_vector ray)
{
	if (current->y == 0)
	{
		if (ray.y > 0)
			new->y = partie_entiere(cub->player.pos.y) + 1;
		else
			new->y = partie_entiere(cub->player.pos.y);
		new->x = cub->player.pos.x;
	}
	else
		new->y = current->y + (ray.y / valeur_absolue(ray.y));
}

void	run_forrest(t_vector *current, t_vector *new,
	t_game *cub, t_vector ray)
{
	if (current->y == 0)
	{
		if (ray.x > 0)
			new->x = partie_entiere(cub->player.pos.x) + 1;
		else
			new->x = partie_entiere(cub->player.pos.x);
		new->y = cub->player.pos.y;
	}
	else
		new->x = current->x + (ray.x / valeur_absolue(ray.x));
}

/* void	init_ray(t_vector *current, t_vector *new, t_game *cub, t_vector ray)
{
	current->y = cub->player.pos.y;
	current->x = cub->player.pos.x;
	new->y = cub->player.pos.y + 0.5 * (ray.y / valeur_absolue(ray.y));
	new->x = y_moins_b_sur_a(new, cub, ray);
} */

void	init_ray(t_vector *current, t_vector *new, t_game *cub, t_vector ray)
{
	current->y = cub->player.pos.y;
	current->x = cub->player.pos.x;
	if (ray.y > 0)
		new->y = partie_entiere(cub->player.pos.y) + 1;
	else
		new->y = partie_entiere(cub->player.pos.y);
	new->x = y_moins_b_sur_a(new, cub, ray);
}
