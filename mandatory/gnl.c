/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 04:38:57 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:16:13 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	j = 0;
	while (src[j] && j < size - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

static char	*get_line(char *buffer, char *str, int cnt, int ind)
{
	buffer[cnt - ind] = '\0';
	str = malloc(cnt + 1 * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, buffer, cnt + 1);
	return (str);
}

char	*gnl(int fd)
{
	ssize_t	bytes_read;
	char	buffer[25];
	char	*str;
	int		cnt;

	buffer[0] = '\0';
	cnt = 0;
	str = NULL;
	bytes_read = read(fd, &buffer[cnt], 1);
	if (bytes_read <= 0)
		return (NULL);
	cnt++;
	while (bytes_read > 0 && cnt < 24)
	{
		if (buffer[cnt - 1] == '\n')
		{
			str = get_line(buffer, str, cnt, 0);
			return (str);
		}
		bytes_read = read(fd, &buffer[cnt], 1);
		cnt++;
	}
	str = get_line(buffer, str, cnt, 1);
	return (str);
}
