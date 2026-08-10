/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 09:49:38 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/10 08:50:17 by rhorace          ###   ########.fr       */
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

/*int	init_mlx(t_game *cub3d)
{
	cub3d->mlx.graphics = mlx_init();
	if (!cub3d->mlx.graphics)
		return (0);
	cub3d->mlx.window = mlx_new_window(
			cub3d->mlx.graphics,
			WIN_WIDTH,
			WIN_HEIGHT,
			"cub3D");
	if (!cub3d->mlx.window)
		return (0);
	cub3d->mlx.image = mlx_new_image(
			cub3d->mlx.graphics,
			WIN_WIDTH,
			WIN_HEIGHT);
	if (!cub3d->mlx.image)
		return (0);
	cub3d->mlx.image_add = mlx_get_data_addr(
			cub3d->mlx.image,
			&cub3d->mlx.bits_per_pixel,
			&cub3d->mlx.line_length,
			&cub3d->mlx.endian);
	if (!cub3d->mlx.image_add)
		return (0);
	return (1);
}*/

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
	if (!read_line(&cub3d, argv[1]))
		return (close_cub3d(&cub3d, 1), 1);
	printf("read_line: OK\n");
	if (!the_verificator(&cub3d))
		return (close_cub3d(&cub3d, 1), 1);
	printf("the_verificator: OK\n");
	if (!init_mlx(&cub3d))
		return (close_cub3d(&cub3d, 1), 1);
	printf("init_mlx: OK\n");
	if (!load_textures(&cub3d))
		return (close_cub3d(&cub3d, 1), 1);
	printf("load_textures: OK\n");
	init_player(&cub3d);
	render_frame(&cub3d);
	init_hooks(&cub3d);
	mlx_loop_hook(cub3d.mlx.graphics, (void *)game_loop, &cub3d);
	mlx_loop(cub3d.mlx.graphics);
	return (0);
}

/*#include "cub3D.h"

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

	if (argc != 2)
		return (usage(), 1);
	ft_bzero(&cub3d, sizeof(t_game));
	ft_init(&cub3d);
	if (!check_extension(argv[1], ".cub"))
		return (send_message("Invalid file name", argv[1]), 1);
	print_etat(cub3d);
	print_map(cub3d.map.grid);
	if (!read_line(&cub3d, argv[1]))
		close_cub3d(&cub3d, 1);
	if (!the_verificator(&cub3d))
		close_cub3d(&cub3d, 1);
	print_etat(cub3d);
	print_map(cub3d.map.grid);
	//cub3d.mlx.graphics = mlx_init();
	if (!init_mlx(&cub3d))
		close_cub3d(&cub3d, 1);
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

int	main(int argc, char **argv)
{
	t_game	cub3d;

	ft_bzero(&cub3d, sizeof(t_game));
	if (argc != 2)
		return (1);
	if (!read_line(&cub3d, argv[1]))
		close_cub3d(&cub3d, 1);
	if (!the_verificator(&cub3d))
		close_cub3d(&cub3d, 1);
	if (!init_mlx(&cub3d))
		close_cub3d(&cub3d, 1);
	if (!load_textures(&cub3d))
		close_cub3d(&cub3d, 1);
	render_frame(&cub3d);
	mlx_loop(cub3d.mlx.graphics);
	return (0);
}*/
