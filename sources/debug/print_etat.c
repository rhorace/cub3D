/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_etat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:07:59 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/14 13:11:23 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_etat(t_game cub3d)
{
	printf("%s--- start of the header ---%s\n", GREEN, YELLOW);
	printf("floor         : %d,%d,%d\n", cub3d.floor.r, cub3d.floor.g, \
cub3d.floor.b);
	printf("ceiling       : %d,%d,%d\n", cub3d.ceiling.r, cub3d.ceiling.g, \
cub3d.ceiling.b);
	printf("t_map width   : %d\n", cub3d.map.width);
	printf("t_map height  : %d\n", cub3d.map.height);
	printf("t_map no_path : %s\n", cub3d.map.no_path);
	printf("t_map so_path : %s\n", cub3d.map.so_path);
	printf("t_map we_path : %s\n", cub3d.map.we_path);
	printf("t_map ea_path : %s\n", cub3d.map.ea_path);
	printf("path_ready: %d\n", texture_ready(&cub3d.map));
	printf("color_ready: %d\n", color_ready(&cub3d.ceiling, &cub3d.floor));
	printf("%s--- end of the header ---%s\n", RED, RESET);
}
