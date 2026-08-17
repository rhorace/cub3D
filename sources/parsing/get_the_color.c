/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:02:01 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/17 13:46:50 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	between_0_255(t_color *couleur)
{
	return ((couleur->r >= 0 && couleur->r <= 255)
		&& (couleur->g >= 0 && couleur->g <= 255)
		&& (couleur->b >= 0 && couleur->b <= 255));
}

static int	which_part(t_game *cub3d, t_color color, char flag)
{
	if (!between_0_255(&color))
		return (-1);
	if (flag == 'F')
	{
		if (floor_ready(&cub3d->floor))
			return (-1);
		cub3d->floor = color;
	}
	else if (flag == 'C')
	{
		if (ceiling_ready(&cub3d->ceiling))
			return (-1);
		cub3d->ceiling = color;
	}
	return (1);
}

static int	get_number(char *line, int *i)
{
	int		start;
	int		n;
	char	*number;

	start = *i;
	if (!ft_isdigit(line[start]))
		return (-1);
	while (ft_isdigit(line[*i]))
		(*i)++;
	number = ft_substr2(line, start, *i);
	if (!number)
		return (-1);
	n = ft_atoi(number);
	free (number);
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	return (n);
}

int	get_rgb(t_game *cub3d, char *line, int *i, char flag)
{
	t_color	color;

	color.r = get_number(line, i);
	if (line[*i] != ',')
		return (-1);
	(*i)++;
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	color.g = get_number(line, i);
	if (line[*i] != ',')
		return (-1);
	(*i)++;
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	color.b = get_number(line, i);
	if (line[*i] != '\n' && line[*i] != '\0')
		return (-1);
	if (which_part(cub3d, color, flag) == -1)
		return (-1);
	return (1);
}

int	get_color(t_game *cub3d, char *line)
{
	int		i;
	char	flag;

	if (!cub3d || !line)
		return (-1);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	flag = line[i];
	if (flag != 'C' && flag != 'F')
		return (-1);
	i++;
	if (line[i] != ' ' && line[i] != '\t')
		return (-1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!line[i] || line[i] == '\n')
		return (-1);
	if (get_rgb(cub3d, line, &i, flag) == -1)
		return (-1);
	return (1);
}
