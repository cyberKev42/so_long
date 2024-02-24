/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:11:03 by kbrauer           #+#    #+#             */
/*   Updated: 2023/11/23 17:42:18 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->map_width - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < data->map_width)
	{
		if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	free_map_cpy(char **ptr, int i)
{
	int	n;

	n = 0;
	while (n <= i)
	{
		free(ptr[n]);
		n++;
	}
	free(ptr);
}

int	copy_map(t_data *data)
{
	int		y;

	data->map_tmp = (char **) malloc (sizeof(char *) * (data->map_height + 1));
	if (!data->map_tmp)
		return (1);
	y = 0;
	while (data->map[y])
	{
		data->map_tmp[y] = ft_strdup(data->map[y]);
		if (!data->map_tmp[y])
			return (free_map_cpy(data->map_tmp, y), 1);
		y++;
	}
	data->map_tmp[y] = data->map[y];
	return (0);
}

int	check_path(t_data *data, int x, int y)
{
	if (!data->map_tmp || !data->map_tmp[y] || !data->map_tmp[y][x]
		|| data->exit_possible > 1)
		return (1);
	if (data->map_tmp[y][x] == 'C')
		data->col_error++;
	if (data->map_tmp[y][x] == 'E')
		data->exit_possible++;
	data->map_tmp[y][x] = '1';
	if (data->map_tmp[y][x - 1] == '0' || data->map_tmp[y][x - 1] == 'C'
		|| data->map_tmp[y][x - 1] == 'E')
		check_path(data, x - 1, y);
	if (data->map_tmp[y - 1][x] == '0' || data->map_tmp[y - 1][x] == 'C'
		|| data->map_tmp[y - 1][x] == 'E')
		check_path(data, x, y - 1);
	if (data->map_tmp[y][x + 1] == '0' || data->map_tmp[y][x + 1] == 'C'
		|| data->map_tmp[y][x + 1] == 'E')
		check_path(data, x + 1, y);
	if (data->map_tmp[y + 1][x] == '0' || data->map_tmp[y + 1][x] == 'C'
		|| data->map_tmp[y + 1][x] == 'E')
		check_path(data, x, y + 1);
	return (0);
}

int	check_error(t_data *data)
{
	if (!data->map)
		return (1);
	positioning(data);
	if (data->players != 1 || data->exits != 1 || data->collectibles == 0
		|| check_walls(data))
		return (1);
	if (copy_map(data))
		return (1);
	if (!data->map_tmp || !data->p_pos[0] || !data->p_pos[1])
		return (free_map_cpy(data->map_tmp, data->map_height), 1);
	check_path(data, data->p_pos[0], data->p_pos[1]);
	if (data->col_error != data->collectibles || data->exit_possible != 1)
		return (free_map_cpy(data->map_tmp, data->map_height), 1);
	free_map_cpy(data->map_tmp, data->map_height);
	return (0);
}
