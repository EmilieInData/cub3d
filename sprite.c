/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:11:08 by esellier          #+#    #+#             */
/*   Updated: 2025/02/28 14:13:59 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	do_sprite(t_data *data)
{
	struct timeval	now;
	double			gap;

	gettimeofday(&now, NULL);
	gap = (now.tv_sec - data->timer.tv_sec)
		+ (now.tv_usec - data->timer.tv_usec) / 1000000;
	if (gap >= 0.1)
	{
		gettimeofday(&data->timer, NULL);
		if (data->doors->count == PICS - 1)
			data->doors->count = 0;
		data->texture_door = data->doors->sprite[data->doors->count];
		find_wall(data);
		data->doors->count++;
	}
	return (0);
}

int	do_hook(t_data *data)
{
	do_sprite(data);
	close_door(data);
	return (0);
}
