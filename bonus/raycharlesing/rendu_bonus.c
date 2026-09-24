/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:27:50 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/24 16:50:04 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* on se deplace dans la direction du rayon vers le y entier le plus proche,
puis on calcule x en restant sur la droite du rayon,
de formule x = (y - b) / a, ou a est la pente et b l'ordonnee a l'origine.
Si x a depasse un entier en premier,
on se repositionne en recalculant y a partir de lui*/
static void	tarzan(t_vector *current, t_vector *new, t_game *cub, t_vector ray)
{
	if (ray.x == 0)
		jack_on_the_magic_bean(current, new, cub, ray);
	else if (ray.y == 0)
		run_forrest(current, new, cub, ray);
	else
	{
		if (current->y == 0)
			init_ray(current, new, cub, ray);
		else
		{
			if (current->y - partie_entiere(current->y) == 0)
				new->y = current->y + (ray.y / valeur_absolue(ray.y));
			else
			{
				if (ray.y > 0)
					new->y = partie_entiere(current->y) + 1;
				else
					new->y = partie_entiere(current->y);
			}
			new->x = y_moins_b_sur_a(new, cub, ray);
		}
		reloc(current, new, cub, ray);
	}
}

static void	hit_the_wall_jack(t_game *cub, int n)
{
	t_vector	ray;
	t_vector	current;
	t_vector	new;
	t_wall_hit	wall;

	matrix(&ray, cub, n);
	current.y = 0;
	wall.tex = 0;
	wall.side = 0;
	while (!wall.side)
	{
		tarzan(&current, &new, cub, ray);
		current.x = new.x;
		current.y = new.y;
		wall = is_wall_or_door(&current, cub, &ray);
	}
	put_column(&wall, current, n, cub);
}

void	rendu(t_game *cub3d)
{
	int	x;

	x = 0;
	remplir_fond(cub3d);
	while (x < WIN_WIDTH)
	{
		hit_the_wall_jack(cub3d, x);
		x++;
	}
	draw_minimap(cub3d);
	mlx_put_image_to_window(cub3d->mlx.graphics, cub3d->mlx.window,
		cub3d->mlx.image, 0, 0);
}
