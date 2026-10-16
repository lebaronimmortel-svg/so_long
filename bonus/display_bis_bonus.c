/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bis_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:14:59 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:04:08 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static void	display_player_left(t_data *data)
{
	int	i;

	if (data->val->speed == 1 && data->val->loop % 1000 == 0)
	{
		i = 0;
		while (i < 9)
		{
			if ((data->val->play_x + 10 * (1 + i)) % 100 == 0)
			{
				put_image_walk(data, i, 0);
				break ;
			}
			i++;
		}
		if (data->val->play_x % 100 == 0)
			data->val->speed = 0;
	}
	else if (data->val->speed == 0)
		put_image_play(data, 2);
}

static void	display_player_right(t_data *data)
{
	int	i;

	if (data->val->speed == 1 && data->val->loop % 1000 == 0)
	{
		i = 0;
		while (i < 9)
		{
			if ((data->val->play_x - 10 * (1 + i)) % 100 == 0)
			{
				put_image_walk(data, i, 1);
				break ;
			}
			i++;
		}
		if (data->val->play_x % 100 == 0)
			data->val->speed = 0;
	}
	else if (data->val->speed == 0)
		put_image_play(data, 3);
}

static void	display_player_down(t_data *data)
{
	if (data->val->speed == 1 && data->val->loop % 1000 == 0)
	{
		if ((data->val->play_y + 30) % 100 == 0)
		{
			put_image_down(data, 0, 0, (data->val->play_y / 100) * 100);
			put_image_down(data, 0, 1, (data->val->play_y / 100) * 100 + 100);
		}
		else if ((data->val->play_y + 50) % 100 == 0)
		{
			put_image_down(data, 1, 0, (data->val->play_y / 100) * 100);
			put_image_down(data, 1, 1, (data->val->play_y / 100) * 100 + 100);
		}
		else if ((data->val->play_y + 70) % 100 == 0)
		{
			put_image_down(data, 1, 0, (data->val->play_y / 100) * 100);
			put_image_down(data, 1, 1, (data->val->play_y / 100) * 100 + 100);
		}
		else if (data->val->play_y % 100 == 0)
			data->val->speed = 0;
	}
	else if (data->val->speed == 0)
		put_image_play(data, 1);
}

static void	display_player_up(t_data *data)
{
	if (data->val->speed == 1 && data->val->loop % 1000 == 0)
	{
		if ((data->val->play_y - 30) % 100 == 0)
		{
			put_image_up(data, 0, 0, (data->val->play_y / 100) * 100);
			put_image_up(data, 0, 1, (data->val->play_y / 100) * 100 + 100);
		}
		else if ((data->val->play_y - 50) % 100 == 0)
		{
			put_image_up(data, 1, 0, (data->val->play_y / 100) * 100);
			put_image_up(data, 1, 1, (data->val->play_y / 100) * 100 + 100);
		}
		else if ((data->val->play_y - 70) % 100 == 0)
		{
			put_image_up(data, 1, 0, (data->val->play_y / 100) * 100);
			put_image_up(data, 1, 1, (data->val->play_y / 100) * 100 + 100);
		}
		else if (data->val->play_y % 100 == 0)
			data->val->speed = 0;
	}
	else if (data->val->speed == 0)
		put_image_play(data, 0);
}

void	display_player_position(t_data *data)
{
	if (data->val->play_view == 0)
		display_player_up(data);
	else if (data->val->play_view == 1)
		display_player_down(data);
	else if (data->val->play_view == 2)
		display_player_right(data);
	else if (data->val->play_view == 3)
		display_player_left(data);
}
