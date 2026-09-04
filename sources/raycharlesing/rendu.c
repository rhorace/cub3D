/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:27:50 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/04 16:11:41 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	charles_ray(t_game *cub3d, int x)
{
	float	theta;
	theta
}

//mais donc ici on ne stocke pas les pixels pour tous les afficher d'un coup, on les affiche un a un
int	put_pixel(t_game *cub3d, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return (0);
	pixel = cub3d->mlx.image_add + y * cub3d->mlx.line_length
		+ x * cub3d->mlx.bits_per_pixel;
	*(unsigned int *)pixel = color;
}

int	rgb_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

int	remplir_fond(t_game *cub3d)
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
				put_pixel(cub3d, x, y, ceiling);
			else
				put_pixel(cub3d, x, y, floor);
			x++;
		}
		y++;
	}
}

int	rendu(t_game *cub3d)
{
	int	x;

	x = 0;
	remplir_fond(cub3d);
	while (x < WIN_WIDTH)
	{
		charles_ray(cub3d, x);
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx.graphics, cub3d->mlx.window,
		cub3d->mlx.image, 0, 0);
}
