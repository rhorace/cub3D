/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:06:12 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/24 16:16:30 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static int	closing : Empêche double free/double destroy (ESC + croix, etc.)

static void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_grid(map->grid);
	free(map->no_path);
	free(map->so_path);
	free(map->we_path);
	free(map->ea_path);
	map->grid = NULL;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
}

static void	destroy_textures(t_game *cub3d)
{
	int	i;

	if (!cub3d->mlx.graphics)
		return ;
	i = 0;
	while (i < 4)
	{
		if (cub3d->tex[i].img_ptr)
		{
			mlx_destroy_image(cub3d->mlx.graphics,
				cub3d->tex[i].img_ptr);
			cub3d->tex[i].img_ptr = NULL;
		}
		i++;
	}
}

static void	destroy_mlx(t_game *cub3d)
{
	if (!cub3d->mlx.graphics)
		return ;
	if (cub3d->mlx.image)
	{
		mlx_destroy_image(cub3d->mlx.graphics,
			cub3d->mlx.image);
		cub3d->mlx.image = NULL;
	}
	if (cub3d->mlx.window)
	{
		mlx_destroy_window(cub3d->mlx.graphics,
			cub3d->mlx.window);
		cub3d->mlx.window = NULL;
	}
	mlx_destroy_display(cub3d->mlx.graphics);
	free(cub3d->mlx.graphics);
	cub3d->mlx.graphics = NULL;
}

void	close_cub3d(t_game	*cub3d, int code)
{
	static int	closing;

	if (closing)
		exit(code);
	closing = 1;
	if (!cub3d)
		exit(code);
	destroy_textures(cub3d);
	destroy_mlx(cub3d);
	free_map(&cub3d->map);
	free(cub3d);
	exit(code);
}
