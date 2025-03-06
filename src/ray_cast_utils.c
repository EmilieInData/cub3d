/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:35:51 by ineimatu          #+#    #+#             */
/*   Updated: 2025/03/06 12:18:51 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ray_projected_up(int angle)
{
	if (angle >= 0 && angle < 180)
		return (1);
	else
		return (0);
}

int	ray_projected_left(int angle)
{
	if (angle >= 90 && angle < 270)
		return (1);
	else
		return (0);
}

void	init_ray(t_data *data)
{
	data->ray.fov = 60;
	data->ray.player_x = ((double)data->player.position_x * TILE);
	data->ray.player_y = ((double)data->player.position_y * TILE);
	data->ray.angle_start = (double)data->player.angle + (data->ray.fov / 2);
	if (data->ray.angle_start > 360)
		data->ray.angle_start -= 360;
	data->ray.dist_h = 0.0;
	data->ray.dist_v = 0.0;
	data->ray.dist_t_wall = 0.0;
	data->ray.first_wall_pxl = 0;
	data->ray.last_wall_pxl = 0;
	data->ray.wall_height = 0.0;
	data->ray.c_f = 0.0;
}

double	adjust_angle(double angle)
{
	double	res;

	res = 0;
	res = fmod(angle, 360.0);
	if (res <= 0.0)
		res = res + 360.0;
	return (res);
}
