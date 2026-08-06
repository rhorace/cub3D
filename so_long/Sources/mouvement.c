/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:42:34 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/28 19:52:41 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_game *g, int move, int k)
{
	int	i;
	int	len;
	int	a;

	len = g->map->largeur * g->map->hauteur;
	i = 0;
	while (g->map->map[i])
	{
		if (g->map->map[i] == 'V')
			return (0);
		if (g->map->map[i] == 'P' || g->map->map[i] == 'z')
			break ;
		i++;
	}
	a = i + move;
	if ((k == KEY_UP && a >= 0 && g->map->map[a] != '1') \
		|| (k == KEY_DOWN && a < len && g->map->map[a] != '1') \
		|| (k == KEY_LEFT && a >= 0 && g->map->map[a] != '1') \
		|| (k == KEY_RIGHT && a < len && g->map->map[a] != '1'))
		return (i);
	return (0);
}

static void	swap_tiles(t_game *g, int from, int dest, void *img_from)
{
	if (g->map->map[dest] == 'e' && g->map->collec > 0)
	{
		mlx_put_image_to_window(g->mlx, g->win, img_from, \
		get_x(g, from), get_y(g, from));
		mlx_put_image_to_window(g->mlx, g->win, g->set->visite, \
		get_x(g, dest), get_y(g, dest));
	}
	else if (g->map->map[dest] == 'e' && g->map->collec == 0)
	{
		mlx_put_image_to_window(g->mlx, g->win, img_from, \
		get_x(g, from), get_y(g, from));
		mlx_put_image_to_window(g->mlx, g->win, g->set->joueur_out, \
		get_x(g, dest), get_y(g, dest));
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, img_from, \
		get_x(g, from), get_y(g, from));
		mlx_put_image_to_window(g->mlx, g->win, g->set->joueur, \
		get_x(g, dest), get_y(g, dest));
	}
}

static void	swap_pos(t_game *g, int i, int move)
{
	if (g->map->map[i] == 'z')
	{
		swap_tiles(g, i, i + move, g->set->sortie);
		g->map->map[i] = 'e';
	}
	else
	{
		swap_tiles(g, i, i + move, g->set->chemin);
		g->map->map[i] = 'o';
	}
	if (g->map->map[i + move] == 'c')
		g->map->collec--;
	if (g->map->map[i + move] == 'e' && g->map->collec > 0)
		g->map->map[i + move] = 'z';
	else if (g->map->map[i + move] == 'e' && g->map->collec == 0)
		g->map->map[i + move] = 'V';
	else
		g->map->map[i + move] = 'P';
}

void	bouger(t_game *g, int move, int keycode)
{
	static int	count;
	int			i;

	i = can_move(g, move, keycode);
	if (!i)
		return ;
	count++;
	ft_printf_fd(1, "number of moves : %d\n", count);
	swap_pos(g, i, move);
}
