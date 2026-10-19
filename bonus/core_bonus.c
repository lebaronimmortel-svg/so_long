/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:30:03 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:03:33 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static int	hit_by_mob(t_data *data)
{
	int	y;
	int	x;

	y = data->val->play_y / 100;
	x = data->val->play_x / 100;
	if (data->map[y][x] == 'A')
		return (1);
	else if (data->map[y][x] == 'S')
		return (1);
	return (0);
}

int	core_fun(t_data *data)
{
	data->val->loop += 1;
	if (hit_by_mob(data))
		close_program(data, 2);
	if (data->val->speed == 1 && data->val->loop % 1000 == 0)
		update_player_pos(data);
	if (data->val->moves_cnt <= 9999)
		display_moves_count(data);
	display_enemy(data);
	display_map(data);
	display_player_position(data);
	return (0);
}
