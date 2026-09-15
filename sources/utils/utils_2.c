/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:45:24 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/15 11:13:53 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3D.h"

int	is_door_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'D' && line[i + 1] == 'O'))
	{
		if (line[i + 2] == ' ' || line[i + 2] == '\t')
			return (1);
	}
	return (0);
}

int	is_texture_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'N' && line[i + 1] == 'O')
		|| (line[i] == 'S' && line[i + 1] == 'O')
		|| (line[i] == 'W' && line[i + 1] == 'E')
		|| (line[i] == 'D' && line[i + 1] == 'O')
		|| (line[i] == 'E' && line[i + 1] == 'A'))
	{
		if (line[i + 2] == ' ' || line[i + 2] == '\t')
			return (1);
	}
	return (0);
}

int	is_color_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'F' || line[i] == 'C')
		&& (line[i + 1] == ' ' || line[i + 1] == '\t'))
		return (1);
	return (0);
}

int	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

int	line_map_valid(char *line, char *do_path)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'D' && do_path == NULL)
			return (0);
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != 'D')
			return (0);
		i++;
	}
	return (1);
}
