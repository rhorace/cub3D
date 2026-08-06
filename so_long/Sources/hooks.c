/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:25:53 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/28 18:12:47 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(void *mlx)
{
	static int	closing;

	if (closing)
		return (0);
	closing = 1;
	if (mlx)
		mlx_loop_end(mlx);
	return (0);
}

int	handle_key(int keycode, t_game *g)
{
	int	move;

	move = 0;
	if (keycode == KEY_ESC)
		close_win(g->mlx);
	else if (keycode == KEY_UP)
		move = -(g->map->largeur);
	else if (keycode == KEY_DOWN)
		move = g->map->largeur;
	else if (keycode == KEY_LEFT)
		move = -1;
	else if (keycode == KEY_RIGHT)
		move = 1;
	else
		return (0);
	bouger(g, move, keycode);
	return (0);
}
