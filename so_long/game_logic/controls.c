/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:14:36 by kbrauer           #+#    #+#             */
/*   Updated: 2023/11/18 17:40:26 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_count(t_data *data)
{
	data->moves++;
	if (data->map[data->p_pos[1]][data->p_pos[0]] == 'C')
		data->col_gathered++;
	if (data->map[data->p_pos[1]][data->p_pos[0]] == 'E')
	{
		if (data->collectibles == data->col_gathered)
		{
			data->winner = 1;
			ft_printf("Winner, Winner, Chicken Dinner!\n");
			return (1);
		}
		ft_printf("Invade more planets\n");
		return (1);
	}
	return (0);
}

void	put_exit1(t_data *data, int key, int x, int y)
{
	int	x_e;
	int	y_e;

	x_e = data->e_pos[0];
	y_e = data->e_pos[1];
	if (key == 'a' || key == 65361)
	{
		if ((x + 1 == x_e) && (y == y_e))
			data->map[y][x + 1] = 'E';
		else
			data->map[y][x + 1] = '0';
	}
	if (key == 'd' || key == 65363)
	{
		if ((x - 1 == x_e) && (y == y_e))
			data->map[y][x - 1] = 'E';
		else
			data->map[y][x - 1] = '0';
	}
}

void	put_exit2(t_data *data, int key, int x, int y)
{
	int	x_e;
	int	y_e;

	x_e = data->e_pos[0];
	y_e = data->e_pos[1];
	if (key == 'w' || key == 65362)
	{
		if ((y + 1 == y_e) && (x == x_e))
			data->map[y + 1][x] = 'E';
		else
			data->map[y + 1][x] = '0';
	}
	if (key == 's' || key == 65364)
	{
		if ((y - 1 == y_e) && (x == x_e))
			data->map[y - 1][x] = 'E';
		else
			data->map[y - 1][x] = '0';
	}
}

int	left_right(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->p_pos[0];
	y = data->p_pos[1];
	if ((key == 'a' || key == 65361) && data->map[y][x - 1] != '1')
	{
		data->p_pos[0]--;
		x = data->p_pos[0];
		move_count(data);
		data->map[y][x] = 'P';
		put_exit1(data, key, x, y);
	}
	else if ((key == 'd' || key == 65363) && data->map[y][x + 1] != '1')
	{
		data->p_pos[0]++;
		x = data->p_pos[0];
		move_count(data);
		data->map[y][x] = 'P';
		put_exit1(data, key, x, y);
	}
	else
		ft_printf("Don't crash into asteroids ;)\n");
	return (0);
}

int	up_down(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->p_pos[0];
	y = data->p_pos[1];
	if ((key == 'w' || key == 65362) && data->map[y - 1][x] != '1')
	{
		data->p_pos[1]--;
		y = data->p_pos[1];
		move_count(data);
		data->map[y][x] = 'P';
		put_exit2(data, key, x, y);
	}
	else if ((key == 's' || key == 65364) && data->map[y + 1][x] != '1')
	{
		data->p_pos[1]++;
		y = data->p_pos[1];
		move_count(data);
		data->map[y][x] = 'P';
		put_exit2(data, key, x, y);
	}
	else
		ft_printf("Don't crash into asteroids ;)\n");
	return (0);
}
