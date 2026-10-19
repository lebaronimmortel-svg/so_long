/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves_count_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:10:57 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 05:46:58 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static void	put_digit(t_data *data, int i, int pos_x)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;

	mlx = data->mlx;
	win = data->win;
	img = data->xpm->digit_img[i];
	x = pos_x;
	mlx_put_image_to_window(mlx, win, img, x, 23);
}

static void	display_digits(t_data *data, int moves_count, int pos_x)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (moves_count % 10 == i)
		{
			put_digit(data, i, pos_x);
			break ;
		}
		i += 1;
	}
}

void	display_moves_count(t_data *data)
{
	int	position_x;
	int	moves_count;

	position_x = 250;
	moves_count = data->val->moves_cnt;
	if (moves_count / 10 == 0)
		display_digits(data, moves_count, position_x);
	else
	{
		while (moves_count / 10)
		{
			display_digits(data, moves_count, position_x);
			position_x -= 25;
			moves_count = moves_count / 10;
		}
		display_digits(data, moves_count, position_x);
	}
}
