/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:27:21 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/27 16:55:38 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	charger_img(void *mlx, char *path, void **elem)
{
	int		s;

	s = IMG_PIX;
	*elem = mlx_xpm_file_to_image(mlx, path, &s, &s);
	if (!(*elem))
		return (0);
	return (1);
}

static int	charger_textures(t_game *g)
{
	if (!(charger_img(g->mlx, "Textures/Joueur_chemin.xpm", &(g->set->joueur))))
		return (free_textures(g), 0);
	if (!(charger_img(g->mlx, "Textures/Victoire.xpm", &(g->set->joueur_out))))
		return (free_textures(g), 0);
	if (!(charger_img(g->mlx, "Textures/Accordeon.xpm", &(g->set->collec))))
		return (free_textures(g), 0);
	if (!(charger_img(g->mlx, "Textures/Teldrassyl.xpm", &(g->set->sortie))))
		return (free_textures(g), 0);
	if (!(charger_img(g->mlx, "Textures/Mur.xpm", &(g->set->mur))))
		return (free_textures(g), 0);
	if (!(charger_img(g->mlx, "Textures/Chemin.xpm", &(g->set->chemin))))
		return (free_textures(g), 0);
	if (!(charger_img(g->mlx, "Textures/Visite_sortie.xpm", &(g->set->visite))))
		return (free_textures(g), 0);
	return (1);
}

static void	put_tex(int i, t_game *g)
{
	int		x;
	int		y;

	x = (i % g->map->largeur) * IMG_PIX;
	y = (i / g->map->largeur) * IMG_PIX;
	if (g->map->map[i] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->set->mur, x, y);
	else if (g->map->map[i] == 'o' || g->map->map[i] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->set->chemin, x, y);
	else if (g->map->map[i] == 'e')
		mlx_put_image_to_window(g->mlx, g->win, g->set->sortie, x, y);
	else if (g->map->map[i] == 'c')
		mlx_put_image_to_window(g->mlx, g->win, g->set->collec, x, y);
	else if (g->map->map[i] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->set->joueur, x, y);
	else
		return ;
}

int	display(t_game *g)
{
	int	i;

	i = 0;
	if (!charger_textures(g))
		return (0);
	while (g->map->map[i])
	{
		put_tex(i, g);
		i++;
	}
	return (1);
}
