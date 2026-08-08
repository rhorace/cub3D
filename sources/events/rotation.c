#include "cub3D.h"

#define ROT_SPEED 0.03

void	rotate_left(t_game *cub3d)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = cub3d->player.dir.x;
	cub3d->player.dir.x = cub3d->player.dir.x * cos(-ROT_SPEED)
		- cub3d->player.dir.y * sin(-ROT_SPEED);
	cub3d->player.dir.y = old_dir_x * sin(-ROT_SPEED)
		+ cub3d->player.dir.y * cos(-ROT_SPEED);
	old_plane_x = cub3d->player.plane.x;
	cub3d->player.plane.x = cub3d->player.plane.x * cos(-ROT_SPEED)
		- cub3d->player.plane.y * sin(-ROT_SPEED);
	cub3d->player.plane.y = old_plane_x * sin(-ROT_SPEED)
		+ cub3d->player.plane.y * cos(-ROT_SPEED);
}

void	rotate_right(t_game *cub3d)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = cub3d->player.dir.x;
	cub3d->player.dir.x = cub3d->player.dir.x * cos(ROT_SPEED)
		- cub3d->player.dir.y * sin(ROT_SPEED);
	cub3d->player.dir.y = old_dir_x * sin(ROT_SPEED)
		+ cub3d->player.dir.y * cos(ROT_SPEED);
	old_plane_x = cub3d->player.plane.x;
	cub3d->player.plane.x = cub3d->player.plane.x * cos(ROT_SPEED)
		- cub3d->player.plane.y * sin(ROT_SPEED);
	cub3d->player.plane.y = old_plane_x * sin(ROT_SPEED)
		+ cub3d->player.plane.y * cos(ROT_SPEED);
}