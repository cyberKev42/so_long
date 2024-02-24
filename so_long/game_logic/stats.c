/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:14:49 by kbrauer           #+#    #+#             */
/*   Updated: 2023/11/18 17:44:26 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_stats(t_data *data)
{
	int	x;
	int	y;

	x = data->map_width;
	y = data->map_height;
	data->col_str = ft_itoa(data->collectibles);
	if (!data->col_str)
		data->col_str = "empty";
	data->col_gat_str = ft_itoa(data->col_gathered);
	if (!data->col_gat_str)
		data->col_gat_str = "empty";
	data->moves_str = ft_itoa(data->moves);
	if (!data->moves_str)
		data->moves_str = "empty";
	put_string(data, y);
	if (data->winner)
	{
		mlx_string_put(data->mlx, data->win, (x * 50) / 2 - 100,
			(y * 50) / 2, 0xFF0000, "Winner, Winner, Chicken Dinner!");
	}
	free(data->col_str);
	free(data->col_gat_str);
	free(data->moves_str);
}

void	put_string(t_data *data, int y)
{
	mlx_string_put(data->mlx, data->win, 25, (y * 50) - 30, 0xFFFFFF,
		"Planets invaded:");
	mlx_string_put(data->mlx, data->win, 130, (y * 50) - 30, 0xFFFFFF,
		data->col_gat_str);
	mlx_string_put(data->mlx, data->win, 145, (y * 50) - 30, 0xFFFFFF, "/");
	mlx_string_put(data->mlx, data->win, 155, (y * 50) - 30, 0xFFFFFF,
		data->col_str);
	mlx_string_put(data->mlx, data->win, 25, (y * 50) - 10, 0xFFFFFF,
		"Moves:");
	mlx_string_put(data->mlx, data->win, 65, (y * 50) - 10, 0xFFFFFF,
		data->moves_str);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i])
		i++;
	ptr = (char *) malloc (i * sizeof(char) + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = s[i];
	return (ptr);
}
