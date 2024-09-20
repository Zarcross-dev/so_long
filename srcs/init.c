/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:00:37 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/18 20:47:23 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_game(t_data *data)
{
	data->game = malloc(sizeof(t_game));
	if (!data->game)
		return (0);
	data->game->x = (data->map->width - 1) * 16;
	data->game->y = data->map->height * 16;
	data->game->mlx = mlx_init();
	if (!data->game->mlx)
		return (0);
	data->game->window = mlx_new_window(data->game->mlx, data->game->x, \
										data->game->y, "Mein Kraft");
	if (!data->game->window)
		return (0);
	return (1);
}

int	init_map(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (0);
	if (!map_size(map_open(data, data->name), data))
		merror(data, "Error while getting map size.\n");
	data->map->data = map_loader(map_open(data, data->name), data);
	if (!valid_map(data))
		return (0);
	if (!data->map->data)
		return (0);
	data->map->coins = get_coins(data);
	data->map->collected = 0;
	if (!init_coins(data))
		return (0);
	if (data->map->coins == data->map->collected)
		data->map->exit = 1;
	else
		data->map->exit = 0;
	return (1);
}

int	init_coins(t_data *data)
{
	data->coins = malloc(sizeof(t_coins));
	if (!data->coins)
		return (0);
	data->coins->x = malloc(sizeof(int) * (data->map->coins + 1));
	if (!data->coins->x)
		return (0);
	data->coins->y = malloc(sizeof(int) * (data->map->coins + 1));
	if (!data->coins->y)
		return (0);
	if (!get_exit_pos(data))
		return (0);
	if (!get_coins_pos(data))
		return (0);
	//print coins pos
	int i = 0;
	while (i < data->map->coins + 1)
	{
		ft_printf("coin %d: %d %d\n", i, data->coins->x[i], data->coins->y[i]);
		i++;
	}
	return (1);
}

int	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		return (0);
	data->player->x = get_player_pos(data->map->data, 'x');
	data->player->y = get_player_pos(data->map->data, 'y');
	data->player->frame = 0;
	data->player->moves = 0;
	return (1);
}

void	init(t_data *data)
{
	if (!init_map(data))
		merror(data, "Error while initializing map.\n");
	if (!init_player(data))
		merror(data, "Error while initializing player.\n");
	if (!init_game(data))
		merror(data, "Error while initializing game.\n");
	if (!verify_map(data))
		merror(data, "Player can't access all coins or exit.\n");
	if (!init_assets(data))
		merror(data, "Error while loading assets.\n");
}
