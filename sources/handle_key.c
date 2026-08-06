/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 10:50:00 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/06 15:57:19 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_presser(int val, void *param)
{
	t_game	*cub3d;

	cub3d = (t_game *)param;
	if (val == XK_Escape)
		close_cub3d(cub3d, 0);
	if (val == XK_w)
	{
		printf("%sW: J'avance.%s\n", GREEN, RESET);
		cub3d->player.key_up = 1;
	}
	if (val == XK_s)
		cub3d->player.key_down = 1;
	if (val == XK_a)
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
	if (val == XK_w)
	{
		printf("%sW: Je n'avance plus.%s\n", RED, RESET);
		cub3d->player.key_up = 0;
	}
	if (val == XK_s)
		cub3d->player.key_down = 0;
	if (val == XK_a)
		cub3d->player.key_left = 0;
	if (val == XK_d)
		cub3d->player.key_right = 0;
	if (val == XK_Left)
		cub3d->player.key_rot_left = 0;
	if (val == XK_Right)
		cub3d->player.key_rot_right = 0;
	return (0);
}
