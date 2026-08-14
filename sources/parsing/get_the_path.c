/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:02:01 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/14 17:16:27 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	remplir_chemin(t_game *cub3d, char *chemin, char *flag)
{
	if (ft_strcmp(flag, "NO") == 0)
	{
		if (cub3d->map.no_path)
			return (0);
		cub3d->map.no_path = chemin;
	}
	else if (ft_strcmp(flag, "SO") == 0)
	{
		if (cub3d->map.so_path)
			return (0);
		cub3d->map.so_path = chemin;
	}
	else if (ft_strcmp(flag, "WE") == 0)
	{
		if (cub3d->map.we_path)
			return (0);
		cub3d->map.we_path = chemin;
	}
	else if (ft_strcmp(flag, "EA") == 0)
	{
		if (cub3d->map.ea_path)
			return (0);
		cub3d->map.ea_path = chemin;
	}
	return (1);
}

static char	*get_xpm(char *line, int *i)
{
	int	start;

	(*i) += 2;
	if (line[*i] != ' ' && line[*i] != '\t')
		return (NULL);
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	if (!line[*i] || line[*i] == '\n')
		return (NULL);
	start = *i;
	while (line[*i] && line[*i] != ' ' && line[*i] != '\t' && line[*i] != '\n')
		(*i)++;
	return (ft_substr2(line, start, *i));
}

int	get_path(t_game *cub3d, char *line)
{
	char	*chemin;
	int		i;
	char	flag[3];

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
	chemin = get_xpm(line, &i);
	if (!chemin)
		return (-1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\0' && line[i] != '\n')
		return (free(chemin), -1);
	if (!remplir_chemin(cub3d, chemin, flag))
		return (free(chemin), -1);
	return (1);
}
