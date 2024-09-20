/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:00:30 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/17 02:59:29 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_open(t_data *data, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		merror(data, "Error while opening map file.\n");
	return (fd);
}

char	**map_loader(int buffer, t_data *data)
{
	char	*line;
	char	**map_data;
	int		i;

	i = 0;
	map_data = malloc(sizeof(char *) * (data->map->height + 1));
	if (!map_data)
		merror(data, "Error while allocating memory for map data.\n");
	line = get_next_line(buffer);
	while (line)
	{
		map_data[i] = ft_strdup(line);
		if (!map_data[i])
			merror(data, "Error while allocating memory for map data.\n");
		free(line);
		i++;
		line = get_next_line(buffer);
	}
	free(line);
	close(buffer);
	map_data[i] = NULL;
	return (map_data);
}

int	map_size(int fd, t_data *data)
{
	char	*line;

	data->map->height = 0;
	line = get_next_line(fd);
	if (!line)
		merror(data, "Error while reading map file.\n");
	data->map->width = ft_strlen(line);
	while (line)
	{
		free(line);
		data->map->height++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (1);
}
