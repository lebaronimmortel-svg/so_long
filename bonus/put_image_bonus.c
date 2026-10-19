/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 12:47:05 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:20:15 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	put_image(t_data *data, int x, int y, int ind)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = data->mlx;
	win = data->win;
	if (ind == 0)
		img = data->xpm->mob_right;
	else if (ind == 1)
		img = data->xpm->mob_left;
	else
		img = data->xpm->grass;
	mlx_put_image_to_window(mlx, win, img, x * 100, y * 100);
}

void	put_image_up(t_data *data, int index, int pos, int y)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;

	mlx = data->mlx;
	win = data->win;
	if (pos == 0)
		img = data->xpm->up_top[index];
	else
		img = data->xpm->up_bot[index];
	x = data->val->play_x;
	mlx_put_image_to_window(mlx, win, img, x, y);
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

void	put_image_walk(t_data *data, int i, int pos)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;

	mlx = data->mlx;
	win = data->win;
	if (pos == 0)
		img = data->xpm->walk_left[i];
	else
		img = data->xpm->walk_right[i];
	x = data->val->play_x;
	y = data->val->play_y;
	mlx_put_image_to_window(mlx, win, img, x, y);
}

void	put_image_down(t_data *data, int index, int pos, int y)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;

	mlx = data->mlx;
	win = data->win;
	if (pos == 0)
		img = data->xpm->down_top[index];
	else
		img = data->xpm->down_bot[index];
	x = data->val->play_x;
	mlx_put_image_to_window(mlx, win, img, x, y);
}
