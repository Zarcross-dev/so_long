/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:40:07 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/18 15:23:38 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_coins(t_data *data)
{
	int	coins;
	int	x;
	int	y;

	x = 0;
	y = 0;
	coins = 0;
	while (data->map->data[x])
	{
		while (data->map->data[x][y])
		{
			if (data->map->data[x][y] == 'C')
				coins++;
			y++;
		}
		y = 0;
		x++;
	}
	return (coins);
}

int	get_exit_pos(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map->data[y])
	{
		while (data->map->data[y][x])
		{
			if (data->map->data[y][x] == 'E')
			{
				data->coins->x[0] = x;
				data->coins->y[0] = y;
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	get_coins_pos(t_data *data)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 1;
	while (data->map->data[y])
	{
		while (data->map->data[y][x])
		{
			if (data->map->data[y][x] == 'C')
			{
				data->coins->x[i] = x;
				data->coins->y[i] = y;
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
