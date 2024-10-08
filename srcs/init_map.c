/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:23:57 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/23 05:09:21 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_p_e(t_data *data)
{
	int	x;
	int	y;
	int	player;
	int	exit;

	x = 0;
	y = 0;
	player = 0;
	exit = 0;
	while (data->map->data[x])
	{
		while (data->map->data[x][y])
		{
			if (data->map->data[x][y] == 'P')
				player++;
			if (data->map->data[x][y] == 'E')
				exit++;
			y++;
		}
		y = 0;
		x++;
	}
	if (player != 1 || exit != 1)
		return (0);
	return (1);
}

int	check_rectangle(t_data *data)
{
	int	x;
	int	width;

	x = 0;
	width = ft_strlen(data->map->data[0]);
	while (data->map->data[x])
	{
		if (ft_strlen(data->map->data[x]) != (size_t)width)
			return (0);
		x++;
	}
	return (1);
}

int	check_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map->height)
	{
		y = 0;
		while (y < data->map->width - 1)
		{
			if (data->map->data[0][y] != '1')
				return (0);
			if (data->map->data[x][0] != '1')
				return (0);
			if (data->map->data[x][data->map->width - 2] != '1')
				return (0);
			if (data->map->data[data->map->height - 1][y] != '1')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	check_chars(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map->data[x])
	{
		y = 0;
		while (data->map->data[x][y])
		{
			if (data->map->data[x][y] != '0' && data->map->data[x][y] != '1' \
				&& data->map->data[x][y] != 'C' && data->map->data[x][y] != 'E' \
				&& data->map->data[x][y] != 'P' && data->map->data[x][y] != 'M' \
				&& data->map->data[x][y] != '\n' \
				&& data->map->data[x][y] != '\0')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	valid_map(t_data *data)
{
	if (!check_p_e(data))
		merror(data, "Error: Map should have 1 player and 1 exit.\n");
	if (!check_rectangle(data))
		merror(data, "Error: Map is not rectangle.\n");
	if (!check_walls(data))
		merror(data, "Error: Map is not closed by walls.\n");
	if (!check_chars(data))
		merror(data, "Error: Map contains invalid characters.\n");
	return (1);
}
