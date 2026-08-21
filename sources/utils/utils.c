/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:45:24 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/21 15:12:16 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ligne_max(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

void	ft_init(t_game *cub3d)
{
	ft_bzero(&cub3d->player, sizeof(t_player));
	// cub3d->map.ea_path = NULL;
	// cub3d->map.no_path = NULL;
	// cub3d->map.so_path = NULL;
	// cub3d->map.we_path = NULL;
	// cub3d->map.grid = NULL;
	ft_bzero(&cub3d->map, sizeof(t_map));
	cub3d->map_list = NULL;
	// cub3d->mlx.graphics = NULL;
	// cub3d->mlx.window = NULL;
	ft_bzero(&cub3d->map_list, sizeof(t_mlx));
	ft_bzero(&cub3d->tex, sizeof(t_texture));
	cub3d->ceiling.r = -1;
	cub3d->ceiling.g = -1;
	cub3d->ceiling.b = -1;
	cub3d->floor.r = -1;
	cub3d->floor.g = -1;
	cub3d->floor.b = -1;
}

void	send_message(char *msg, char *arg)
{
	if (arg)
		printf("%sError\n%s%s: %s%s\n", RED, YELLOW, msg, arg, RESET);
	else
		printf("%sError\n%s%s%s\n", RED, YELLOW, msg, RESET);
}

void	remove_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}
