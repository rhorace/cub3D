/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:02:01 by rhorace           #+#    #+#             */
/*   Updated: 2026/07/20 10:11:51 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_path(t_game *cub3d, char *line)
{
	char	*chemin;
	int		i;
	char	flag[3];
	int		start;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!line[i] || !line[i + 1])
		return (-1);
	flag[0] = line[i];
	flag[1] = line[i + 1];
	flag[2] = '\0';
	if (ft_strcmp(flag, "NO") != 0 && ft_strcmp(flag, "SO") != 0
		&& ft_strcmp(flag, "WE") != 0 && ft_strcmp(flag, "EA") != 0)
		return (-1);
	i += 2;
	if (line[i] != ' ' && line[i] != '\t')
		return (-1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!line[i] || line[i] == '\n')
		return (-1);
	start = i;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		i++;
	chemin = ft_substr2(line, start, i);
	if (!chemin)
		return (-1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\0' && line[i] != '\n')
		return (free(chemin), -1);
	if (ft_strcmp(flag, "NO") == 0)
	{
		if (cub3d->map.no_path)
			return (free(chemin), -1);
		cub3d->map.no_path = chemin;
	}
	else if (ft_strcmp(flag, "SO") == 0)
	{
		if (cub3d->map.so_path)
			return (free(chemin), -1);
		cub3d->map.so_path = chemin;
	}
	else if (ft_strcmp(flag, "WE") == 0)
	{
		if (cub3d->map.we_path)
			return (free(chemin), -1);
		cub3d->map.we_path = chemin;
	}
	else if (ft_strcmp(flag, "EA") == 0)
	{
		if (cub3d->map.ea_path)
			return (free(chemin), -1);
		cub3d->map.ea_path = chemin;
	}
	return (1);
}
