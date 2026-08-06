/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:49:47 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/27 13:58:07 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_graphics(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
}

void	free_textures(t_game *g)
{
	if (g->set->joueur)
		mlx_destroy_image(g->mlx, g->set->joueur);
	if (g->set->joueur_out)
		mlx_destroy_image(g->mlx, g->set->joueur_out);
	if (g->set->collec)
		mlx_destroy_image(g->mlx, g->set->collec);
	if (g->set->sortie)
		mlx_destroy_image(g->mlx, g->set->sortie);
	if (g->set->mur)
		mlx_destroy_image(g->mlx, g->set->mur);
	if (g->set->chemin)
		mlx_destroy_image(g->mlx, g->set->chemin);
	if (g->set->visite)
		mlx_destroy_image(g->mlx, g->set->visite);
	free(g->set);
}
