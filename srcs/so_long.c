/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:00:40 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/19 18:08:29 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	valid_args(int ac, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	if (ac == 2 && ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		return (1);
	return (0);
}

int	close_game(t_data *data)
{
	clean_exit(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		merror(data, "Malloc failed\n");
	if (ac == 2)
	{
		if (!valid_args(ac, av))
			merror(data, "Invalid map\n");
		data->name = av[1];
		init(data);
		mlx_hook(data->game->window, 2, 1L << 0, key_hook, data);
		mlx_hook(data->game->window, 17, 1, close_game, data);
		mlx_expose_hook(data->game->window, draw_map, data);
		draw_map(data);
		mlx_loop(data->game->mlx);
	}
	else
		merror(data, "Usage: ./so_long [maps/map.ber]\n");
	return (0);
}
