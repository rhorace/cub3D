/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:27:50 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/08 21:50:11 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	is_wall(t_vector current, t_game cub, t_vector ray)
{
	return (coin(current, cub, ray) || gauche(current, cub, ray)
		|| droite(current, cub, ray) || haut(current, cub, ray)
		|| bas()current, cub, ray);
}

void	reloc(t_vector *current, t_vector *new, t_game cub, t_vector ray)
{
	//if (ray.y < 0)
	//{
		if (ray.x < 0)
		{
			if (new->x < abs(current.x))
			{
				new->x = abs(new->x) + 1;
				new->y = (new->x * ray.x / ray.y)
					+ cub.player.pos.y - (cub.player.pos.x * ray.y / ray.x);
			}
		}
		if (ray.x > 0)
		{
			if (new->x > abs(current->x) + 1)
			{
				new->x = abs(new->x);
				new->y = (new->x * ray.x / ray.y)
					+ cub.player.pos.y - (cub.player.pos.x * ray.y / ray.x);
			}
		}
	//}
	//else
	//{
	/*	if (ray.x < 0)
		{
			if (new.x < abs(current.x))
			{
				new->x = abs(new->x) + 1;
				new->y = (new->x * ray.x / ray.y)
					+ cub.player.pos.y - (cub.player.pos.x * ray.y / ray.x);
			}
		}
		if (ray.x > 0)
		{
			if (new.x > abs(current.x) + 1)
			{
				new->x = abs(new->x);
				new->y = (new->x * ray.x / ray.y)
					+ cub.player.pos.y - (cub.player.pos.x * ray.y / ray.x);
			}
		}*/
	//}
	/*if (ray.x < 0 && ray.y < 0)
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
	}*/

}

void	tarzan(t_vector *current, t_vector *new, t_game cub, t_vector ray)
{
	if (current->y == 0)
	{
			new->y = cub3->player.pos.y + 0.5 * (ray.y / abs(ray.y));
			new->x = (new->y - cub3d.player.pos.y
				+ (cub3d.player.pos.x * ray.y / ray.x)) * (ray.y / ray.x);
	}
	else
	{
		if (current->y - abs(current->y) == 0)
			new->y = current->y + (ray.y / abs(ray.y));
		else
		{
			if (ray.y > 0)
				new->y = abs(current->y) + 1;
			else
				new->y = abs(current->y);
		}
		new->x = (new->y - cub3d.player.pos.y
			+ (cub3d.player.pos.x * ray.y / ray.x)) * (ray.y / ray.x);
	}
	reloc(&current, &new, cub3d, ray);
}

void	matrix(t_vector *ray, t_game cub, int	n)
{
	ray->x = cub->player.dir.x * cos(FOV * (-0.5 + (n / WIN_WIDTH)))
		- cub->player.dir.y * sin(FOV * (-0.5 + (n / WIN_WIDTH)));
	ray->y = cub->player.dir.x * sin(FOV * (-0.5 + (n / WIN_WIDTH)))
		+ cub->player.dir.y * cos(FOV * (-0.5 + (n / WIN_WIDTH)));
}

int	hit_the_wall_jack(t_game *cub, int n)
{
	t_vector	ray;
	float		origine;
	t_vector	current;
	t_vector	new;

	matrix(&ray, cub, n);
	current.y = 0;
	while (!is_wall(current, cub, ray))
	{
		tarzan(&current, &new, cub, ray);
		current->x = new->x;
		current->y = new->y;
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
		hit_the_wall_jack(cub3d, x);
		x++;
	}
	mlx_put_image_to_window(cub3d->mlx.graphics, cub3d->mlx.window,
		cub3d->mlx.image, 0, 0);
}
