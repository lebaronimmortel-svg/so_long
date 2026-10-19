/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_spawn_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 04:42:50 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 04:42:52 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static int	enemy_valid_spawn(char **map, int y, int x)
{
	if (!map)
		return (0);
	if (my_strchr(map[y], 'Q'))
		return (0);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] != 'O' || map[y][x - 1] != 'O' || map[y][x + 1] != 'O')
		return (0);
	if (map[y + 1][x] != 'O' && map[y - 1][x] != 'O')
		return (0);
	return (1);
}

void	enemy_spawn(t_data *data)
{
	int	coord[2];

	coord[0] = data->val->map_height / 2;
	coord[1] = data->val->map_width / 2;
	while (data->val->mob_cnt < data->val->mob_cnt_max
		&& coord[0] < data->val->map_height - 1)
	{
		while (!enemy_valid_spawn(data->map, coord[0], coord[1])
			&& coord[0] < data->val->map_height - 1)
		{
			if (coord[1] == data->val->map_width - 1)
			{
				coord[1] = 1;
				coord[0]++;
			}
			else
				coord[1]++;
		}
		if (coord[0] == data->val->map_height - 1)
			return ;
		data->map[coord[0]][coord[1]] = 'S';
		data->val->mob_cnt += 1;
		coord[1] = 1;
		coord[0]++;
	}
}
