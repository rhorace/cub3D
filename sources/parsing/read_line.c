/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:29:00 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/07 15:52:13 by rhorace          ###   ########.fr       */
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
		if (get_path(cub3d, line) == -1)
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
	return (0);
}

static void	read_line_close(t_game *cub3d, char *line, int fd)
{
	send_message("Pb avec cette ligne: ", line);
	free (line);
	clear_gnl(fd);
	close (fd);
	close_cub3d(cub3d, 1);
}

void	remove_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	read_line(t_game *cub3d, char *path)
{
	int		fd;
	char	*line;
	int		in_map;

	if (!cub3d || !path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (send_message("Cannot open map", path), 0);
	in_map = 0;
	cub3d->map.width = 0;
	line = get_next_line(fd);
	while (line)
	{
		remove_newline(line);
		if (path_ready(&cub3d->map) && color_ready(&cub3d->ceiling, \
&cub3d->floor))
		{
			if (is_texture_line(line))
				read_line_close(cub3d, line, fd);
			if (is_color_line(line))
				read_line_close(cub3d, line, fd);
			if (!is_empty_line(line))
				in_map = 1;
			if (get_map(cub3d, line, in_map) == -1)
				read_line_close(cub3d, line, fd);
		}
		else
		{
			if (get_header(cub3d, line) == -1)
				read_line_close(cub3d, line, fd);
		}
		if (ft_strlen(line) > cub3d->map.width)
			cub3d->map.width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	cub3d->map.grid = map_list_to_array(cub3d->map_list, cub3d->map.width);
	//cub3d->map.width = ligne_max(cub3d->map.grid);
	cub3d->map.height = map_list_size(cub3d->map_list);
	free_map_list(cub3d->map_list);
	cub3d->map_list = NULL;
	/*if (!path_ready(&cub3d->map) || !color_ready(&cub3d->ceiling, \
&cub3d->floor) || (cub3d->map.height < 3))
		close_cub3d(cub3d, 1);*/
	the_verificator(cub3d);
	return (1);
}
