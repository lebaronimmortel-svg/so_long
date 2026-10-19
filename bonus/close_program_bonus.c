/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program_bonus.c                                :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:44:06 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:03:53 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static void	destroy_img(t_data *data)
{
	if (data->xpm->panel)
		mlx_destroy_image(data->mlx, data->xpm->panel);
	if (data->xpm->grass)
		mlx_destroy_image(data->mlx, data->xpm->grass);
	if (data->xpm->barrier)
		mlx_destroy_image(data->mlx, data->xpm->barrier);
	if (data->xpm->mob_left)
		mlx_destroy_image(data->mlx, data->xpm->mob_left);
	if (data->xpm->mob_right)
		mlx_destroy_image(data->mlx, data->xpm->mob_right);
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

static void	destroy_img2(t_data *data)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (data->xpm->walk_right[i])
			mlx_destroy_image(data->mlx, data->xpm->walk_right[i]);
		if (data->xpm->walk_left[i])
			mlx_destroy_image(data->mlx, data->xpm->walk_left[i]);
		if (data->xpm->digit_img[i])
			mlx_destroy_image(data->mlx, data->xpm->digit_img[i]);
		i++;
	}
	if (data->xpm->digit_img[9])
		mlx_destroy_image(data->mlx, data->xpm->digit_img[9]);
}

static void	destroy_img3(t_data *data)
{
	if (data->xpm->up_top[0])
		mlx_destroy_image(data->mlx, data->xpm->up_top[0]);
	if (data->xpm->up_top[1])
		mlx_destroy_image(data->mlx, data->xpm->up_top[1]);
	if (data->xpm->up_bot[0])
		mlx_destroy_image(data->mlx, data->xpm->up_bot[0]);
	if (data->xpm->up_bot[1])
		mlx_destroy_image(data->mlx, data->xpm->up_bot[1]);
	if (data->xpm->down_top[0])
		mlx_destroy_image(data->mlx, data->xpm->down_top[0]);
	if (data->xpm->down_top[1])
		mlx_destroy_image(data->mlx, data->xpm->down_top[1]);
	if (data->xpm->down_bot[0])
		mlx_destroy_image(data->mlx, data->xpm->down_bot[0]);
	if (data->xpm->down_bot[1])
		mlx_destroy_image(data->mlx, data->xpm->down_bot[1]);
}

int	close_program(t_data *data, int ind)
{
	destroy_img(data);
	destroy_img2(data);
	destroy_img3(data);
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
	else if (ind == 2)
		ft_putstr_fd("You lose !\n", 1);
	exit(0);
	return (0);
}
