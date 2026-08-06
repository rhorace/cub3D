/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:09:26 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/27 16:34:53 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bzero_gnl(char *str, int min, int max)
{
	int	i;

	i = min;
	while (i < max)
	{
		str[i] = '\0';
		i++;
	}
}

static char	*lire(int fd, char *stock)
{
	int		ret_read;
	char	*buffer;
	int		flag;

	flag = 0;
	ret_read = -1;
	while (ret_read != 0 && flag == 0)
	{
		buffer = ft_malloc_gnl(BUFFER_SIZE);
		if (buffer == NULL)
			return (free(stock), stock = NULL, NULL);
		ret_read = read(fd, buffer, BUFFER_SIZE);
		if (ret_read == -1)
			return (free(stock), stock = NULL, free(buffer), NULL);
		if (ret_read < BUFFER_SIZE)
			ft_bzero_gnl(buffer, ret_read, BUFFER_SIZE);
		flag = trouve(buffer);
		stock = ft_join(stock, buffer);
		if (stock == NULL)
			return (NULL);
	}
	return (stock);
}

static char	*extr(char *stock)
{
	char	*ligne;
	int		i;

	if (stock == NULL)
		return (NULL);
	i = 0;
	ligne = ft_malloc_gnl(ft_strchr_n(stock));
	if (ligne == NULL)
		return (NULL);
	while (stock[i] != '\n' && stock[i])
	{
		ligne[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
		ligne[i] = stock[i];
	return (ligne);
}

static char	*trop(char *stock)
{
	int		i;
	int		j;
	char	*temp;

	i = ft_strchr_n(stock);
	j = 0;
	temp = ft_malloc_gnl(ft_strlen(stock) - ft_strchr_n(stock));
	if (temp == NULL)
		return (free(stock), stock = NULL, NULL);
	while (stock[i])
	{
		temp[j] = stock[i];
		i++;
		j++;
	}
	return (free(stock), stock = NULL, temp);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*ligne;

	if (stock == NULL)
	{
		stock = ft_malloc_gnl(0);
		if (stock == NULL)
			return (NULL);
	}
	stock = lire(fd, stock);
	if (stock == NULL)
		return (NULL);
	ligne = extr(stock);
	if (ligne == NULL)
		return (free(stock), stock = NULL, NULL);
	if (ligne[0] == '\0')
		return (free(stock), stock = NULL, ligne);
	stock = trop(stock);
	if (stock == NULL)
		return (free(ligne), NULL);
	return (ligne);
}

/*int	main(void)
{
	int		fd;
	char	*l;

	fd = open("../Textes/Empty.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	l = get_next_line(fd);
	if (l == NULL)
		return (0);
	while (l != NULL)
	{
		l = get_next_line(fd);
		if (l == NULL)
			return (0);
		printf("%s", l);
	}
	free(l);
	close(fd);
}*/
