/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:16:53 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:16:55 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	initialize_basic_images(t_data *data)
{
	void			*mlx;
	int				*w;
	int				*h;
	struct s_xpm	*img;

	img = data->xpm;
	mlx = data->mlx;
	w = &(data->val->width);
	h = &(data->val->height);
	img->grass = mlx_xpm_file_to_image(mlx, "xpm/env/grass.xpm", w, h);
	img->barrier = mlx_xpm_file_to_image(mlx, "xpm/env/barrier.xpm", w, h);
	img->exit = mlx_xpm_file_to_image(mlx, "xpm/env/exit.xpm", w, h);
	img->coll = mlx_xpm_file_to_image(mlx, "xpm/env/coll.xpm", w, h);
	img->play_right = mlx_xpm_file_to_image(mlx, "xpm/player/idle/r.xpm", w, h);
	img->play_left = mlx_xpm_file_to_image(mlx, "xpm/player/idle/l.xpm", w, h);
	img->play_up = mlx_xpm_file_to_image(mlx, "xpm/player/up/u.xpm", w, h);
	img->play_down = mlx_xpm_file_to_image(mlx, "xpm/player/idle/d.xpm", w, h);
	if (!img->grass || !img->barrier || !img->exit || !img->coll
		|| !img->play_right || !img->play_left || !img->play_up
		|| !img->play_down)
		return (0);
	return (1);
}

int	initialize_all(t_data *data)
{
	initialize_formal_values(data);
	if (!data->mlx || !data->win)
		return (0);
	if (!initialize_basic_images(data))
		return (0);
	return (1);
}
