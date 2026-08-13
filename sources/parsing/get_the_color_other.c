/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_color_other.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:02:01 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/13 16:26:17 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	skip_spaces(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
}

char	*get_the_number(char *line, int *i)
{
	int		start;
	int		end;

	skip_spaces(line, i);
	start = *i;
	if (!ft_isdigit(line[start]))
		return (NULL);
	while (ft_isdigit(line[*i]))
		(*i)++;
	end = *i;
	return (ft_substr2(line, start, end));
}

int	between_0_255(t_color *couleur)
{
	return ((couleur->r >= 0 && couleur->r <= 255)
		&& (couleur->g >= 0 && couleur->g <= 255)
		&& (couleur->b >= 0 && couleur->b <= 255));
}

int	get_color(t_game *cub3d, char *line)
{
	t_color	color;
	int		i;
	char	flag;
	char	*number;

	if (!cub3d || !line)
		return (-1);
	i = 0;
	skip_spaces(line, &i);
	flag = line[i];
	if (flag != 'C' && flag != 'F')
		return (-1);
	i++;
	if (line[i] != ' ' && line[i] != '\t')
		return (-1);
	number = get_the_number(line, &i);
	if (!number)
		return (-1);
	color.r = ft_atoi(number);
	free(number);
	skip_spaces(line, &i);
	if (line[i] != ',')
		return (-1);
	i++;
	number = get_the_number(line, &i);
	if (!number)
		return (-1);
	color.g = ft_atoi(number);
	free(number);
	skip_spaces(line, &i);
	if (line[i] != ',')
		return (-1);
	i++;
	number = get_the_number(line, &i);
	if (!number)
		return (-1);
	color.b = ft_atoi(number);
	free(number);
	skip_spaces(line, &i);
	if (line[i] != '\n' && line[i] != '\0')
		return (-1);
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
