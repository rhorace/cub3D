/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mur.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:11:56 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/14 20:35:30 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* le vecteur impact = current - player.pos */
int	hauteur_mur(t_game *cub, t_vector current)
{
	int			h;
	t_vector	impact;

	impact.x = current.x - cub->player.pos.x;
	impact.y = current.y - cub->player.pos.y;
	h = WIN_HEIGHT / (2 * (((float)impact.x * (float)cub->player.dir.x)
				+ ((float)impact.y * (float)cub->player.dir.y)) * tan(FOV / 2));
	return (h);
}

/*int	get_col(t_vector impact)
{
	float	k;
	int		arrondi;

	k = (impact.x - partie_entiere(impact.x)) * BLOCK;
	if (k - partie_entiere(k) < 0.5)
		arrondi = 0;
	else
		arrondi = 1;
	return (partie_entiere(k) + arrondi);
}*/

int    get_col(t_vector impact, t_texture tex)
{
    float    k;
    int        arrondi;

    if (impact.x - partie_entiere(impact.x) != 0)
    {
        if (tex.id == TEX_NO)
            k = (impact.x - partie_entiere(impact.x)) * BLOCK;
        else
            k = (1 - (impact.x - partie_entiere(impact.x))) * BLOCK;
    }
    else
    {
        if (tex.id == TEX_EA)
            k = (impact.y - partie_entiere(impact.y)) * BLOCK;
        else
            k = (1 - (impact.y - partie_entiere(impact.y))) * BLOCK;
    }
    if (k - partie_entiere(k) < 0.5 || k > BLOCK - 1)
        arrondi = 0;
    else
        arrondi = 1;
    return (partie_entiere(k) + arrondi);
}

/*int	get_brique(int brique, int h)
{
	float	j;
	int		arrondi;

	j = (BLOCK * brique) / h;
	if (j - partie_entiere(j) < 0.5)
		arrondi = 0;
	else
		arrondi = 1;
	return (partie_entiere(j) + arrondi);
}*/
int    get_brique(int brique, int h)
{
    float    j;
    int        arrondi;

    j = (BLOCK * brique) / h;
    if (j - partie_entiere(j) < 0.5 || j > BLOCK - 1)
        arrondi = 0;
    else
        arrondi = 1;
    return (partie_entiere(j) + arrondi);
}
