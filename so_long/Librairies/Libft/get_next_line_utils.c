/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:36:06 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/13 18:25:41 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trouve(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_join(char *stock, char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = ft_malloc_gnl(sizeof(char) * (ft_strlen(stock) \
		+ ft_strlen(buffer) + 1));
	if (temp == NULL)
		return (free(stock), free(buffer), stock = NULL, NULL);
	temp[ft_strlen(stock) + ft_strlen(buffer)] = '\0';
	while (stock[i])
	{
		temp[i] = stock[i];
		i++;
	}
	while (buffer[j])
	{
		temp[i] = buffer[j];
		i++;
		j++;
	}
	return (free(buffer), free(stock), stock = NULL, temp);
}

char	*ft_malloc_gnl(size_t size)
{
	char	*espace;
	size_t	i;

	i = 0;
	if (size == __SIZE_MAX__)
		return (NULL);
	espace = malloc(sizeof(char) * (size + 1));
	if (espace == NULL)
		return (NULL);
	while (i <= size)
	{
		espace[i] = '\0';
		i++;
	}
	return (espace);
}

int	ft_strchr_n(char *stock)
{
	int	i;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] == '\n')
		return (i + 1);
	else
		return (i);
}
