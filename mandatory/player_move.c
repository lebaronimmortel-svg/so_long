/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:17:12 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:18:03 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_putnbr_fd(int n, int fd)
{
	char	c;	

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + 48;
		write(fd, &c, 1);
	}
	if (n < 10 && n >= 0)
	{
		c = n + 48;
		write(fd, &c, 1);
	}
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
	data->val->moves_cnt += 1;
	ft_putstr_fd("moves : ", 1);
	ft_putnbr_fd(data->val->moves_cnt, 1);
	write(1, "\n", 1);
	data->val->play_x -= 100;
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
	data->val->moves_cnt += 1;
	ft_putstr_fd("moves : ", 1);
	ft_putnbr_fd(data->val->moves_cnt, 1);
	write(1, "\n", 1);
	data->val->play_y -= 100;
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
	data->val->moves_cnt += 1;
	ft_putstr_fd("moves : ", 1);
	ft_putnbr_fd(data->val->moves_cnt, 1);
	write(1, "\n", 1);
	data->val->play_x += 100;
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
	data->val->moves_cnt += 1;
	ft_putstr_fd("moves : ", 1);
	ft_putnbr_fd(data->val->moves_cnt, 1);
	write(1, "\n", 1);
	data->val->play_y += 100;
	data->val->play_view = 1;
}
