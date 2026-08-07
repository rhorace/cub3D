/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:07:59 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/07 08:45:40 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(char **map)
{
	int	i;

	printf("%s--- start of the map ---%s\n", GREEN, YELLOW);
	if (!map)
	{
		printf("Map = NULL\n");
		printf("%s--- end of the map ---%s\n", RED, RESET);
		return ;
	}
	i = 0;
	while (map[i])
	{
		printf("%2d : %s\n", i, map[i]);
		i++;
	}
	printf("%s--- end of the map ---%s\n", RED, RESET);
}
