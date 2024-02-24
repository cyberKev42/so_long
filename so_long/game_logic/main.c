/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:57:30 by kbrauer           #+#    #+#             */
/*   Updated: 2023/11/23 17:46:58 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free_all(data);
		exit(0);
	}
	if (keycode == 'a' || keycode == 'd' || keycode == 65361
		|| keycode == 65363)
		left_right(data, keycode);
	if (keycode == 'w' || keycode == 's' || keycode == 65362
		|| keycode == 65364)
		up_down(data, keycode);
	ft_printf("Planets invaded: %d/%d\nMoves: %d\n\n",
		data->col_gathered, data->collectibles, data->moves);
	return (0);
}

int	window_x(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_all(data);
	exit(0);
}

int	mousepress(int button, int x, int y, t_data *data)
{
	int	keycode;

	x++;
	y++;
	keycode = 0;
	if (button == 1)
		keycode = 'a';
	if (button == 4)
		keycode = 'w';
	if (button == 3)
		keycode = 'd';
	if (button == 5)
		keycode = 's';
	if (keycode == 'a' || keycode == 'd' || keycode == 65361
		|| keycode == 65363)
		left_right(data, keycode);
	if (keycode == 'w' || keycode == 's' || keycode == 65362
		|| keycode == 65364)
		up_down(data, keycode);
	ft_printf("Planets invaded: %d/%d\nMoves: %d\n\n",
		data->col_gathered, data->collectibles, data->moves);
	return (0);
}

int	handle_no_event(t_data *data)
{
	static int	i = 0;

	if ((i / 10) % 2 == 0)
		data->xpm = 0;
	else
		data->xpm = 1;
	load_img(data);
	put_map(data);
	i++;
	usleep(10000);
	free_img(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Error\nInvalid number of arguments.\n"), 0);
	init(&data);
	if (read_map(argv[1], &data))
	{
		ft_printf("Error\nProblem reading map!\n");
		mlx_destroy_display(data.mlx);
		free_all(&data);
		return (0);
	}
	start_error_checking(&data);
	data.win = mlx_new_window(data.mlx, data.map_width * 50,
			data.map_height * 50, "so_long");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		return (free_all(&data), 0);
	}
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &window_x, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &keypress, &data);
	mlx_hook(data.win, ButtonPress, ButtonPressMask, &mousepress, &data);
	mlx_loop_hook(data.mlx, &handle_no_event, &data);
	mlx_loop(data.mlx);
}
