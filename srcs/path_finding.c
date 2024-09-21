/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:38:51 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/19 17:01:24 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_map(char **temp_map)
{
	int	i;

	i = 0;
	while (temp_map[i])
	{
		ft_printf("%s", temp_map[i]);
		i++;
	}
	ft_printf("\n");
}

int	dfs(char **map, t_point size, t_point start, t_point end)
{
	if (start.x < 0 || start.y < 0 || start.x >= size.x || start.y >= size.y)
		return (0);
	if (map[start.y][start.x] == '1' || map[start.y][start.x] == 'X' \
		|| map[start.y][start.x] == 'M')
		return (0);
	if (start.x == end.x && start.y == end.y)
		return (1);
	map[start.y][start.x] = 'X';
	if (dfs(map, size, (t_point){start.x + 1, start.y}, end) || \
		dfs(map, size, (t_point){start.x - 1, start.y}, end) || \
		dfs(map, size, (t_point){start.x, start.y + 1}, end) || \
		dfs(map, size, (t_point){start.x, start.y - 1}, end))
		return (1);
	return (0);
}

int	verify_map(t_data *data)
{
	char	**temp_map;
	int		i;
	t_point	player;
	t_point	size;

	i = 0;
	player = (t_point){data->player->x, data->player->y};
	size = (t_point){data->map->width, data->map->height};
	while (i < data->map->coins + 1)
	{
		temp_map = copy_map(data);
		if (!temp_map)
			return (0);
		if (!dfs(temp_map, size, player, (t_point){data->coins->x[i], \
			data->coins->y[i]}))
		{
			free_temp_map(temp_map);
			return (0);
		}
		free_temp_map(temp_map);
		i++;
	}
	return (1);
}
