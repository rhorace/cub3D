/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:15:55 by rhorace           #+#    #+#             */
/*   Updated: 2026/07/06 18:25:33 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i = 0;

	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

static size_t	ft_strlen(char *s)
{
	size_t	ret = 0;

	if (!s)
		return (0);
	while (s[ret])
		ret++;
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);

	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp [size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;

	char	*tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (b[0] != '\0')
		{
			if (!str_append_mem(&ret, b, ft_strlen(b)))
			{
				free(ret);
				return (NULL);
			}
		}
		int read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(ret);
			return (NULL);
		}
		b[read_ret] = 0;
		if (read_ret == 0)
			return (ret);
		tmp = ft_strchr(b, '\n');
	}
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	return (ret);
}
