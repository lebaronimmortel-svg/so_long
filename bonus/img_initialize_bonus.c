/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_initialize_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:48:37 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:10:47 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static int	initialize_profile_images_right(t_data *data)
{
	void	*mlx;
	int		*w;
	int		*h;
	void	**img;

	mlx = data->mlx;
	w = &(data->val->width);
	h = &(data->val->height);
	img = data->xpm->walk_right;
	img[0] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/r_1.xpm", w, h);
	img[1] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/r_2.xpm", w, h);
	img[2] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/r_3.xpm", w, h);
	img[3] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/r_4.xpm", w, h);
	img[4] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/r_5.xpm", w, h);
	img[5] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/r_6.xpm", w, h);
	img[6] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/r_7.xpm", w, h);
	img[7] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/r_8.xpm", w, h);
	img[8] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/r_9.xpm", w, h);
	if (!img[0] || !img[1] || !img[2] || !img[3] || !img[4] || !img[5]
		|| !img[6] || !img[7] || !img[8])
		return (0);
	return (1);
}

static int	initialize_profile_images_left(t_data *data)
{
	void	*mlx;
	int		*w;
	int		*h;
	void	**img;

	mlx = data->mlx;
	w = &(data->val->width);
	h = &(data->val->height);
	img = data->xpm->walk_left;
	img[0] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/l_1.xpm", w, h);
	img[1] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/l_2.xpm", w, h);
	img[2] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/l_3.xpm", w, h);
	img[3] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/l_4.xpm", w, h);
	img[4] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/l_5.xpm", w, h);
	img[5] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/l_6.xpm", w, h);
	img[6] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/l_7.xpm", w, h);
	img[7] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/l_8.xpm", w, h);
	img[8] = mlx_xpm_file_to_image(mlx, "xpm/player/profile/l_9.xpm", w, h);
	if (!img[0] || !img[1] || !img[2] || !img[3] || !img[4] || !img[5]
		|| !img[6] || !img[7] || !img[8])
		return (0);
	return (1);
}

static int	initialize_profile_images_face(t_data *data)
{
	void	*mlx;
	int		*w;
	int		*h;
	void	**img[4];

	img[0] = data->xpm->up_top;
	img[1] = data->xpm->up_bot;
	img[2] = data->xpm->down_top;
	img[3] = data->xpm->down_bot;
	mlx = data->mlx;
	w = &(data->val->width);
	h = &(data->val->height);
	img[0][0] = mlx_xpm_file_to_image(mlx, "xpm/player/up/u_4_top.xpm", w, h);
	img[1][0] = mlx_xpm_file_to_image(mlx, "xpm/player/up/u_4_bot.xpm", w, h);
	img[0][1] = mlx_xpm_file_to_image(mlx, "xpm/player/up/u_5_top.xpm", w, h);
	img[1][1] = mlx_xpm_file_to_image(mlx, "xpm/player/up/u_5_bot.xpm", w, h);
	img[2][0] = mlx_xpm_file_to_image(mlx, "xpm/player/up/d_3_top.xpm", w, h);
	img[3][0] = mlx_xpm_file_to_image(mlx, "xpm/player/up/d_3_bot.xpm", w, h);
	img[2][1] = mlx_xpm_file_to_image(mlx, "xpm/player/up/d_4_top.xpm", w, h);
	img[3][1] = mlx_xpm_file_to_image(mlx, "xpm/player/up/d_4_bot.xpm", w, h);
	if (!img[0][0] || !img[1][0] || !img[0][1] || !img[1][1] || !img[2][0]
	|| !img[3][0] || !img[2][1] || !img[3][1])
		return (0);
	return (1);
}

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
	img->mob_right = mlx_xpm_file_to_image(mlx, "xpm/env/enemy.xpm", w, h);
	img->mob_left = mlx_xpm_file_to_image(mlx, "xpm/env/enemy2.xpm", w, h);
	img->play_right = mlx_xpm_file_to_image(mlx, "xpm/player/idle/r.xpm", w, h);
	img->play_left = mlx_xpm_file_to_image(mlx, "xpm/player/idle/l.xpm", w, h);
	img->play_up = mlx_xpm_file_to_image(mlx, "xpm/player/up/u.xpm", w, h);
	img->play_down = mlx_xpm_file_to_image(mlx, "xpm/player/idle/d.xpm", w, h);
	if (!img->grass || !img->barrier || !img->exit || !img->coll
		|| !img->mob_right || !img->mob_left || !img->play_right
		|| !img->play_left || !img->play_up || !img->play_down)
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
	if (!initialize_profile_images_right(data))
		return (0);
	if (!initialize_profile_images_left(data))
		return (0);
	if (!initialize_profile_images_face(data))
		return (0);
	return (1);
}
