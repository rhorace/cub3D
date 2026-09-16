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

static size_t	ft_strlen(char *s)
{
	size_t	ret;

	ret = 0;
	if (!s)
		return (0);
	while (s[ret])
		ret++;
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*tmp;

	size1 = ft_strlen(*s1);
	tmp = malloc(size2 + size1 + 1);
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

static int	read_until_newline(int fd, char *b, char **ret)
{
	int	read_ret;

	while (!ft_strchr(b, '\n'))
	{
		if (b[0] && !str_append_mem(ret, b, ft_strlen(b)))
			return (0);
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (0);
		b[read_ret] = '\0';
		if (read_ret == 0)
			return (2);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char		*ret;
	char		*tmp;
	int			status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = NULL;
	status = read_until_newline(fd, b, &ret);
	if (status == 0)
		return (free(ret), NULL);
	if (status == 2)
		return (ret);
	tmp = ft_strchr(b, '\n');
	if (!str_append_mem(&ret, b, tmp - b + 1))
		return (free(ret), NULL);
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	return (ret);
}
