/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:48:27 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:17:42 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static int	is_valid_square(char c)
{
	char	array[5];
	int		i;

	array[0] = 'P';
	array[1] = 'C';
	array[2] = 'E';
	array[3] = '0';
	array[4] = '1';
	i = 0;
	while (i < 5)
	{
		if (c == array[i])
			return (1);
		i++;
	}
	return (0);
}

static int	is_valid_middle_line(char *str, int *ind_P, int *ind_E)
{
	int	i;

	if (!str)
		return (0);
	if (str[0] != '1')
		return (0);
	i = 1;
	while (str[i] != 1 && str[i])
	{
		if (!is_valid_square(str[i]))
			return (0);
		if (str[i] == 'P')
			(*ind_P)++;
		else if (str[i] == 'E')
			(*ind_E)++;
		i++;
	}
	if (str[i] == '\0' && str[i - 1] == '1')
		return (1);
	else
		return (0);
}

static int	is_valid_line(char **map, int i, int *p_cnt, int *e_cnt)
{
	unsigned int	len;

	len = ft_strlen(map[0]);
	if (ft_strlen(map[i]) != len)
		return (0);
	if (i == 0 || i == my_memlen(map) - 1)
	{
		if (!is_valid_border_line(map[i]))
			return (0);
	}
	else
	{
		if (!is_valid_middle_line(map[i], p_cnt, e_cnt))
			return (0);
	}
	return (1);
}

int	error_check2(int fd, char *str2, int *error)
{
	if (!str2 || *error != 0)
	{
		if (str2)
			free(str2);
		if (fd >= 0)
			close (fd);
		return (0);
	}
	return (1);
}

int	item_count(char **map, int *error)
{
	int	i;
	int	cnt[3];

	if (!map || !(*map))
		return (0);
	i = 0;
	cnt[0] = 0;
	cnt[1] = 0;
	cnt[2] = 0;
	while (map[i])
	{
		if (my_strchr(map[i], 'C'))
			cnt[2]++;
		if (!is_valid_line(map, i, &cnt[0], &cnt[1]))
		{
			*error = 4;
			return (0);
		}
		if (ft_strlen(map[i]) >= 20 && *error == 0)
			*error = 6;
		i++;
	}
	if (cnt[0] != 1 || cnt[1] != 1 || cnt[2] == 0)
		return (0);
	return (1);
}
