/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:25:56 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/24 16:43:46 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	game_loop(t_game *cub3d)
{
	if (cub3d->player.key_up)
		move_forward(cub3d);
	if (cub3d->player.key_down)
		move_backward(cub3d);
	if (cub3d->player.key_left)
		move_left(cub3d);
	if (cub3d->player.key_right)
		move_right(cub3d);
	if (cub3d->player.key_rot_left)
		rotate_left(cub3d);
	if (cub3d->player.key_rot_right)
		rotate_right(cub3d);
	rendu(cub3d);
	return (0);
}

int	key_presser(int val, void *param)
{
	t_game	*cub3d;

	cub3d = (t_game *)param;
	if (val == XK_Escape)
		close_cub3d(cub3d, 0);
	if (val == XK_w || val == XK_z)
		cub3d->player.key_up = 1;
	if (val == XK_s)
		cub3d->player.key_down = 1;
	if (val == XK_a || val == XK_q)
		cub3d->player.key_left = 1;
	if (val == XK_d)
		cub3d->player.key_right = 1;
	if (val == XK_Left)
		cub3d->player.key_rot_left = 1;
	if (val == XK_Right)
		cub3d->player.key_rot_right = 1;
	return (0);
}

int	key_releaser(int val, void *param)
{
	t_game	*cub3d;

	cub3d = (t_game *)param;
	if (val == XK_w || val == XK_z)
		cub3d->player.key_up = 0;
	if (val == XK_s)
		cub3d->player.key_down = 0;
	if (val == XK_a || val == XK_q)
		cub3d->player.key_left = 0;
	if (val == XK_d)
		cub3d->player.key_right = 0;
	if (val == XK_Left)
		cub3d->player.key_rot_left = 0;
	if (val == XK_Right)
		cub3d->player.key_rot_right = 0;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_game	*cub3d;
	int		delta_x;

	(void)y;
	cub3d = (t_game *)param;
	if (cub3d->mlx.mouse_x == -1)
	{
		cub3d->mlx.mouse_x = x;
		return (0);
	}
	delta_x = x - cub3d->mlx.mouse_x;
	cub3d->mlx.mouse_x = x;
	if (delta_x < 0)
		rotate_left(cub3d);
	else if (delta_x > 0)
		rotate_right(cub3d);
	return (0);
}
