/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:24:58 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/12 18:30:58 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) +1);
	if (str == NULL)
		return (NULL);
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	return (str);
}

/* int	main(void)
{
	const char	*s1;
	const char	*s2;
	char		*join;

	s1 = "Bonjour Madame ";
	s2 = "George Sand !";
	join = ft_strjoin(s1, s2);
	printf("%s\n", join);
	free(join);
} */
