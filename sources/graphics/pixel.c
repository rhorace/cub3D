/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 09:21:21 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/21 17:15:54 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_game *cub3d, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_WIDTH)
		return ;
	if (y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = cub3d->mlx.image_add
		+ (y * cub3d->mlx.line_length
			+ x * (cub3d->mlx.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	get_texture_pixel(t_texture *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= texture->width)
		return (0);
	if (y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr
		+ (y * texture->line_length
			+ x * (texture->bpp / 8));
	return (*(unsigned int *)pixel);
}

int	rgb_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}
