/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:25:56 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/10 08:26:02 by rhorace          ###   ########.fr       */
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
	render_frame(cub3d);
	return (0);
}
