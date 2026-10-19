/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 04:46:43 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:17:35 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	spawn_exit_coord(char **map, int *coord)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				coord[0] = i;
				coord[1] = j;
			}
			else if (map[i][j] == 'E')
			{
				coord[2] = i;
				coord[3] = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	my_strchr(char *str, char c)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	new_window(t_data *data)
{
	void	*mlx;
	int		wid;
	int		hei;

	mlx = data->mlx;
	wid = data->val->map_width * 100;
	hei = data->val->map_height * 100;
	data->win = mlx_new_window(mlx, wid, hei, "so_long");
}

void	initialize_formal_values(t_data *data)
{
	data->mlx = mlx_init();
	data->val->map_height = my_memlen(data->map);
	data->val->map_width = ft_strlen(data->map[0]);
	if (data->mlx)
		new_window(data);
	data->val->loop = 0;
	data->val->play_view = 2;
	data->val->moves_cnt = 0;
	data->val->coll_tot = 0;
	data->val->coll_cnt = 0;
}
