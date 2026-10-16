/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:17:12 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:13:31 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static int	is_square_a_mob(t_data *data, int a, int b)
{
	if (data->map[data->val->play_y / 100 + a]
		[data->val->play_x / 100 + b] == 'S')
		return (1);
	if (data->map[data->val->play_y / 100 + a]
		[data->val->play_x / 100 + b] == 'A')
		return (1);
	return (0);
}

void	move_player_left(t_data *data)
{
	if (data->map[data->val->play_y / 100][data->val->play_x / 100 - 1] == 'D')
	{
		data->map[data->val->play_y / 100][data->val->play_x / 100 - 1] = 'O';
		data->val->coll_cnt += 1;
	}
	else if (data->map[data->val->play_y / 100]
		[data->val->play_x / 100 - 1] == 'F')
	{
		if (data->val->coll_cnt == data->val->coll_tot)
			close_program(data, 1);
		else
			return ;
	}
	else if (is_square_a_mob(data, 0, -1))
		close_program(data, 2);
	data->val->moves_cnt += 1;
	data->val->speed = 1;
	data->val->play_view = 3;
}

void	move_player_up(t_data *data)
{
	if (data->map[data->val->play_y / 100 - 1][data->val->play_x / 100] == 'D')
	{
		data->map[data->val->play_y / 100 - 1][data->val->play_x / 100] = 'O';
		data->val->coll_cnt += 1;
	}
	else if (data->map[data->val->play_y / 100 - 1]
		[data->val->play_x / 100] == 'F')
	{
		if (data->val->coll_cnt == data->val->coll_tot)
			close_program(data, 1);
		else
			return ;
	}
	else if (is_square_a_mob(data, -1, 0))
		close_program(data, 2);
	data->val->moves_cnt += 1;
	data->val->speed = 1;
	data->val->play_view = 0;
}

void	move_player_right(t_data *data)
{
	if (data->map[data->val->play_y / 100][data->val->play_x / 100 + 1] == 'D')
	{
		data->map[data->val->play_y / 100][data->val->play_x / 100 + 1] = 'O';
		data->val->coll_cnt += 1;
	}
	else if (data->map[data->val->play_y / 100]
		[data->val->play_x / 100 + 1] == 'F')
	{
		if (data->val->coll_cnt == data->val->coll_tot)
			close_program(data, 1);
		else
			return ;
	}
	else if (is_square_a_mob(data, 0, 1))
		close_program(data, 2);
	data->val->moves_cnt += 1;
	data->val->speed = 1;
	data->val->play_view = 2;
}

void	move_player_down(t_data *data)
{
	if (data->map[data->val->play_y / 100 + 1][data->val->play_x / 100] == 'D')
	{
		data->map[data->val->play_y / 100 + 1][data->val->play_x / 100] = 'O';
		data->val->coll_cnt += 1;
	}
	else if (data->map[data->val->play_y / 100 + 1]
		[data->val->play_x / 100] == 'F')
	{
		if (data->val->coll_cnt == data->val->coll_tot)
			close_program(data, 1);
		else
			return ;
	}
	else if (is_square_a_mob(data, 1, 0))
		close_program(data, 2);
	data->val->moves_cnt += 1;
	data->val->speed = 1;
	data->val->play_view = 1;
}
