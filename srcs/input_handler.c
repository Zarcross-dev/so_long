/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:00:37 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/23 14:13:56 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		clean_exit(data);
	else if (keycode == 119)
		moves_handler(data, 'U');
	else if (keycode == 115)
		moves_handler(data, 'D');
	else if (keycode == 97)
		moves_handler(data, 'L');
	else if (keycode == 100)
		moves_handler(data, 'R');
	return (0);
}
