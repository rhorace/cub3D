/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:02:01 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/06 09:36:49 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map_node	*new_map_node(char *line)
{
	t_map_node	*new;

	new = malloc(sizeof(t_map_node));
	if (!new)
		return (NULL);
	new->line = ft_strdup(line);
	if (!new->line)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void	add_map_line(t_map_node **map_list, char *line)
{
	t_map_node	*new;
	t_map_node	*tmp;

	new = new_map_node(line);
	if (!new)
		return ;
	if (!*map_list)
	{
		*map_list = new;
		return ;
	}
	tmp = *map_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	map_list_size(t_map_node *map_list)
{
	int	count;

	count = 0;
	while (map_list)
	{
		count++;
		map_list = map_list->next;
	}
	return (count);
}

char	**map_list_to_array(t_map_node *map_list, int max_width)
{
	char	**map;
	int		size;
	int		i;

	size = map_list_size(map_list);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (map_list)
	{
		map[i] = pad_map_line(map_list->line, max_width);
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		i++;
		map_list = map_list->next;
	}
	map[i] = NULL;
	return (map);
}

void	free_map_list(t_map_node *map_list)
{
	t_map_node	*tmp;

	while (map_list)
	{
		tmp = map_list->next;
		free(map_list->line);
		free(map_list);
		map_list = tmp;
	}
}
