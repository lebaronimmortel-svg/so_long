/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:31:57 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:17:18 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	put_image_init(t_data *data, int ind, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = data->mlx;
	win = data->win;
	if (ind == 0)
		img = data->xpm->barrier;
	else if (ind == 1)
		img = data->xpm->exit;
	else if (ind == 2)
		img = data->xpm->coll;
	else if (ind == 4)
		img = data->xpm->play_right;
	else
		img = data->xpm->grass;
	mlx_put_image_to_window(mlx, win, img, x, y);
}

static void	read_map(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		put_image_init(data, 0, x * 100, y * 100);
	else if (data->map[y][x] == 'F')
		put_image_init(data, 1, x * 100, y * 100);
	else if (data->map[y][x] == 'D')
	{
		put_image_init(data, 2, x * 100, y * 100);
		(data->val->coll_tot)++;
	}
	else if (data->map[y][x] == 'Q')
	{
		put_image_init(data, 4, x * 100, y * 100);
		data->val->play_y = y * 100;
		data->val->play_x = x * 100;
		data->map[y][x] = 'O';
	}
	else
		put_image_init(data, 5, x * 100, y * 100);
}

void	initialize_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->val->map_height)
	{
		x = 0;
		while (x < data->val->map_width)
		{
			read_map(data, x, y);
			x += 1;
		}
		y += 1;
	}
}
