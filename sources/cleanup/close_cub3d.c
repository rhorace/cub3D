/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:06:12 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/10 08:42:04 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static int	closing : Empêche double free/double destroy (ESC + croix, etc.)

static void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	close_mlx(t_game *cub3d)
{
	if (cub3d->mlx.window)
	{
		mlx_destroy_window(cub3d->mlx.graphics, cub3d->mlx.window);
		cub3d->mlx.window = NULL;
	}
	if (cub3d->mlx.graphics)
	{
		mlx_destroy_display(cub3d->mlx.graphics);
		free(cub3d->mlx.graphics);
		cub3d->mlx.graphics = NULL;
	}
}

void	close_cub3d(t_game	*cub3d, int code)
{
	static int	closing;

	closing = 0;
	if (!cub3d)
		exit(code);
	if (closing)
		exit(code);
	closing = 1;
	close_mlx(cub3d);
	free(cub3d->map.no_path);
	free(cub3d->map.so_path);
	free(cub3d->map.we_path);
	free(cub3d->map.ea_path);
	free_tab(cub3d->map.grid);
	cub3d->map.grid = NULL;
	exit(code);
}
