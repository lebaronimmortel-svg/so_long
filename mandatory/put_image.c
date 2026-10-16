/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 12:47:05 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:18:22 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	put_image(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = data->mlx;
	win = data->win;
	img = data->xpm->grass;
	mlx_put_image_to_window(mlx, win, img, x * 100, y * 100);
}

void	put_image_play(t_data *data, int ind)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;

	mlx = data->mlx;
	win = data->win;
	if (ind == 0)
		img = data->xpm->play_up;
	else if (ind == 1)
		img = data->xpm->play_down;
	else if (ind == 2)
		img = data->xpm->play_left;
	else
		img = data->xpm->play_right;
	x = data->val->play_x;
	y = data->val->play_y;
	mlx_put_image_to_window(mlx, win, img, x, y);
}
