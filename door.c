/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:25:21 by esellier          #+#    #+#             */
/*   Updated: 2025/02/03 19:51:03 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	do_door(t_data *data, int x, int y)
{
	if (data->map->matrix[y - 1][x] == 'D' && data->player.angle <= 100
		&& data->player.angle >= 80 && data->map->door == -1)
	{
		data->map->door = 0;
		//do the sprite to open the door
		gettimeofday(&data->timer, NULL);
		// timer de 5sec (Gettime of the day) surement dans le main 
		// et se referme avec un sprite reverse
		data->map->door = -1;
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
			// et se referme avec un sprite reverse
			data->map->door = -1;
		}
	}
}