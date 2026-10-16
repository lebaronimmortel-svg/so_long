/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:20:35 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:04:52 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	display_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->val->map_height)
	{
		x = 0;
		while (x < data->val->map_width)
		{
			if (data->map[y][x] != '1')
				display_square(data, y, x);
			x += 1;
		}
		y += 1;
	}
}

void	display_enemy(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->val->map_height)
	{
		x = 0;
		while (x < data->val->map_width)
		{
			if (update_enemy_pos(data, y, x))
				break ;
			x += 1;
		}
		y += 1;
	}
}

static int	is_grass_square(t_data *data, int y, int x)
{
	if (data->val->play_y / 100 == y && data->val->play_x / 100 == x)
		return (0);
	if (data->val->speed != 0)
		return (0);
	if (data->map[y][x] != 'O')
		return (0);
	return (1);
}

void	display_square(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'A')
		put_image(data, x, y, 0);
	else if (data->map[y][x] == 'S')
		put_image(data, x, y, 1);
	else if (is_grass_square(data, y, x))
		put_image(data, x, y, 2);
}
