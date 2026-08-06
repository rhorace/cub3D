/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:40:48 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/27 14:09:30 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strendstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0 && big == NULL)
		return (NULL);
	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j) < len && big[i + j])
				j++;
			if (little[j] == '\0' && big[i + j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

int	get_x(t_game *g, int i)
{
	int		x;

	x = (i % g->map->largeur) * IMG_PIX;
	return (x);
}

int	get_y(t_game *g, int i)
{
	int		y;

	y = (i / g->map->largeur) * IMG_PIX;
	return (y);
}
