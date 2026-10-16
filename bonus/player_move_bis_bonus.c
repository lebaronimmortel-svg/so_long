/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bis_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:26:10 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:13:23 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static int	is_move_ok(t_data *data, int ind_y, int ind_x)
{
	int	y;
	int	x;

	y = data->val->play_y / 100 + ind_y;
	x = data->val->play_x / 100 + ind_x;
	if (data->map[y][x] == '1')
		return (0);
	if (data->val->speed != 0)
		return (0);
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_program(data, 0);
	if (keycode == 65361 && is_move_ok(data, 0, -1))
		move_player_left(data);
	if (keycode == 65362 && is_move_ok(data, -1, 0))
		move_player_up(data);
	if (keycode == 65363 && is_move_ok(data, 0, 1))
		move_player_right(data);
	if (keycode == 65364 && is_move_ok(data, 1, 0))
		move_player_down(data);
	return (0);
}

void	update_player_pos(t_data *data)
{
	if (data->val->play_view == 2)
		data->val->play_x += 10;
	else if (data->val->play_view == 3)
		data->val->play_x -= 10;
	else if (data->val->play_view == 0)
		data->val->play_y -= 10;
	else if (data->val->play_view == 1)
		data->val->play_y += 10;
}
