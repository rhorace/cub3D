/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _solution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 09:50:23 by rhorace           #+#    #+#             */
/*   Updated: 2026/07/15 09:50:26 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	path_already_exists(t_game *cub3d, char *flag)
{
	if (ft_strcmp(flag, "NO") == 0 && cub3d->map.no_path)
		return (1);
	if (ft_strcmp(flag, "SO") == 0 && cub3d->map.so_path)
		return (1);
	if (ft_strcmp(flag, "WE") == 0 && cub3d->map.we_path)
		return (1);
	if (ft_strcmp(flag, "EA") == 0 && cub3d->map.ea_path)
		return (1);
	return (0);
}

int	get_path(t_game *cub3d, char *map)
{
	char	*chemin;
	char	flag[3];
	int		i;
	int		start;
	int		end;

	if (!cub3d || !map)
		return (-1);
	i = 0;
	while (map[i] == ' ' || map[i] == '\t')
		i++;
	if (!map[i] || !map[i + 1])
		return (-1);
	flag[0] = map[i];
	flag[1] = map[i + 1];
	flag[2] = '\0';
	if (ft_strcmp(flag, "NO") != 0
		&& ft_strcmp(flag, "SO") != 0
		&& ft_strcmp(flag, "WE") != 0
		&& ft_strcmp(flag, "EA") != 0)
		return (-1);
	if (path_already_exists(cub3d, flag))
		return (-1);
	i += 2;
	if (map[i] != ' ' && map[i] != '\t')
		return (-1);
	while (map[i] == ' ' || map[i] == '\t')
		i++;
	if (!map[i] || map[i] == '\n')
		return (-1);
	start = i;
	while (map[i]
		&& map[i] != ' '
		&& map[i] != '\t'
		&& map[i] != '\n')
		i++;
	end = i;
	chemin = ft_substr2(map, start, end);
	if (!chemin)
		return (-1);
	while (map[i] == ' ' || map[i] == '\t')
		i++;
	if (map[i] != '\0' && map[i] != '\n')
	{
		free(chemin);
		return (-1);
	}
	if (ft_strcmp(flag, "NO") == 0)
		cub3d->map.no_path = chemin;
	else if (ft_strcmp(flag, "SO") == 0)
		cub3d->map.so_path = chemin;
	else if (ft_strcmp(flag, "WE") == 0)
		cub3d->map.we_path = chemin;
	else if (ft_strcmp(flag, "EA") == 0)
		cub3d->map.ea_path = chemin;
	return (1);
}
