/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:40:27 by esellier          #+#    #+#             */
/*   Updated: 2025/03/05 13:31:56 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	do_door(t_data *data)
{
	int	i;

	i = 0;
	if (check_door_distance(data->player.position_x,
			data->player.position_y, i, data))
	{
		data->map->matrix[data->doors->y][data->doors->x] = '0';
		data->doors->flag = 0;
		gettimeofday(&data->doors->timer, NULL);
		find_wall(data);
	}
	else
		return ;
}

int	check_door_distance(double tmp_x, double tmp_y, int i, t_data *data)
{
	int		j;
	int		x;
	int		y;
	double	door_angle;

	j = -2;
	while (j < 3)
	{
		i = -2;
		while (i < 3)
		{
			x = (int)round(tmp_x) + i;
			y = (int)round(tmp_y) + j;
			if (x <= check_length(data->map->matrix, y)
				&& data->map->matrix[y][x] == 'D' && data->doors->flag == -1)
			{
				door_angle = door_distance_calcul(x, y, tmp_x, tmp_y);
				if (!door_angle_check(data, door_angle, x, y))
					return (1);
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
	door_angle = atan2(yy, xx) * (180.0 / M_PI);
	return (door_angle);
}

int	door_angle_check(t_data *data, double door_angle, int x, int y)
{
	double	tmp;

	tmp = data->ray.angle_start + data->ray.fov;
	if (tmp > 360)
	{
		tmp = tmp - 360;
		if ((fabs)(door_angle) <= tmp)
		{
			data->doors->x = x;
			data->doors->y = y;
			return (0);
		}
	}
	else if ((fabs)(door_angle) >= data->ray.angle_start
	&& (fabs)(door_angle) <= tmp)
	{
		data->doors->x = x;
		data->doors->y = y;
		return (0);
	}
	return (1);
}

int	close_door(t_data *data)
{
	struct timeval	new;
	double			result;

	if (data->doors->flag == 0
		&& (double_to_int(data->doors->x, data->player.position_x)
			!= data->doors->x || double_to_int(data->doors->y,
				data->player.position_y) != data->doors->y))
	{
		gettimeofday(&new, NULL);
		result = (new.tv_sec - data->doors->timer.tv_sec)
			+ (new.tv_usec - data->doors->timer.tv_usec) / 1000000;
		if (result >= 5)
		{
			data->map->matrix[data->doors->y][data->doors->x] = 'D';
			data->doors->x = -1;
			data->doors->y = -1;
			find_wall(data);
			data->doors->flag = -1;
		}
	}
	return (0);
}
