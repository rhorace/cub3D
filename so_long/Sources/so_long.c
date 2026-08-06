/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:14:53 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/28 19:59:07 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	check_oneonly(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '1')
			i++;
		else if (line[i] == '\n')
		{
			if (line[i + 1] == '\0')
				i++;
			else
				return (ft_printf_fd(2, "Error\nnot closed\n"), 0);
		}
		else
			return (ft_printf_fd(2, "Error\nnot closed\n"), 0);
	}
	return (i);
}

static int	fill_map(int fd, t_map *map)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf_fd(2, "Error\ngnl\n"), 0);
	if (check_oneonly(line) == 0)
		return (get_next_line(-1), free(line), 0);
	map->largeur = ft_strlen(line);
	temp = NULL;
	map->hauteur = 0;
	if (milieu_map(&line, &temp, map, fd) == 0)
		return (get_next_line(-1), 0);
	if (check_oneonly(temp + (map->largeur * (map->hauteur - 1))) == 0)
		return (free(line), free(temp), 0);
	if (map->collec == 0 || map->sortie != 1 || map->nbjoueur != 1)
		return (ft_printf_fd(2, "Error\ncollec, player or way out\n"), \
			free(line), free(temp), 0);
	return (map->map = temp, free(line), 1);
}

static t_map	*manage_map(char *str)
{
	int		fd;
	t_map	*map;

	if (ft_strendstr(str, ".ber", ft_strlen(str)) == NULL)
		return (ft_printf_fd(2, "Error\nnot .ber\n"), NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_printf_fd(2, "Error\nopening map\n"), NULL);
	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		return (close(fd), ft_printf_fd(2, "Error\nmalloc map\n"), NULL);
	ft_bzero(map, sizeof(t_map));
	if (!fill_map(fd, map))
		return (close(fd), free(map), NULL);
	if (map->largeur > LARGEUR_MAX / IMG_PIX \
		|| map->hauteur > HAUTEUR_MAX / IMG_PIX)
		return (close(fd), free(map->map), free(map), \
			ft_printf_fd(2, "Error\nmap too big\n"), NULL);
	if (finishable(map) == 0)
		return (close(fd), free(map->map), free(map), NULL);
	return (close(fd), map);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*g;

	if (argc != 2)
		return (0);
	map = manage_map(argv[1]);
	if (map == NULL)
		return (1);
	g = init_game(map);
	if (!g)
		return (ft_printf_fd(2, "Error\nalloc game\n"), \
		free(map->map), free(map), 0);
	so_so_long(g);
	return (free(map->map), free(map), free(g), 0);
}
