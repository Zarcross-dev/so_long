/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:51:28 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/18 00:43:19 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	moves_handler(t_data *data, char direction)
{
	if (direction == 'U')
		move_up(data);
	else if (direction == 'D')
		move_down(data);
	else if (direction == 'L')
		move_left(data);
	else if (direction == 'R')
		move_right(data);
	draw_map(data);
}

void	move_up(t_data *data)
{
	if (data->map->data[data->player->y - 1][data->player->x] == '0')
		update_position(data, -1, 0, 0);
	else if (data->map->data[data->player->y - 1][data->player->x] == 'C')
		collect_coin(data, -1, 0, 0);
	else if (data->map->data[data->player->y - 1][data->player->x] == 'E')
		check_exit(data, -1, 0, 0);
	else if (data->map->data[data->player->y - 1][data->player->x] == 'M')
	{
		ft_printf("You lost!\n");
		clean_exit(data);
	}
}

void	move_down(t_data *data)
{
	if (data->map->data[data->player->y + 1][data->player->x] == '0')
		update_position(data, 1, 0, 1);
	else if (data->map->data[data->player->y + 1][data->player->x] == 'C')
		collect_coin(data, 1, 0, 1);
	else if (data->map->data[data->player->y + 1][data->player->x] == 'E')
		check_exit(data, 1, 0, 1);
	else if (data->map->data[data->player->y + 1][data->player->x] == 'M')
	{
		ft_printf("You lost!\n");
		clean_exit(data);
	}
}

void	move_left(t_data *data)
{
	if (data->map->data[data->player->y][data->player->x - 1] == '0')
		update_position(data, 0, -1, 1);
	else if (data->map->data[data->player->y][data->player->x - 1] == 'C')
		collect_coin(data, 0, -1, 1);
	else if (data->map->data[data->player->y][data->player->x - 1] == 'E')
		check_exit(data, 0, -1, 1);
	else if (data->map->data[data->player->y][data->player->x - 1] == 'M')
	{
		ft_printf("You lost!\n");
		clean_exit(data);
	}
}

void	move_right(t_data *data)
{
	if (data->map->data[data->player->y][data->player->x + 1] == '0')
		update_position(data, 0, 1, 0);
	else if (data->map->data[data->player->y][data->player->x + 1] == 'C')
		collect_coin(data, 0, 1, 0);
	else if (data->map->data[data->player->y][data->player->x + 1] == 'E')
		check_exit(data, 0, 1, 0);
	else if (data->map->data[data->player->y][data->player->x + 1] == 'M')
	{
		ft_printf("You lost!\n");
		clean_exit(data);
	}
}
