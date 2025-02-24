/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:40:27 by esellier          #+#    #+#             */
/*   Updated: 2025/02/24 18:27:50 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	init_sprite_door(t_data *data)
// {
// 	create_struct_files(data, "./Doors/door_1.xpm", &data->doors.sprite[0]);
// 	create_struct_files(data, "./Doors/door_2.xpm", &data->doors.sprite[1]);
// 	create_struct_files(data, "./Doors/door_3.xpm", &data->doors.sprite[2]);
// 	create_struct_files(data, "./Doors/door_4.xpm", &data->doors.sprite[3]);
// 	create_struct_files(data, "./Doors/door_1.xpm", &data->doors.sprite[4]);
// }

void	do_door(t_data *data, int x, int y)
{
	//init_sprite_door(data);
	if (data->map->matrix[y - 1][x] == 'D' && data->player.angle <= 100
		&& data->player.angle >= 80 && data->doors->flag == -1)
	{
		data->doors->x = x;
		data->doors->y = y - 1;
		if (data->doors->count == PICS)
		{
			data->doors->flag = 0;
			gettimeofday(&data->timer, NULL);
			return ;
		}
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->doors->sprite[data->doors->count].img,
			data->doors->x, data->doors->y);
		data->doors->count++;
	}
}

void	close_door(t_data *data)
{
	struct timeval	new;
	double			result;

	if (data->doors->flag == 0)
	{
		gettimeofday(&new, NULL);
		result = (new.tv_sec - data->timer.tv_sec)
			+ (new.tv_usec - data->timer.tv_usec) / 1000000;
		if (result >= 5)
		{
			data->doors->flag = -1;
			if (data->doors->count == 0)
			{
				data->doors->x = -1;
				data->doors->y = -1;
				return ;
			}
			mlx_put_image_to_window(data->mlx, data->mlx_window,
				data->doors->sprite[data->doors->count - 1].img,
				data->doors->x, data->doors->y);
			data->doors->count--;
			free_doors(data, data->doors);
		}
	}
}
