/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_position_update_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 12:57:37 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 05:48:41 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static int	is_next_valid(char **map, int y, int x, int ind)
{
	char	c;

	if (ind == 0)
		c = map[y][x - 1];
	else
		c = map[y][x + 1];
	if (c == '1')
		return (0);
	if (c == 'F')
		return (0);
	if (c == 'D')
		return (0);
	if (c == 'S')
		return (0);
	if (c == 'A')
		return (0);
	return (1);
}

static int	update_left(t_data *data, int y, int x)
{
	if (is_next_valid(data->map, y, x, 0))
	{
		data->map[y][x] = 'O';
		data->map[y][x - 1] = 'S';
		return (1);
	}
	else
		data->map[y][x] = 'A';
	return (0);
}

static int	update_right(t_data *data, int y, int x)
{
	if (is_next_valid(data->map, y, x, 1))
	{
		data->map[y][x] = 'O';
		data->map[y][x + 1] = 'A';
		return (1);
	}
	else
		data->map[y][x] = 'S';
	return (0);
}

int	update_enemy_pos(t_data *data, int y, int x)
{
	if (data->val->loop % 2000 == 0 && data->val->speed == 0)
	{
		if (data->map[y][x] == 'S')
		{
			if (update_left(data, y, x) == 1)
				return (1);
		}
		else if (data->map[y][x] == 'A')
		{
			if (update_right(data, y, x) == 1)
				return (1);
		}
	}
	return (0);
}
