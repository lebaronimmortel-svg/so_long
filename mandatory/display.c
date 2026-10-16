/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:20:35 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:14:36 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	display_map(t_data *data)
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
			{
				if ((data->val->play_y / 100 != y
						|| data->val->play_x / 100 != x)
					&& data->map[y][x] == 'O')
					put_image(data, x, y);
			}
			x += 1;
		}
		y += 1;
	}
}

void	display_player_position(t_data *data)
{
	if (data->val->play_view == 0)
		put_image_play(data, 0);
	else if (data->val->play_view == 1)
		put_image_play(data, 1);
	else if (data->val->play_view == 2)
		put_image_play(data, 3);
	else if (data->val->play_view == 3)
		put_image_play(data, 2);
}

int	core_fun(t_data *data)
{
	data->val->loop += 1;
	display_map(data);
	display_player_position(data);
	return (0);
}
