/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:06:54 by kbrauer           #+#    #+#             */
/*   Updated: 2023/11/23 17:41:16 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
//compile with: -lmlx -lXext -lm

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "get_next_line_bonus.h"
# include "ft_printf.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*empty;
	void	*wall;
	void	*col;
	void	*exit;
	void	*player;
	char	**map;
	char	**map_tmp;
	int		p_pos[2];
	int		players;
	int		e_pos[2];
	int		map_height;
	int		map_width;
	int		collectibles;
	int		col_gathered;
	int		col_error;
	int		exit_possible;
	int		exits;
	int		xpm;
	int		img_width;
	int		img_height;
	int		moves;
	char	*moves_str;
	char	*col_str;
	char	*col_gat_str;
	int		winner;
}	t_data;

int		check_error(t_data *data);
int		check_walls(t_data *data);
int		put_img(t_data *data, char c, int x, int y);
int		load_img(t_data *data);
int		read_map(char *map, t_data *data);
int		add_line(t_data *data, char **line);
int		put_map(t_data *data);
int		left_right(t_data *data, int key);
int		up_down(t_data *data, int key);
int		move_count(t_data *data);
int		map_width(t_data *data);
char	*ft_itoa(int n);
char	*ft_strdup(char *s);
void	put_exit1(t_data *data, int key, int x, int y);
void	put_exit2(t_data *data, int key, int x, int y);
void	set_pos(t_data *data, int x, int y);
void	display_stats(t_data *data);
void	init(t_data *data);
void	free_all(t_data *data);
void	free_img(t_data *data);
void	put_string(t_data *data, int y);
void	free_map_cpy(char **ptr, int i);
void	free_map(t_data *data);
void	start_error_checking(t_data *data);
void	dataset1(t_data *data);
void	dataset2(t_data *data);
void	positioning(t_data *data);

#endif
