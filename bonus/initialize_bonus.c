/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:35:30 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/15 12:51:33 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static void	define_nb_mob(t_data *data)
{
	if (ft_strlen(data->map[0]) <= 10)
		data->val->mob_cnt_max = 1;
	else
		data->val->mob_cnt_max = 2;
}

static void	initialize_null2(t_data *data)
{
	data->xpm->digit_img[9] = NULL;
	data->xpm->up_top[0] = NULL;
	data->xpm->up_bot[0] = NULL;
	data->xpm->down_top[0] = NULL;
	data->xpm->down_bot[0] = NULL;
	data->xpm->up_top[1] = NULL;
	data->xpm->up_bot[1] = NULL;
	data->xpm->down_top[1] = NULL;
	data->xpm->down_bot[1] = NULL;
}

static void	initialize_null(t_data *data)
{
	int	i;

	data->xpm->panel = NULL;
	data->xpm->grass = NULL;
	data->xpm->barrier = NULL;
	data->xpm->mob_right = NULL;
	data->xpm->mob_left = NULL;
	data->xpm->exit = NULL;
	data->xpm->coll = NULL;
	data->xpm->play_right = NULL;
	data->xpm->play_left = NULL;
	data->xpm->play_up = NULL;
	data->xpm->play_down = NULL;
	i = 0;
	while (i < 9)
	{
		data->xpm->walk_right[i] = NULL;
		data->xpm->walk_left[i] = NULL;
		data->xpm->digit_img[i] = NULL;
		i++;
	}
}

static int	initialize_panel(t_data *data)
{
	int		*w;
	int		*h;
	void	**img;

	w = &(data->val->width);
	h = &(data->val->height);
	img = data->xpm->digit_img;
	data->xpm->panel
		= mlx_xpm_file_to_image(data->mlx, "xpm/env/panel.xpm", w, h);
	img[0] = mlx_xpm_file_to_image(data->mlx, "xpm/env/0.xpm", w, h);
	img[1] = mlx_xpm_file_to_image(data->mlx, "xpm/env/1.xpm", w, h);
	img[2] = mlx_xpm_file_to_image(data->mlx, "xpm/env/2.xpm", w, h);
	img[3] = mlx_xpm_file_to_image(data->mlx, "xpm/env/3.xpm", w, h);
	img[4] = mlx_xpm_file_to_image(data->mlx, "xpm/env/4.xpm", w, h);
	img[5] = mlx_xpm_file_to_image(data->mlx, "xpm/env/5.xpm", w, h);
	img[6] = mlx_xpm_file_to_image(data->mlx, "xpm/env/6.xpm", w, h);
	img[7] = mlx_xpm_file_to_image(data->mlx, "xpm/env/7.xpm", w, h);
	img[8] = mlx_xpm_file_to_image(data->mlx, "xpm/env/8.xpm", w, h);
	img[9] = mlx_xpm_file_to_image(data->mlx, "xpm/env/9.xpm", w, h);
	if (!img[0] || !img[1] || !img[2] || !img[3] || !img[4] || !img[5]
		|| !img[6] || !img[7] || !img[8] || !img[9] || !data->xpm->panel)
		return (0);
	mlx_put_image_to_window(data->mlx, data->win, data->xpm->panel, 5, 20);
	return (1);
}

int	initialize(t_data *data)
{
	define_nb_mob(data);
	initialize_null(data);
	initialize_null2(data);
	if (!initialize_all(data))
		return (0);
	enemy_spawn(data);
	initialize_map(data);
	if (!initialize_panel(data))
		return (0);
	return (1);
}
