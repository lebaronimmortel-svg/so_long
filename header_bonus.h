/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:43:58 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:10:38 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

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
	int		mob_pos;
	int		mob_cnt;
	int		mob_cnt_max;
	int		speed;
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
	void	*walk_right[9];
	void	*walk_left[9];
	void	*up_top[2];
	void	*up_bot[2];
	void	*down_top[2];
	void	*down_bot[2];
	void	*digit_img[10];
	void	*grass;
	void	*barrier;
	void	*mob_left;
	void	*mob_right;
	void	*panel;
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
char	*ft_strjoin(char const *str1, char const *str2);
int		add_tail(char **str0, char **str1, char **str2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/////// MAP ////////

void	free_map(char **map);
void	enemy_spawn(t_data *data);
char	**create_map(char *filename, int *error);
void	spawn_exit_coord(char **map, int *coord);

/////// INITIALIZE ////////

int		initialize(t_data *data);
int		initialize_all(t_data *data);
void	initialize_map(t_data *data);
void	initialize_formal_values(t_data *data);

/////// DISPLAY ////////

int		core_fun(t_data *data);
void	display_map(t_data *data);
void	display_enemy(t_data *data);
void	ft_putstr_fd(char *s, int fd);
void	move_player_up(t_data *data);
void	move_player_down(t_data *data);
void	move_player_left(t_data *data);
void	move_player_right(t_data *data);
void	update_player_pos(t_data *data);
void	display_moves_count(t_data *data);
int		key_hook(int keycode, t_data *data);
int		close_program(t_data *data, int ind);
void	put_image_play(t_data *data, int ind);
void	display_player_position(t_data *data);
void	display_square(t_data *data, int y, int x);
void	put_image_walk(t_data *data, int i, int pos);
int		update_enemy_pos(t_data *data, int y, int x);
void	put_image(t_data *data, int x, int y, int ind);
void	put_image_up(t_data *data, int index, int pos, int y);
void	put_image_down(t_data *data, int index, int pos, int y);

#endif
