/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:15:29 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/17 01:53:48 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**copy_map(t_data *data)
{
	char	**temp_map;
	int		i;

	i = 0;
	temp_map = malloc(sizeof(char *) * (data->map->height + 1));
	while (i < data->map->height)
	{
		temp_map[i] = ft_strdup(data->map->data[i]);
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
}

void	free_temp_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
