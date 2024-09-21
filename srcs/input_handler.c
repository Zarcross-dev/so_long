/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:00:37 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/19 17:01:31 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		clean_exit(data);
	else if (keycode == 65362 || keycode == 119)
		moves_handler(data, 'U');
	else if (keycode == 65364 || keycode == 115)
		moves_handler(data, 'D');
	else if (keycode == 65361 || keycode == 97)
		moves_handler(data, 'L');
	else if (keycode == 65363 || keycode == 100)
		moves_handler(data, 'R');
	return (0);
}
