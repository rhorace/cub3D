/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:29:00 by rhorace           #+#    #+#             */
/*   Updated: 2026/09/15 19:25:01 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

int	bad_file(t_game *cub3d, char *path)
{
	int		fd;
	char	*line;

	if (!cub3d || !path)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (send_message("Cannot open file", path), 1);
	line = get_next_line(fd);
	while (line)
	{
		remove_newline(line);
		manage_line(cub3d, line, fd);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	cub3d->map.grid = map_list_to_grid(cub3d->map_list, cub3d->map.width);
	cub3d->map.height = map_list_size(cub3d->map_list);
	free_map_list(cub3d->map_list);
	cub3d->map_list = NULL;
	return (0);
}
