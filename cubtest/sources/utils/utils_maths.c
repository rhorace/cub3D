/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:06:33 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/15 19:25:16 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 2 manieres de l'ecrire : le cast en int fonctionne,
mais uniquement pour les nombres positifs.
Ce qui n'est pas genant vu que nos coordonnees sont positives dans notre repere.
Mais pour la forme et la rapidite du programme, pour prend l'autre ecriture. */
unsigned int	partie_entiere(float n)
{
	return (n / 1);
}

float	valeur_absolue(float n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	is_pos_int(float x)
{
	if (partie_entiere(valeur_absolue(x)) == x)
		return (1);
	return (0);
}

/* le rayon a une  direction tournee de theta par rapport a l'orientation du
joueur, avec theta = FOV * (-0.5 + (n / WIN_WIDTH)),
soit un decalage d'un demi FOV + n * le pas angulaire separant chaque rayon.
On calcule les coordonnees du vecteur tourne
en multipliant par la matrice de rotation */
void	matrix(t_vector *ray, t_game *cub, int n)
{
	ray->x = cub->player.dir.x * cos(FOV * (-0.5 + ((float)n / WIN_WIDTH)))
		- cub->player.dir.y * sin(FOV * (-0.5 + ((float)n / WIN_WIDTH)));
	ray->y = cub->player.dir.x * sin(FOV * (-0.5 + ((float)n / WIN_WIDTH)))
		+ cub->player.dir.y * cos(FOV * (-0.5 + ((float)n / WIN_WIDTH)));
}

float	y_moins_b_sur_a(t_vector *new, t_game *cub, t_vector ray)
{
	return (cub->player.pos.x + (ray.x / ray.y) * (new->y - cub->player.pos.y));
}
