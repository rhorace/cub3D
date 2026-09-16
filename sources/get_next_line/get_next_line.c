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

#include "cub3D.h"
#include "get_next_line.h"

static char	*ajouter_tant_que(int fd, char *s_chaine, char *espace_memoire);
static char	*couper_ligne(char *ligne_retour_M);
static char	*cherche_n(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*s_chaine;
	char		*ligne_retour;
	char		*espace_memoire;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(s_chaine);
		s_chaine = NULL;
		return (NULL);
	}
	espace_memoire = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!espace_memoire)
		return (NULL);
	ligne_retour = ajouter_tant_que(fd, s_chaine, espace_memoire);
	free(espace_memoire);
	if (!ligne_retour)
	{
		free(s_chaine);
		s_chaine = NULL;
		return (NULL);
	}
	s_chaine = couper_ligne(ligne_retour);
	return (ligne_retour);
}

static char	*couper_ligne(char *ligne_retour_M)
{
	char	*s_chaine;
	int		i;
	int		len;

	i = 0;
	while (ligne_retour_M[i] != '\n' && ligne_retour_M[i] != '\0')
		i++;
	if (ligne_retour_M[i] == '\0' || ligne_retour_M[i + 1] == '\0')
		return (NULL);
	len = ft_strlen(ligne_retour_M);
	s_chaine = ft_substr(ligne_retour_M, i + 1, len - i);
	if (!s_chaine)
		return (NULL);
	if (s_chaine[0] == '\0')
	{
		free(s_chaine);
		s_chaine = NULL;
	}
	ligne_retour_M[i + 1] = '\0';
	return (s_chaine);
}

static char	*ajouter_tant_que(int fd, char *s_chaine, char *espace_memoire)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, espace_memoire, BUFFER_SIZE);
		if (b_read == -1)
			return (NULL);
		if (b_read == 0)
			break ;
		espace_memoire[b_read] = '\0';
		if (!s_chaine)
			s_chaine = ft_strdup("");
		tmp = s_chaine;
		s_chaine = ft_strjoin(tmp, espace_memoire);
		free(tmp);
		tmp = NULL;
		if (cherche_n(espace_memoire, '\n'))
			break ;
	}
	return (s_chaine);
}

static char	*cherche_n(char *s, int n)
{
	unsigned int	i;
	char			nn;

	if (!s)
		return (NULL);
	nn = (char)n;
	i = 0;
	while (s[i])
	{
		if (s[i] == nn)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == nn)
		return ((char *)&s[i]);
	return (NULL);
}
