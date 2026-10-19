/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:52:09 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:13:09 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h" 

int	is_valid_border_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

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

int	is_valid_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".ber", 4))
		return (0);
	return (1);
}

static int	is_empty_square(char **map, int p_y, int p_x)
{
	if (map[p_y][p_x] == '0')
		return (1);
	if (map[p_y][p_x] == 'C')
		return (1);
	if (map[p_y][p_x] == 'E')
		return (1);
	if (map[p_y][p_x] == 'P')
		return (1);
	return (0);
}

void	flood_fill(char **map, int p_y, int p_x)
{
	if (!is_empty_square(map, p_y, p_x))
		return ;
	if (map[p_y][p_x] == '0')
		map[p_y][p_x] = 'O';
	else if (map[p_y][p_x] == 'C')
		map[p_y][p_x] = 'D';
	else if (map[p_y][p_x] == 'E')
	{
		map[p_y][p_x] = 'F';
		return ;
	}
	else if (map[p_y][p_x] == 'P')
		map[p_y][p_x] = 'Q';
	flood_fill(map, p_y, p_x + 1);
	flood_fill(map, p_y, p_x - 1);
	flood_fill(map, p_y + 1, p_x);
	flood_fill(map, p_y - 1, p_x);
}
