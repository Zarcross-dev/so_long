/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:50:02 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/18 01:46:28 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	update_position(t_data *data, int dy, int dx, int frame)
{
	if (data->player->y == data->coins->x[0] && \
		data->player->x == data->coins->y[0])
		data->map->data[data->player->y][data->player->x] = 'E';
	else
		data->map->data[data->player->y][data->player->x] = '0';
	data->player->y += dy;
	data->player->x += dx;
	data->map->data[data->player->y][data->player->x] = 'P';
	data->player->moves++;
	update_frame(data, frame);
	ft_printf("Moves: %d\n", data->player->moves);
}

void	collect_coin(t_data *data, int dy, int dx, int frame)
{
	update_position(data, dy, dx, frame);
	data->map->collected++;
	if (data->map->coins == data->map->collected)
	{
		data->map->exit = 1;
		ft_printf("You collected all the coins\n");
	}
}

void	check_exit(t_data *data, int dy, int dx, int frame)
{
	update_position(data, dy, dx, frame);
	if (data->map->exit)
	{
		ft_printf("You won!\n");
		clean_exit(data);
	}
}

void	update_frame(t_data *data, int frame)
{
	if (frame == 0)
	{
		if (data->player->frame == 0)
			data->player->frame = 1;
		else if (data->player->frame == 1)
			data->player->frame = 2;
		else if (data->player->frame == 2)
			data->player->frame = 3;
		else if (data->player->frame == 3)
			data->player->frame = 0;
	}
	else if (frame == 1)
	{
		if (data->player->frame == 0)
			data->player->frame = 3;
		else if (data->player->frame == 1)
			data->player->frame = 0;
		else if (data->player->frame == 2)
			data->player->frame = 1;
		else if (data->player->frame == 3)
			data->player->frame = 2;
	}
}
