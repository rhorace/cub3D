/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:26:20 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/18 18:50:12 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_game *cub3d)
{
	t_vector	new_pos;
	t_vector	move_dir;

	printf("j'essaie d'avancer, ");
	move_dir.x = cub3d->player.dir.x;
	move_dir.y = cub3d->player.dir.y;
	new_pos.x = cub3d->player.pos.x + move_dir.x * MOVE_SPEED;
	new_pos.y = cub3d->player.pos.y + move_dir.y * MOVE_SPEED;
	if (!worlds_collide(&new_pos, cub3d, &move_dir))
	{
		printf("j'avance\n");
		cub3d->player.pos.x = new_pos.x;
		cub3d->player.pos.y = new_pos.y;
	}
}

void	move_backward(t_game *cub3d)
{
	t_vector	new_pos;
	t_vector	move_dir;

	printf("j'essaie de reculer, ");
	move_dir.x = -cub3d->player.dir.x;
	move_dir.y = -cub3d->player.dir.y;
	new_pos.x = cub3d->player.pos.x + move_dir.x * MOVE_SPEED;
	new_pos.y = cub3d->player.pos.y + move_dir.y * MOVE_SPEED;
	if (!worlds_collide(&new_pos, cub3d, &move_dir))
	{
		printf("je recule\n");
		cub3d->player.pos.x = new_pos.x;
		cub3d->player.pos.y = new_pos.y;
	}
}

void	move_left(t_game *cub3d)
{
	t_vector	new_pos;
	t_vector	move_dir;

	printf("j'essaie d'aller a gauche, ");
	move_dir.x = cub3d->player.dir.y;
	move_dir.y = -cub3d->player.dir.x;
	new_pos.x = cub3d->player.pos.x + move_dir.x * MOVE_SPEED;
	new_pos.y = cub3d->player.pos.y + move_dir.y * MOVE_SPEED;
	if (!worlds_collide(&new_pos, cub3d, &move_dir))
	{
		printf("je vais a gauche\n");
		cub3d->player.pos.x = new_pos.x;
		cub3d->player.pos.y = new_pos.y;
	}
}

void	move_right(t_game *cub3d)
{
	t_vector	new_pos;
	t_vector	move_dir;

	printf("j'essaie d'aller a droite, ");
	move_dir.x = -cub3d->player.dir.y;
	move_dir.y = cub3d->player.dir.x;
	new_pos.x = cub3d->player.pos.x + move_dir.x * MOVE_SPEED;
	new_pos.y = cub3d->player.pos.y + move_dir.y * MOVE_SPEED;
	if (!worlds_collide(&new_pos, cub3d, &move_dir))
	{
		printf("je vais a droite\n");
		cub3d->player.pos.x = new_pos.x;
		cub3d->player.pos.y = new_pos.y;
	}
}

//C'est moi qui gère les collisions !
/* static int	collision(t_game *cub3d, float x, float y)
{
	if (cub3d->map.grid[(int)y][(int)x] == '1')
		return (0);
	return (1);
} */

/* void	move_forward(t_game *cub3d)
{
	float	new_x;
	float	new_y;

	new_x = cub3d->player.pos.x
		+ cub3d->player.dir.x * MOVE_SPEED;
	new_y = cub3d->player.pos.y
		+ cub3d->player.dir.y * MOVE_SPEED;
	if (collision(cub3d, new_x, cub3d->player.pos.y))
		cub3d->player.pos.x = new_x;
	if (collision(cub3d, cub3d->player.pos.x, new_y))
		cub3d->player.pos.y = new_y;
} */

/* void	move_backward(t_game *cub3d)
{
	float	new_x;
	float	new_y;

	new_x = cub3d->player.pos.x
		- cub3d->player.dir.x * MOVE_SPEED;
	new_y = cub3d->player.pos.y
		- cub3d->player.dir.y * MOVE_SPEED;
	if (collision(cub3d, new_x, cub3d->player.pos.y))
		cub3d->player.pos.x = new_x;
	if (collision(cub3d, cub3d->player.pos.x, new_y))
		cub3d->player.pos.y = new_y;
} */

/* void	move_left(t_game *cub3d)
{
	float	new_x;
	float	new_y;

	new_x = cub3d->player.pos.x
		+ cub3d->player.dir.y * MOVE_SPEED;
	new_y = cub3d->player.pos.y
		- cub3d->player.dir.x * MOVE_SPEED;
	if (collision(cub3d, new_x, cub3d->player.pos.y))
		cub3d->player.pos.x = new_x;
	if (collision(cub3d, cub3d->player.pos.x, new_y))
		cub3d->player.pos.y = new_y;
} */

/* void	move_right(t_game *cub3d)
{
	float	new_x;
	float	new_y;

	new_x = cub3d->player.pos.x
		- cub3d->player.dir.y * MOVE_SPEED;
	new_y = cub3d->player.pos.y
		+ cub3d->player.dir.x * MOVE_SPEED;
	if (collision(cub3d, new_x, cub3d->player.pos.y))
		cub3d->player.pos.x = new_x;
	if (collision(cub3d, cub3d->player.pos.x, new_y))
		cub3d->player.pos.y = new_y;
} */
