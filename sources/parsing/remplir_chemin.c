/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplir_chemin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 21:17:09 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/29 21:18:29 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	remplir_chemin1(t_game *cub3d, char *chemin, char *flag)
{
	if (ft_strcmp(flag, "NO") == 0)
	{
		if (cub3d->map.no_path)
			return (0);
		cub3d->map.no_path = chemin;
	}
	else if (ft_strcmp(flag, "SO") == 0)
	{
		if (cub3d->map.so_path)
			return (0);
		cub3d->map.so_path = chemin;
	}
	else if (ft_strcmp(flag, "WE") == 0)
	{
		if (cub3d->map.we_path)
			return (0);
		cub3d->map.we_path = chemin;
	}
	else if (ft_strcmp(flag, "EA") == 0)
	{
		if (cub3d->map.ea_path)
			return (0);
		cub3d->map.ea_path = chemin;
	}
	return (1);
}

static int	remplir_chemin2(t_game *cub3d, char *chemin, char *flag)
{
	if (ft_strcmp(flag, "DO") == 0)
	{
		if (cub3d->map.do_path)
			return (0);
		cub3d->map.do_path = chemin;
	}
	else if (ft_strcmp(flag, "OD") == 0)
	{
		if (cub3d->map.od_path)
			return (0);
		cub3d->map.od_path = chemin;
	}
	return (1);
}

static int	remplir_chemin3(t_game *cub3d, char *chemin, char *flag)
{
	int	k;

	if (!ft_isdigit(flag[0]))
		return (1);
	k = ft_atoi(flag);
	if (!(k >= 1 && k <= ANIM_FRAME_NUMBER))
		return (0);
	if (cub3d->map.anim_path[k - 1][0] != '\0')
		return (0);
	ft_memmove2(chemin, cub3d->map.anim_path[k - 1], ft_strlen(chemin));
	free(chemin);
	return (1);
}

int	remplir_chemin(t_game *cub3d, char *chemin, char *flag)
{
	if (!remplir_chemin1(cub3d, chemin, flag))
		return (0);
	if (!remplir_chemin2(cub3d, chemin, flag))
		return (0);
	if (!remplir_chemin3(cub3d, chemin, flag))
		return (0);
	return (1);
}
