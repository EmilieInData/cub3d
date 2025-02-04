/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:25:21 by esellier          #+#    #+#             */
/*   Updated: 2025/02/04 15:48:01 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	do_door(t_data *data, int x, int y)
{
	if (data->map->matrix[y - 1][x] == 'D' && data->player.angle <= 100
		&& data->player.angle >= 80 && data->map->door == -1)
	{
		//do the sprite to open the door
		data->map->door = 0;
		gettimeofday(&data->timer, NULL);
	}
}

void	close_door(t_data *data)
{
	struct timeval	new;
	double			result;

	if (data->map->door == 0)
	{
		gettimeofday(&new, NULL);
		result = (new.tv_sec - data->timer.tv_sec)
			+ (new.tv_usec - data->timer.tv_usec) / 1000000;
		if (result >= 5)
		{
			data->map->door = -1;
			// et se referme avec un sprite reverse
		}
	}
}