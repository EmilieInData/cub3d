/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:40:27 by esellier          #+#    #+#             */
/*   Updated: 2025/02/26 18:36:07 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	do_door(t_data *data, int x, int y)
{
	printf("DOOR ENTER\n");
	 if (data->map->matrix[y - 1][x] == 'D' && data->player.angle <= 100
	 	&& data->player.angle >= 80 && data->doors->flag == -1)
	 {
	 	data->doors->x = x;
	 	data->doors->y = y;
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

int	do_sprite(t_data *data)
{
	struct timeval	now;
	double			gap;

	gettimeofday(&now, NULL);
	gap = (now.tv_sec - data->timer.tv_sec)
		+ (now.tv_usec - data->timer.tv_usec) / 1000000;
	if (gap >= 0.3)
	{
		gettimeofday(&data->timer, NULL);
		if (data->doors->count == PICS - 1)
			data->doors->count = 0;
		// if (data->door.img)
		//  	mlx_destroy_image(data->mlx, data->door.img);
		data->door = data->doors->sprite[data->doors->count];
		find_wall(data);
		data->doors->count++;
	}
	return (0);
}

// void	do_sprite(t_data *data, int x, int y)
// {
// 	printf("SPRITE ENTER\n");
// 	//trouver une porte pres du player(en commencant par l'avant)
// 	// x = round (x / 64);
// 	// y = round (y / 64); 
// 	data->doors->x = x;
//  	data->doors->y = y;
// 	//printf("X = %d, Y = %d\n", x, y);
// 	// printf("%c\n", data->map->matrix[y][x]);
// 	if (data->doors->count == PICS)
// 	{
// 		data->doors->flag = 0;
// 		gettimeofday(&data->timer, NULL);
// 		return ;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->mlx_window,
// 		data->doors->sprite[data->doors->count].img, data->doors->x,
// 		data->doors->y);
// 	data->doors->count++;
// }

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
				//free_doors(data, data->doors);
				return ;
			}
			mlx_put_image_to_window(data->mlx, data->mlx_window,
				data->doors->sprite[data->doors->count - 1].img,
				data->doors->x, data->doors->y);
			data->doors->count--;
		}
	}
}

