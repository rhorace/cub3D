/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:54:47 by sohollar          #+#    #+#             */
/*   Updated: 2026/07/16 08:36:37 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(t_map *map)
{
	t_game		*g;

	g = ft_calloc(1, sizeof(t_game));
	if (!g)
		return (NULL);
	g->mlx = mlx_init();
	if (!g->mlx)
		return (free(g), NULL);
	g->win = mlx_new_window(g->mlx, LARGEUR_MAX, HAUTEUR_MAX, \
		"Stropharia's adventures");
	if (!g->win)
		return (mlx_destroy_display(g->mlx), free(g->mlx), free(g), NULL);
	g->set = ft_calloc(1, sizeof(t_textures));
	if (g->set == NULL)
		return (free_graphics(g), free(g), NULL);
	g->map = map;
	return (g);
}

int	so_so_long(t_game *g)
{
	if (!display(g))
		return (ft_printf_fd(2, "Error\nAlloc textures\n"), \
		free_graphics(g), g->map = NULL, 0);
	mlx_key_hook(g->win, (void *)handle_key, g);
	mlx_hook(g->win, 17, 0, (void *)close_win, g->mlx);
	mlx_loop(g->mlx);
	free_textures(g);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	return (g->map = NULL, 1);
}
