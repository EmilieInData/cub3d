/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:40:27 by esellier          #+#    #+#             */
/*   Updated: 2025/02/28 14:13:48 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_door_distance(double tmp_x, double tmp_y, t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	double	door_angle;

	j = -2;
	while (j < 3)
	{
		i = -2;
		while (i < 3)
		{
			x = (int)round(tmp_x) + i;
			y = (int)round(tmp_y) + j;
			if (data->map->matrix[y][x] == 'D' && data->doors->flag == -1)
			{
				door_angle = door_distance_calcul(x, y, tmp_x, tmp_y);
				if (door_distance_check(door_angle, data))
				{
					data->doors->x = x;
					data->doors->y = y;
					return (1);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

double	door_distance_calcul(int x, int y, double tmp_x, double tmp_y)
{
	double	xx;
	double	yy;
	double	door_angle;
	
	xx = x - tmp_x;
	yy = y - tmp_y;
	door_angle = atan2(yy, xx) * (180.0 / M_PI); // Conversion en degrés
	return (door_angle);
}

int	door_distance_check(double door, t_data *data)
{
	double	diff_angle;
	
	diff_angle = door - data->player.angle;
	if (diff_angle > 180)
		diff_angle -= 360;
	if (diff_angle < -180)
		diff_angle += 360;
	if (fabs(diff_angle) < (data->ray.FOV / 2))
		return (1);
	return (0);
}

void	do_door(t_data *data)
{
	if (check_door_distance(data->player.position_x, data->player.position_y, data))
	{
		data->map->matrix[data->doors->y][data->doors->x] = '0';
		data->doors->flag = 0;
		gettimeofday(&data->doors->timer, NULL);
		find_wall(data);
	}
	else
		return ;
}

int	close_door(t_data *data)
{
	struct timeval	new;
	double			result;

	if (data->doors->flag == 0 && (double_to_int(data->doors->x, data->player.position_x)
		!= data->doors->x || double_to_int(data->doors->y, data->player.position_y)
		!= data->doors->y))
	{
		gettimeofday(&new, NULL);
		result = (new.tv_sec - data->doors->timer.tv_sec)
			+ (new.tv_usec - data->doors->timer.tv_usec) / 1000000;
		if (result >= 5)
		{
			printf("door_closed_timer_ok\n");
			printf("player_y = %f, player_x = %f\n", data->player.position_y, data->player.position_x);
			printf("door_y = %d, door_x = %d\n", data->doors->y, data->doors->x);
			data->map->matrix[data->doors->y][data->doors->x] = 'D';
			data->doors->x = -1;
			data->doors->y = -1;
			find_wall(data);
			data->doors->flag = -1;
		}
	}
	return (0);
}

int	double_to_int(int door, double player)
{
	int	tmp;
	
	tmp = 0;
	if (player > door)
		tmp = floor (player);
	if (player < door)
		tmp = ceil (player);
	return (tmp);
 }