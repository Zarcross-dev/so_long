/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 01:27:14 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/17 01:53:36 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_player_pos(char **map, char c)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				if (c == 'x')
					return (y);
				if (c == 'y')
					return (x);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}
