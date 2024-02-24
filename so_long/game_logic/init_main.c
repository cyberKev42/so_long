/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:49:06 by kbrauer           #+#    #+#             */
/*   Updated: 2023/11/23 17:43:35 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit (0);
	data->map = 0;
	data->xpm = 0;
	data->map_height = 0;
	data->collectibles = 0;
	data->players = 0;
	data->exits = 0;
	data->col_gathered = 0;
	data->col_error = 0;
	data->exit_possible = 0;
	data->moves = 0;
	data->winner = 0;
	data->player = 0;
	data->wall = 0;
	data->exit = 0;
	data->empty = 0;
	data->col = 0;
	data->img_height = 0;
	data->img_width = 0;
}

void	free_all(t_data *data)
{
	free_map(data);
	if (data->mlx)
		free(data->mlx);
}

void	free_img(t_data *data)
{
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->empty)
		mlx_destroy_image(data->mlx, data->empty);
	if (data->col)
		mlx_destroy_image(data->mlx, data->col);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
			free(data->map[i++]);
		free(data->map[i]);
		free(data->map);
	}
}

void	start_error_checking(t_data *data)
{
	if (check_error(data) || data->map_height > 19 || data->map_width > 38)
	{
		ft_printf("Error\nProblem with map configuration!\n");
		mlx_destroy_display(data->mlx);
		free_all(data);
		exit (0);
	}
}
