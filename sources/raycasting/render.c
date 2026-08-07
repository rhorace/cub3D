/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 09:18:23 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/07 10:06:57 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_frame(t_game *cub3d)
{
	int	x;

	draw_background(cub3d);
	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_ray(cub3d, x);
		x++;
	}
	mlx_put_image_to_window(
		cub3d->mlx.graphics,
		cub3d->mlx.window,
		cub3d->mlx.image,
		0,
		0);
}
