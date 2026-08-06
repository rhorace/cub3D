/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:56:04 by sohollar          #+#    #+#             */
/*   Updated: 2026/07/16 08:30:52 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (str[i] != (unsigned char) c && i < (n - 1))
		i++;
	if (str[i] == (unsigned char) c)
		return (NULL);
	else
		return (NULL);
}

/* int	main(void)
{
	char	*str;
	int		c;

	c = 100;
	str = "The only difference between science \
	anD messing arounD is writing it Down";
	printf("%s\n", (char *)ft_memchr(str, c, 11));
	printf("%s", (char *)memchr(str, c, 11));
} */
