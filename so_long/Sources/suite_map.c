/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:36:34 by sohollar          #+#    #+#             */
/*   Updated: 2026/07/16 08:35:19 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	/*int		i;
	int		j;*/
	char	*str;

	/*i = 0;
	j = 0;*/
	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) +1, sizeof(char));
	if (str == NULL)
		return (free(s1), NULL);
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (s1 == NULL)
		return (ft_memmove(str, s2, ft_strlen(s2)));
	else if (s2 == NULL)
	{
		ft_memmove(str, s1, ft_strlen(s1));
		return (free(s1), str);
	}
	else
	{
		ft_memmove(str, s1, ft_strlen(s1));
		ft_memmove((str + ft_strlen(s1)), s2, ft_strlen(s2));
	}
	return (free(s1), str);
}

int	milieu_map(char **line, char **temp, t_map *map, int fd)
{
	while (*line[0] != '\0')
	{
		*temp = ft_strjoin_free(*temp, *line);
		free(*line);
		if (*temp == NULL)
			return (ft_printf_fd(2, "Error\nmalloc join\n"), 0);
		*line = get_next_line(fd);
		if (*line == NULL)
			return (free(*temp), ft_printf_fd(2, "Error\ngnl\n"), 0);
		if (count_assets(*line, map) != map->largeur)
			return (free(*temp), free(*line), 0);
		map->hauteur++;
	}
	return (1);
}
