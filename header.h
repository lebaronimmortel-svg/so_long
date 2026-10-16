/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:43:58 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:10:38 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_data
{
	void				*mlx;
	void				*win;
	char				**map;
	struct s_val		*val;
	struct s_xpm		*xpm;
}	t_data;

struct s_val
{
	int		play_view;
	int		play_y;
	int		play_x;
	int		width;
	int		height;
	int		coll_cnt;
	int		coll_tot;
	int		moves_cnt;
	int		map_width;
	int		map_height;
	int		loop;
};

struct s_xpm
{
	void	*play_right;
	void	*play_left;
	void	*play_up;
	void	*play_down;
	void	*grass;
	void	*barrier;
	void	*exit;
	void	*coll;
};

/////// PARSING ////////

char	*gnl(int fd);
int		my_memlen(char **map);
size_t	ft_strlen(const char *s);
int		my_strchr(char *str, char c);
int		is_valid_name(char *filename);
int		is_valid_border_line(char *str);
int		item_count(char **map, int *error);
char	**ft_split(char const	*s, char c);
void	flood_fill(char **map, int p_y, int p_x);
int		error_check2(int fd, char *str2, int *error);
int		add_tail(char **str0, char **str1, char **str2);
char	*ft_strjoin(char const *str1, char const *str2);

/////// MAP ////////

void	free_map(char **map);
char	**create_map(char *filename, int *error);
void	spawn_exit_coord(char **map, int *coord);

/////// INITIALIZE ////////

int		initialize(t_data *data);
int		initialize_all(t_data *data);
void	initialize_map(t_data *data);
void	initialize_formal_values(t_data *data);

/////// DISPLAY ////////

int		core_fun(t_data *data);
void	ft_putstr_fd(char *s, int fd);
void	move_player_up(t_data *data);
void	move_player_left(t_data *data);
void	move_player_down(t_data *data);
void	move_player_right(t_data *data);
int		key_hook(int keycode, t_data *data);
int		close_program(t_data *data, int ind);
void	put_image_play(t_data *data, int ind);
void	put_image(t_data *data, int x, int y);
void	display_player_position(t_data *data);

#endif
