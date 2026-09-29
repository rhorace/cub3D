/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:18:20 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/28 22:04:43 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_colors(t_game *cub3d)
{
	cub3d->floor.r = -1;
	cub3d->floor.g = -1;
	cub3d->floor.b = -1;
	cub3d->ceiling.r = -1;
	cub3d->ceiling.g = -1;
	cub3d->ceiling.b = -1;
}

int	init_anim(t_game *cub)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (ANIM_FRAME_NUMBER + 1));
	if (tab == NULL)
		return (0);
	tab[ANIM_FRAME_NUMBER] = NULL;
	while (i < ANIM_FRAME_NUMBER)
	{
		tab[i] = ft_calloc(sizeof(char), PATH_MAX_SIZE + 1);
		if (tab[i] == NULL)
			return (free_tab(tab), 0);
		i++;
	}
	cub->map.anim_path = tab;
	return (1);
}

t_game	*init_cub3d(void)
{
	t_game	*cub3d;

	cub3d = ft_calloc(1, sizeof(t_game));
	if (!cub3d)
		return (NULL);
	if (!init_anim(cub3d))
		return (NULL);
	init_colors(cub3d);
	return (cub3d);
}
