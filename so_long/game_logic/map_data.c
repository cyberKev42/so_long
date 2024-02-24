/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:03:48 by kbrauer           #+#    #+#             */
/*   Updated: 2023/11/23 17:42:12 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_width(t_data *data)
{
	int	x;
	int	y;
	int	length;

	x = 0;
	if (!data->map)
		return (1);
	while (data->map[0][x] && data->map[0][x] != '\n')
		x++;
	length = x;
	data->map_width = length;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] && data->map[y][x] != '\n')
			x++;
		if (x != length)
			return (1);
		y++;
	}
	return (0);
}

void	set_pos(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'P')
	{
		data->p_pos[0] = x;
		data->p_pos[1] = y;
		data->players++;
	}
	if (data->map[y][x] == 'C')
		data->collectibles++;
	if (data->map[y][x] == 'E')
	{
		data->e_pos[0] = x;
		data->e_pos[1] = y;
		data->exits++;
	}
}

void	positioning(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			set_pos(data, x, y);
			x++;
		}
		y++;
	}
}

int	add_line(t_data *data, char **line)
{
	int		i;
	char	**map_tmp;

	data->map_height++;
	i = 0;
	map_tmp = (char **) malloc (sizeof(char *) * (data->map_height + 1));
	if (!map_tmp)
		return (1);
	while (i < data->map_height - 1)
	{
		map_tmp[i] = data->map[i];
		i++;
	}
	map_tmp[i] = *line;
	map_tmp[data->map_height] = NULL;
	if (data->map_height > 1)
		free(data->map);
	data->map = map_tmp;
	return (0);
}

int	read_map(char *map, t_data *data)
{
	int		fd;
	char	*line;

	line = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (1);
	if (!get_next_line(fd, &line))
		return (close(fd), 1);
	while (line)
	{
		if (add_line(data, &line))
			break ;
		if (!get_next_line(fd, &line))
			break ;
	}
	if (line)
		free(line);
	close(fd);
	return (map_width(data));
}
