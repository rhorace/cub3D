#include "cub3D.h"

int	init_mlx(t_game *cub3d)
{
	cub3d->mlx.graphics = mlx_init();
	if (!cub3d->mlx.graphics)
		return (0);
	cub3d->mlx.window = mlx_new_window(
			cub3d->mlx.graphics,
			WIN_WIDTH,
			WIN_HEIGHT,
			"cub3D");
	if (!cub3d->mlx.window)
		return (0);
	cub3d->mlx.image = mlx_new_image(
			cub3d->mlx.graphics,
			WIN_WIDTH,
			WIN_HEIGHT);
	if (!cub3d->mlx.image)
		return (0);
	cub3d->mlx.image_add = mlx_get_data_addr(
			cub3d->mlx.image,
			&cub3d->mlx.bits_per_pixel,
			&cub3d->mlx.line_length,
			&cub3d->mlx.endian);
	return (1);
}