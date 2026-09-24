/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 09:49:38 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/24 16:41:42 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	close_win(void *param)
{
	t_game	*cub3d;

	cub3d = (t_game *)param;
	close_cub3d(cub3d, 0);
	return (0);
}

static void	init_hooks(t_game *cub3d)
{
	mlx_hook(cub3d->mlx.window, KeyPress, KeyPressMask,
		(void *)key_presser, cub3d);
	mlx_hook(cub3d->mlx.window, KeyRelease, KeyReleaseMask,
		(void *)key_releaser, cub3d);
	mlx_hook(cub3d->mlx.window, 17, 0, (void *)close_win, cub3d);
}

int	main(int argc, char **argv)
{
	t_game	*cub3d;

	if (argc != 2)
		return (send_message("usage: ./cub3D <.cub>", NULL), 1);
	if (bad_extension(argv[1], ".cub"))
		return (send_message("Invalid file name", argv[1]), 1);
	cub3d = init_cub3d();
	if (!cub3d)
		return (send_message("Initialization failed", NULL), 1);
	if (bad_file(cub3d, argv[1]))
		return (close_cub3d(cub3d, 1), 1);
	if (verificator_failed(cub3d))
		return (close_cub3d(cub3d, 1), 1);
	if (init_mlx_failed(cub3d))
		return (close_cub3d(cub3d, 1), 1);
	if (load_textures_failed(cub3d))
		return (close_cub3d(cub3d, 1), 1);
	init_player(cub3d);
	rendu(cub3d);
	init_hooks(cub3d);
	mlx_loop_hook(cub3d->mlx.graphics, (void *)game_loop, cub3d);
	mlx_loop(cub3d->mlx.graphics);
	return (0);
}
