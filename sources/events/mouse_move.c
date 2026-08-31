#include "cub3D.h"

int	mouse_move(int x, int y, void *param)
{
	t_game	*cub3d;
	int		center_x;

	(void)y;
	cub3d = (t_game *)param;
	center_x = WIN_WIDTH / 2;

	if (x < center_x)
		rotate_left(cub3d);
	else if (x > center_x)
		rotate_right(cub3d);

	mlx_mouse_move(cub3d->mlx.graphics,
		cub3d->mlx.window,
		center_x,
		WIN_HEIGHT / 2);
	return (0);
}