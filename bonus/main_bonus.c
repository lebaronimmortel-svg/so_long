/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:45:59 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:11:57 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static void	display_error_msg(int error)
{
	ft_putstr_fd("Error:\n", 2);
	if (error == -1)
		ft_putstr_fd("one argument required\n", 2);
	else if (error == 0)
		ft_putstr_fd("failed to allocate data\n", 2);
	else if (error == 2)
		ft_putstr_fd("invalid map name\n", 2);
	else if (error == 3)
		ft_putstr_fd("failed to read map file\n", 2);
	else if (error == 4)
		ft_putstr_fd("invalid map\n", 2);
	else if (error == 5)
		ft_putstr_fd("failed to load images\n", 2);
	else if (error == 6)
		ft_putstr_fd("map ok but larger than screen !\n", 2);
	else if (error == 7)
		ft_putstr_fd("map ok but taller than screen !\n", 2);
}

static void	launch(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_program, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop_hook(data->mlx, core_fun, data);
	mlx_loop(data->mlx);
}

static void	error_close(t_data *data, int error)
{
	if (data->val)
		free(data->val);
	if (data->xpm)
		free(data->xpm);
	display_error_msg(error);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		error;

	error = 0;
	data.val = malloc(sizeof(struct s_val));
	data.xpm = malloc(sizeof(struct s_xpm));
	if (argc != 2 || !(data.val) || !(data.xpm))
	{
		if (argc != 2)
			error = -1;
		error_close(&data, error);
		return (-1);
	}
	data.map = create_map(argv[1], &error);
	if (!data.map)
	{
		error_close(&data, error);
		return (-1);
	}
	if (!initialize(&data))
		error = 5;
	if (error == 0)
		launch(&data);
	display_error_msg(error);
	close_program(&data, 0);
}
