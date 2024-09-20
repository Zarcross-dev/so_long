/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:16:42 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/17 04:04:58 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_assets_player(t_data *data)
{
	int	x;
	int	y;

	data->path->player = malloc(sizeof(void *) * 4);
	data->path->player[0] = mlx_xpm_file_to_image(data->game->mlx, \
	"./assets/player.xpm", &x, &y);
	data->path->player[1] = mlx_xpm_file_to_image(data->game->mlx, \
	"./assets/player1.xpm", &x, &y);
	data->path->player[2] = mlx_xpm_file_to_image(data->game->mlx, \
	"./assets/player2.xpm", &x, &y);
	data->path->player[3] = mlx_xpm_file_to_image(data->game->mlx, \
	"./assets/player3.xpm", &x, &y);
	return (1);
}

int	init_assets(t_data *data)
{
	int	x;
	int	y;

	data->path = malloc(sizeof(t_path));
	data->path->placeholder = mlx_xpm_file_to_image(data->game->mlx, \
													"./assets/placeholder.xpm", \
													&x, &y);
	data->path->background = mlx_xpm_file_to_image(data->game->mlx, \
	"./assets/background.xpm", &x, &y);
	data->path->wall = mlx_xpm_file_to_image(data->game->mlx, \
	"./assets/wall.xpm", &x, &y);
	data->path->collectible = mlx_xpm_file_to_image(data->game->mlx, \
	"./assets/collectible.xpm", &x, &y);
	data->path->enemy = mlx_xpm_file_to_image(data->game->mlx, \
	"./assets/enemy.xpm", &x, &y);
	data->path->exit = mlx_xpm_file_to_image(data->game->mlx, \
	"./assets/exit.xpm", &x, &y);
	init_assets_player(data);
	return (1);
}
