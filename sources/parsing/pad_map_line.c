/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_map_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:01:56 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/07 15:46:35 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*pad_map_line(char *line, int max_width)
{
	char	*new_line;
	int		i;
	int		len;

	if (!line || max_width <= 0)
		return (NULL);
	len = ft_strlen(line);
	new_line = malloc(sizeof(char) * (max_width + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < max_width)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[max_width] = '\0';
	i = 0;
	while (i < len && i < max_width)
	{
		new_line[i] = line[i];
		i++;
	}
	return (new_line);
}
