/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:08:55 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/29 21:22:20 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_game *cub3d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = cub3d->mlx.image_add
		+ (y * cub3d->mlx.line_length
			+ x * (cub3d->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	store_pixel(t_game *cub3d, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = cub3d->mlx.image_add + y * cub3d->mlx.line_length
		+ (x * cub3d->mlx.bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

int	rgb_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

void	remplir_fond(t_game *cub3d)
{
	int	y;
	int	x;
	int	ceiling;
	int	floor;

	ceiling = rgb_to_int(cub3d->ceiling);
	floor = rgb_to_int(cub3d->floor);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				store_pixel(cub3d, x, y, ceiling);
			else
				store_pixel(cub3d, x, y, floor);
			x++;
		}
		y++;
	}
}
