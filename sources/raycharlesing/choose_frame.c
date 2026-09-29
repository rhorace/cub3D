/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 21:30:29 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/29 21:30:45 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	choose_opening_tex(t_game *cub)
{
	struct timeval	time;
	struct timeval	start;
	long			diff;
	int				i;

	gettimeofday(&time, NULL);
	start = cub->anim_encours.start;
	diff = (time.tv_sec * 1000) + (time.tv_usec / 1000)
		- ((start.tv_sec * 1000) + (start.tv_usec / 1000));
	i = diff / SPF;
	if (i >= ANIM_FRAME_NUMBER)
	{
		cub->map.grid[cub->anim_encours.y][cub->anim_encours.x] = '2';
		cub->anim_encours.opening = 0;
		return (ANIM_FRAME_NUMBER - 1);
	}
	return (i);
}

int	choose_closing_tex(t_game *cub)
{
	struct timeval	time;
	struct timeval	start;
	long			diff;
	int				i;

	gettimeofday(&time, NULL);
	start = cub->anim_encours.start;
	diff = (time.tv_sec * 1000) + (time.tv_usec / 1000)
		- ((start.tv_sec * 1000) + (start.tv_usec / 1000));
	i = diff / SPF;
	if (i >= ANIM_FRAME_NUMBER)
	{
		cub->map.grid[cub->anim_encours.y][cub->anim_encours.x] = 'D';
		cub->anim_encours.closing = 0;
		return (ANIM_FRAME_NUMBER - 1);
	}
	return (ANIM_FRAME_NUMBER -1 - i);
}
