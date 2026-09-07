/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:27:50 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/07 21:27:47 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	is_wall(t_vector v)
{

}

int	charles_ray(t_game *cub3d, int n)
{
	t_vector	ray;
	float		theta;
	float		pente;
	float		origine;
	t_vector	current;
	t_vector	new;

	theta = FOV * (-0.5 + (n / WIN_WIDTH));
	ray.x = cub3d->player.dir.x * cos(theta) - cub3d->player.dir.y * sin(theta);
	ray.y = cub3d->player.dir.x * sin(theta) + cub3d->player.dir.y * cos(theta);
	pente = ray.x / ray.y;
	origine = cub3d->player.pos.y - (cub3d->player.pos.x * ray.y / ray.x);
	current.y = cub3d->player.pos.y + 0.5 * (ray.y / abs(ray.y));
	current.x = (current.y - origine) / pente;
	if (ray.x < 0 && ray.y < 0)
		{
			if (new.x < abs(current.x))
		}
		if (ray.x > 0 && ray.y < 0)
		{
			if (new.x > abs(current.x) + 1)
		}
		if (ray.x < 0 && ray.y > 0)
		{
			if (new.x < abs(current.x))
		}
		if (ray.x > 0 && ray.y > 0)
		{
			if (new.x > abs(current.x) + 1)
		}
	while (!is_wall(current))
	{
		new.y = current.y + (ray.y / abs(ray.y));
		new.x = (current.y - origine) / pente;
		if (ray.x < 0 && ray.y < 0)
		{
			if (new.x < abs(current.x))
		}
		if (ray.x > 0 && ray.y < 0)
		{
			if (new.x > abs(current.x) + 1)
		}
		if (ray.x < 0 && ray.y > 0)
		{
			if (new.x < abs(current.x))
		}
		if (ray.x > 0 && ray.y > 0)
		{
			if (new.x > abs(current.x) + 1)
		}
	}
}

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
