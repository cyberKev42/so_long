/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:16:49 by kbrauer           #+#    #+#             */
/*   Updated: 2023/11/18 17:31:20 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dataset1(t_data *data)
{
	data->player = mlx_xpm_file_to_image(data->mlx,
			"sprites/player/ufo.xpm", &data->img_width, &data->img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"sprites/wall/ast.xpm", &data->img_width, &data->img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			"sprites/exit/exit.xpm", &data->img_width, &data->img_height);
	data->empty = mlx_xpm_file_to_image(data->mlx,
			"sprites/empty/emp.xpm", &data->img_width, &data->img_height);
	data->col = mlx_xpm_file_to_image(data->mlx,
			"sprites/col/planet.xpm", &data->img_width, &data->img_height);
}

void	dataset2(t_data *data)
{
	data->player = mlx_xpm_file_to_image(data->mlx,
			"sprites/player/ufo2.xpm", &data->img_width, &data->img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"sprites/wall/ast2.xpm", &data->img_width, &data->img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			"sprites/exit/exit2.xpm", &data->img_width, &data->img_height);
	data->empty = mlx_xpm_file_to_image(data->mlx,
			"sprites/empty/emp2.xpm", &data->img_width, &data->img_height);
	data->col = mlx_xpm_file_to_image(data->mlx,
			"sprites/col/planet2.xpm", &data->img_width, &data->img_height);
}

int	load_img(t_data *data)
{
	if (data->xpm % 2 == 0)
		dataset1(data);
	if (data->xpm % 2 == 1)
		dataset2(data);
	if (!data->player || !data->wall || !data->exit
		|| !data->empty || !data->col)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free_all(data);
		ft_printf("Error\nFailed to load all sprites!\n");
		exit (0);
	}
	return (0);
}

int	put_img(t_data *data, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall,
			x * 50, y * 50);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->empty,
			x * 50, y * 50);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player,
			x * 50, y * 50);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->col,
			x * 50, y * 50);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit,
			x * 50, y * 50);
	return (0);
}

int	put_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			put_img(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
	display_stats(data);
	return (0);
}
