/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 09:49:38 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/07 09:08:36 by rhorace          ###   ########.fr       */
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
	printf("%sUsage\n%s./cub3D <filename>%s\n", RED, YELLOW, RESET);
}

int	main(int argc, char **argv)
{
	t_game	cub3d;

	ft_bzero(&cub3d, sizeof(t_game));
	ft_init(&cub3d);
	if (argc != 2)
		return (usage(), 1);
	if (!check_extension(argv[1], ".cub"))
		return (send_message("Invalid file name", argv[1]), 1);
	print_etat(cub3d);
	print_map(cub3d.map.grid);
	if (!read_line(&cub3d, argv[1]))
		return (1);
	print_etat(cub3d);
	print_map(cub3d.map.grid);
	cub3d.mlx.graphics = mlx_init();
	if (!cub3d.mlx.graphics)
		return (1);
	cub3d.mlx.window = mlx_new_window(cub3d.mlx.graphics, \
SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!cub3d.mlx.window)
		return (1);
	mlx_hook(cub3d.mlx.window, KeyPress, KeyPressMask, \
(void *)key_presser, &cub3d);
	mlx_hook(cub3d.mlx.window, KeyRelease, KeyReleaseMask, \
(void *)key_releaser, &cub3d);
	mlx_hook(cub3d.mlx.window, 17, 0, (void *)close_win, &cub3d);
	mlx_loop(cub3d.mlx.graphics);
	close_cub3d(&cub3d, 0);
	return (0);
}
