/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 09:12:42 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/07 09:14:01 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_extension(char *path, char *extension)
{
	int	len_path;
	int	len_extension;

	len_path = ft_strlen(path);
	len_extension = ft_strlen(extension);
	if (!len_path || !len_extension || len_path < 5)
		return (0);
	return (path[len_path - 4] == extension[0]
		&& path[len_path - 3] == extension[1]
		&& path[len_path - 2] == extension[2]
		&& path[len_path - 1] == extension[3]);

}
