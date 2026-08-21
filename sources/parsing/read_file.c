/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:29:00 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/21 15:22:42 by sohollar         ###   ########.fr       */
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
	// if (!cub3d || !line)
	// 	return (-1);
	if (is_texture_line(line))
	{
		if (get_texture_path(cub3d, line) == -1)
		{
			send_message("Le probleme concerne les textures", line);
			return (-1);
		}
	}
	else if (is_color_line(line))
	{
		if (get_color(cub3d, line) == -1)
		{
			send_message("Le probleme concerne les couleurs", line);
			return (-1);
		}
	}
	else if (!is_empty_line(line))
	{
		send_message("Le probleme concerne cette ligne", line);
		return (-1);
	}
	return (0);
}

static void	read_file_close(t_game *cub3d, char *line, int fd)
{
	free (line);
	clear_gnl(fd);
	close (fd);
	free_map_list(cub3d->map_list);
	cub3d->map_list = NULL;
	close_cub3d(cub3d, 1);
}

void	manage_line(t_game *cub3d, char *line, int fd)
{
	static int	in_map;

	if (texture_ready(&cub3d->map) && color_ready(&cub3d->ceiling, \
&cub3d->floor))
	{
		if (is_texture_line(line))
			read_file_close(cub3d, line, fd);
		if (is_color_line(line))
			read_file_close(cub3d, line, fd);
		if (!is_empty_line(line))
			in_map = 1;
		if (in_map)
			add_map_line(&cub3d->map_list, line);
		if (ft_strlen(line) > cub3d->map.width)
			cub3d->map.width = ft_strlen(line);
	}
	else
	{
		if (get_header(cub3d, line) == -1)
			read_file_close(cub3d, line, fd);
	}
}

int	read_file(t_game *cub3d, char *path)
{
	int		fd;
	char	*line;

	//if (!cub3d || !path)
	//	return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (send_message("Cannot open file", path), 0);
//	cub3d->map.width = 0;
	line = get_next_line(fd);
	while (line)
	{
		remove_newline(line);
		manage_line(cub3d, line, fd);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	cub3d->map.grid = map_list_to_array(cub3d->map_list, cub3d->map.width);
	cub3d->map.height = map_list_size(cub3d->map_list);
	free_map_list(cub3d->map_list);
	cub3d->map_list = NULL;
	return (1);
}
