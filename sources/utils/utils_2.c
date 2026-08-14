/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:45:24 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/14 13:33:22 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_texture_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if ((line[i] == 'N' && line[i + 1] == 'O')
		|| (line[i] == 'S' && line[i + 1] == 'O')
		|| (line[i] == 'W' && line[i + 1] == 'E')
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
