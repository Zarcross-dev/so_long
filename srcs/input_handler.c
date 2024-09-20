/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:00:37 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/17 01:50:48 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		clean_exit(data);
	else if (keycode == 65362)
		moves_handler(data, 'U');
	else if (keycode == 65364)
		moves_handler(data, 'D');
	else if (keycode == 65361)
		moves_handler(data, 'L');
	else if (keycode == 65363)
		moves_handler(data, 'R');
	return (0);
}
