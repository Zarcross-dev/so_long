/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:50:45 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/23 04:52:48 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	draw_asset(t_data *data, char asset, char *path)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < (data->map->width - 1))
		{
			i = y * 16;
			j = x * 16;
			if (data->map->data[y][x] == asset)
				mlx_put_image_to_window(data->game->mlx, \
				data->game->window, path, j, i);
			x++;
		}
		y++;
	}
	return (1);
}

void	put_string(t_data *data, char *str, int x, int y)
{
	mlx_string_put(data->game->mlx, data->game->window, x, y, 0x00FFFFFF, \
					str);
}

void	draw_hud(t_data *data)
{
	char	*value;
	char	*collected;
	char	*coins;

	mlx_set_font(data->game->mlx, data->game->window, "8x13bold");
	value = safe_itoa(data, data->player->moves);
	collected = safe_itoa(data, data->map->collected);
	coins = safe_itoa(data, data->map->coins);
	put_string(data, "Moves: ", 10, 20);
	put_string(data, value, 60, 20);
	if (data->map->exit)
		put_string(data, "You collected all coins!", 10, 40);
	else
	{
		put_string(data, "Coins: ", 10, 40);
		put_string(data, collected, 60, 40);
		put_string(data, "/", 80, 40);
		put_string(data, coins, 90, 40);
	}
	free(collected);
	free(coins);
	free(value);
}

int	draw_map(t_data *data)
{
	draw_asset(data, '0', data->path->background);
	draw_asset(data, '1', data->path->wall);
	draw_asset(data, 'C', data->path->collectible);
	draw_asset(data, 'P', data->path->player[data->player->frame]);
	draw_asset(data, 'M', data->path->enemy);
	if (data->map->exit)
		draw_asset(data, 'E', data->path->exit);
	else
		draw_asset(data, 'E', data->path->background);
	draw_hud(data);
	return (1);
}
