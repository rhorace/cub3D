/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:12:32 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/28 19:57:50 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fill_assets(char *line, int i, t_map *map)
{
	size_t	emplacement;

	emplacement = i + (map->largeur * (map->hauteur + 1));
	if (line[0] == 'C')
		return (map->collec++, 1);
	else if (line[0] == 'E')
		return (map->sortie++, 1);
	else if (line[0] == 'P' && map->nbjoueur > 0)
		return (ft_printf_fd(2, "Error\ntoo many players\n"), 0);
	else if (line[0] == 'P')
		return (map->ijoueur = emplacement, map->nbjoueur = 1, 1);
	else
	{
		if (! (line[0] == '0' || line[0] == '1' || \
			(line[0] == '\n' && line[1] == '\0')))
			return (ft_printf_fd(2, "Error\nincorrect map\n"), 0);
		return (1);
	}
}

size_t	count_assets(char *line, t_map *map)
{
	size_t	count;
	int		i;

	i = 0;
	if (line[i] == '\0')
		return (map->largeur);
	if (line[i] != '1')
		return (ft_printf_fd(2, "Error\nmap not closed\n"), 0);
	i++;
	count = 1;
	while (line[i])
	{
		if (!fill_assets(line + i, i, map))
			return (0);
		count++;
		i++;
	}
	i = i - 2;
	if (line[i] != '1')
		return (ft_printf_fd(2, "Error\nmap not closed\n"), 0);
	if (count != map->largeur)
		return (ft_printf_fd(2, "Error\nmap not rectangle\n"), 0);
	return (map->temp_collec = map->collec, count);
}

static int	flood_fill(t_map *map, int i)
{
	if (i < 0 || i > (int)((map->largeur * map->hauteur) - 1) \
		|| map->map[i] == '1' || map->map[i] == 'o' || map->map[i] == 'e' \
		|| map->map[i] == 'c' || (map->map[i] == 'P' && map->flagp == 1))
		return (1);
	else if (map->map[i] == 'P')
		map->flagp = 1;
	else if (map->map[i] == 'C')
	{
		map->map[i] = 'c';
		map->temp_collec--;
	}
	else if (map->map[i] == '0')
		map->map[i] = 'o';
	else if (map->map[i] == 'E')
		map->map[i] = 'e';
	flood_fill(map, i - 1);
	flood_fill(map, i + 1);
	flood_fill(map, i - map->largeur);
	flood_fill(map, i + map->largeur);
	if (map->temp_collec > 0)
		return (0);
	return (1);
}

static int	goto_exit(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i] == 'e')
			return (1);
		i++;
	}
	return (0);
}

int	finishable(t_map *map)
{
	if (flood_fill(map, map->ijoueur) == 0)
		return (ft_printf_fd(2, "Error\nuncollectible\n"), 0);
	if (goto_exit(map) == 0)
		return (ft_printf_fd(2, "Error\nunreachable exit\n"), 0);
	return (1);
}
