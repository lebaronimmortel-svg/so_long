/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:45:03 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:14:26 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	error_check(char *filename, int *error)
{
	int	fd;

	if (!is_valid_name(filename) || ft_strlen(filename) < 5)
		*error = 2;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		*error = 3;
	return (fd);
}

static char	**read_from_file(char *filename, int *error)
{
	char	*str0;
	char	*str1;
	char	*str2;
	char	**map;
	int		fd;

	fd = error_check(filename, error);
	str2 = malloc(1);
	if (!error_check2(fd, str2, error))
		return (NULL);
	*(str2) = '\0';
	str0 = gnl(fd);
	while (str0)
	{
		if (!add_tail(&str0, &str1, &str2))
		{
			close(fd);
			return (NULL);
		}
		str0 = gnl(fd);
	}
	map = ft_split(str2, '\n');
	free(str2);
	close(fd);
	return (map);
}

static int	is_valid_path(char **map, int *coord)
{
	int	i;
	int	j;

	flood_fill(map, coord[0], coord[1]);
	if (map[coord[2]][coord[3]] != 'F')
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_valid_map(char **map, int *error)
{
	int	coord[4];

	if (my_memlen(&map[0]) > 10 && *error == 0)
		*error = 7;
	spawn_exit_coord(map, coord);
	if (!is_valid_path(map, coord))
		*error = 4;
	if (*error != 0)
		return (0);
	return (1);
}

char	**create_map(char *filename, int *error)
{
	char	**map;

	map = read_from_file(filename, error);
	if (!map)
		return (NULL);
	if (!item_count(map, error))
	{
		if (*error == 0 || *error == 6 || *error == 7)
			*error = 4;
		free_map(map);
		return (NULL);
	}
	if (is_valid_map(map, error) && *error == 0)
		return (map);
	free_map(map);
	return (NULL);
}
