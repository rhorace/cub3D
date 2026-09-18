/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anticipate_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:20:24 by sohollar          #+#    #+#             */
/*   Updated: 2026/09/18 19:14:27 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mattress_under(float x)
{
	if (x - partie_entiere(x) < 0.3)
		return (1);
	return (0);
}

int	ceiling_above(float x)
{
	if (partie_entiere(x) + 1 - x < 0.3)
		return (1);
	return (0);
}
