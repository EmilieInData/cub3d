/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:25:21 by esellier          #+#    #+#             */
/*   Updated: 2025/02/05 17:23:58 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_sprite_door(t_data *data)
{
	data->sprite[0] = create_struct_files(data, FILES_NAME);
	data->sprite[1] = create_struct_files(data, FILES_NAME);
	data->sprite[2] = create_struct_files(data, FILES_NAME);
	data->sprite[3] = create_struct_files(data, FILES_NAME);
	data->sprite[4] = create_struct_files(data, FILES_NAME);
	data->sprite[5] = create_struct_files(data, FILES_NAME);
	data->sprite[6] = create_struct_files(data, FILES_NAME);
	data->sprite[7] = create_struct_files(data, FILES_NAME);
	data->sprite[8] = create_struct_files(data, FILES_NAME);
	data->sprite[9] = create_struct_files(data, FILES_NAME);
}

void	do_sprite_door(t_data *data)
{
	if (data->count >= PICS)
		return ;
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->image->img_add,
		0, 0);
}

void	do_door(t_data *data, int x, int y)
{
	if (data->map->matrix[y - 1][x] == 'D' && data->player.angle <= 100
		&& data->player.angle >= 80 && data->map->door == -1)
	{
		do_sprite_door(data);
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