/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:47:59 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:20:39 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t			i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	my_memlen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s2[i] != s1[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const	*str1, char const	*str2)
{
	size_t				i;
	size_t				j;
	size_t				cnt;
	char				*tab;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	j = 0;
	cnt = ft_strlen(str1) + ft_strlen(str2);
	tab = (char *) malloc ((cnt + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (str1[i] != '\0')
	{
		tab[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		tab[i + j] = str2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}
