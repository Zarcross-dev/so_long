/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 03:33:39 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/21 03:35:26 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*safe_itoa(t_data *data, int n)
{
	char	*str;
	str = ft_itoa(n);
	if (!str)
		merror(data, "Malloc failed\n");
	return (str);
}