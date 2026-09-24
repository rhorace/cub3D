/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:34:08 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/15 19:32:24 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

static void	clear_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

static int	get_header(t_game *cub3d, char *line)
{
	if (!cub3d || !line)
		return (-1);
	if (is_texture_line(line))
	{
		if (get_texture_path(cub3d, line) == -1)
			return (-1);
	}
	else if (is_color_line(line))
	{
		if (get_color(cub3d, line) == -1)
			return (-1);
	}
	else if (!is_empty_line(line))
		return (-1);
	return (0);
}

static void	read_file_close(t_game *cub3d, char *line, int fd, char *msg)
{
	if (msg)
		send_message(msg, line);
	free (line);
	clear_gnl(fd);
	close (fd);
	free_map_list(cub3d->map_list);
	cub3d->map_list = NULL;
	close_cub3d(cub3d, 1);
}

static int	is_first_map_line(char *line)
{
	int	i;
	int	has_wall;

	i = 0;
	has_wall = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		if (line[i] == '1')
			has_wall = 1;
		i++;
	}
	return (has_wall);
}

void	manage_line(t_game *cub3d, char *line, int fd)
{
	static int	map_started;

	if (!map_started && is_first_map_line(line))
	{
		map_started = 1;
		if (!line_map_valid(line))
			read_file_close(cub3d, line, fd, "Invalid map line");
		add_map_line(&cub3d->map_list, line);
		if (ft_strlen(line) > cub3d->map.width)
			cub3d->map.width = ft_strlen(line);
	}
	else if (map_started)
	{
		if (!line_map_valid(line))
			read_file_close(cub3d, line, fd, "Invalid map line");
		add_map_line(&cub3d->map_list, line);
		if (ft_strlen(line) > cub3d->map.width)
			cub3d->map.width = ft_strlen(line);
	}
	else
	{
		if (get_header(cub3d, line) == -1)
			read_file_close(cub3d, line, fd, "header");
	}
}
