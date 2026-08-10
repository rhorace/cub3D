/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 09:49:38 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/10 14:48:57 by rhorace          ###   ########.fr       */
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

static void	usage(void)
{
	printf("%sUsage\n%s./cub3D map.cub%s\n", RED, YELLOW, RESET);
}

static void	init_hooks(t_game *cub3d)
{
	mlx_hook(cub3d->mlx.window, KeyPress, KeyPressMask,
		(void *)key_presser, cub3d);
	mlx_hook(cub3d->mlx.window, KeyRelease, KeyReleaseMask,
		(void *)key_releaser, cub3d);
	mlx_hook(cub3d->mlx.window, 17, 0,
		(void *)close_win, cub3d);
}

int	main(int argc, char **argv)
{
	t_game	cub3d;

	if (argc != 2)
		return (usage(), 1);
	ft_bzero(&cub3d, sizeof(t_game));
	ft_init(&cub3d);
	if (!check_extension(argv[1], ".cub"))
		return (send_message("Invalid file name", argv[1]), 1);
	if (!read_file(&cub3d, argv[1]))
		return (close_cub3d(&cub3d, 1), 1);
	print_etat(cub3d);
	print_map(cub3d.map.grid);
	if (!the_verificator(&cub3d))
		return (close_cub3d(&cub3d, 1), 1);
	if (!init_mlx(&cub3d))
		return (close_cub3d(&cub3d, 1), 1);
	if (!load_textures(&cub3d))
		return (close_cub3d(&cub3d, 1), 1);
	init_player(&cub3d);
	render_frame(&cub3d);
	init_hooks(&cub3d);
	mlx_loop_hook(cub3d.mlx.graphics, (void *)game_loop, &cub3d);
	mlx_loop(cub3d.mlx.graphics);
	return (0);
}
