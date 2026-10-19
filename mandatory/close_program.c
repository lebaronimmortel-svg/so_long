/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:44:06 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:14:12 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	destroy_img(t_data *data)
{
	if (data->xpm->grass)
		mlx_destroy_image(data->mlx, data->xpm->grass);
	if (data->xpm->barrier)
		mlx_destroy_image(data->mlx, data->xpm->barrier);
	if (data->xpm->exit)
		mlx_destroy_image(data->mlx, data->xpm->exit);
	if (data->xpm->coll)
		mlx_destroy_image(data->mlx, data->xpm->coll);
	if (data->xpm->play_right)
		mlx_destroy_image(data->mlx, data->xpm->play_right);
	if (data->xpm->play_left)
		mlx_destroy_image(data->mlx, data->xpm->play_left);
	if (data->xpm->play_up)
		mlx_destroy_image(data->mlx, data->xpm->play_up);
	if (data->xpm->play_down)
		mlx_destroy_image(data->mlx, data->xpm->play_down);
}

int	close_program(t_data *data, int ind)
{
	destroy_img(data);
	free_map(data->map);
	free(data->val);
	free(data->xpm);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	if (ind == 1)
		ft_putstr_fd("You win !\n", 1);
	exit(0);
	return (0);
}
