/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _solution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 09:49:58 by rhorace           #+#    #+#             */
/*   Updated: 2026/07/15 09:50:05 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_empty_line(char *line)
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

static int	is_texture_line(char *line)
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

static int	is_color_line(char *line)
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

static int	parse_header_line(t_game *cub3d, char *line)
{
	if (is_texture_line(line))
		return (get_path(cub3d, line));
	if (is_color_line(line))
		return (get_color(cub3d, line));
	return (0);
}

static int	read_map_error(t_game *cub3d, int fd, char *line)
{
	free(line);
	close(fd);
	close_cub3d(cub3d, 1);
	return (0);
}

int	read_map(t_game *cub3d, char *path)
{
	char	*line;
	int		fd;
	int		map_started;
	int		result;

	if (!cub3d || !path)
		return (0);
	cub3d->map_list = NULL;
	map_started = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("%sError\n%sCannot open map: %s%s\n",
			RED, YELLOW, path, RESET);
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (!map_started)
		{
			result = parse_header_line(cub3d, line);
			if (result == -1)
				return (read_map_error(cub3d, fd, line));
			if (result == 0 && !is_empty_line(line))
				map_started = 1;
		}
		if (map_started)
		{
			if (!add_map_line(&cub3d->map_list, line))
				return (read_map_error(cub3d, fd, line));
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	cub3d->map.height = map_list_size(cub3d->map_list);
	cub3d->map.grid = map_list_to_array(cub3d->map_list);
	free_map_list(cub3d->map_list);
	cub3d->map_list = NULL;
	if (!cub3d->map.grid)
		return (0);
	cub3d->map.width = ligne_max(cub3d->map.grid);
	return (1);
}
