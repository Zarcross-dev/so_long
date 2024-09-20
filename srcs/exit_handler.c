/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:00:38 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/17 04:01:51 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_path(t_data *data)
{
	if (data->path->placeholder)
		mlx_destroy_image(data->game->mlx, data->path->placeholder);
	if (data->path->background)
		mlx_destroy_image(data->game->mlx, data->path->background);
	if (data->path->wall)
		mlx_destroy_image(data->game->mlx, data->path->wall);
	if (data->path->player)
	{
		mlx_destroy_image(data->game->mlx, data->path->player[0]);
		mlx_destroy_image(data->game->mlx, data->path->player[1]);
		mlx_destroy_image(data->game->mlx, data->path->player[2]);
		mlx_destroy_image(data->game->mlx, data->path->player[3]);
		free(data->path->player);
	}
	if (data->path->collectible)
		mlx_destroy_image(data->game->mlx, data->path->collectible);
	if (data->path->enemy)
		mlx_destroy_image(data->game->mlx, data->path->enemy);
	if (data->path->exit)
		mlx_destroy_image(data->game->mlx, data->path->exit);
	if (data->path)
		free(data->path);
}

void	free_game(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game)
		free(game);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->data[i])
			free(map->data[i]);
		i++;
	}
	if (map->data)
		free(map->data);
	if (map)
		free(map);
}

void	free_coins(t_coins *coins)
{
	if (coins->x)
		free(coins->x);
	if (coins->y)
		free(coins->y);
	if (coins)
		free(coins);
}

int	free_structs(t_data *data)
{
	if (data->path)
		free_path(data);
	if (data->game)
		free_game(data->game);
	if (data->map)
		free_map(data->map);
	if (data->player)
		free(data->player);
	if (data->coins)
		free_coins(data->coins);
	if (data)
		free(data);
	return (0);
}
