/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 09:21:14 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/14 11:02:50 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_tex_y(t_texture *texture, t_wall *wall, int y)
{
	float	step;
	float	tex_pos;
	int		tex_y;

	step = (float)texture->height / wall->height;
	tex_pos = (y - WIN_HEIGHT / 2 + wall->height / 2) * step;
	tex_y = (int)tex_pos;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= texture->height)
		tex_y = texture->height - 1;
	return (tex_y);
}

void	draw_wall(t_game *cub3d, int x, t_wall *wall, int texture_id)
{
	t_texture	*texture;
	int			tex_y;
	int			color;
	int			y;

	texture = &cub3d->tex[texture_id];
	y = wall->start;
	while (y <= wall->end)
	{
		tex_y = get_tex_y(texture, wall, y);
		color = get_texture_pixel(texture, wall->tex_x, tex_y);
		put_pixel(cub3d, x, y, color);
		y++;
	}
}
