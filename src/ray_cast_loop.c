/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:58:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/03/06 12:21:19 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ray_trace(t_data *data, int x, double increment)
{
	data->ray.angle_start = adjust_angle(data->ray.angle_start);
	data->utils.radians = data->ray.angle_start * (M_PI / 180.0);
	horizontal_check(data, data->ray);
	vertical_check(data, data->ray);
	find_shortest_distance(data);
	wall_height(data, x);
	increment = (double)data->ray.fov / LENGTH;
	data->ray.angle_start -= increment;
}

void	find_wall(t_data *data)
{
	int		x;
	double	increment;

	x = 0;
	increment = (double)data->ray.fov / (double)LENGTH;
	init_ray(data);
	init_utils(data);
	while (x <= LENGTH)
	{
		ray_trace(data, x, increment);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->image->img_add, 0, 0);
	do_mini_map(data, data->map->matrix);
}

void	init_utils(t_data *data)
{
	data->utils.radians = 0.0;
	data->utils.wall_hit = 'c';
	data->utils.h_x = 0;
	data->utils.v_x = 0;
	data->utils.h_y = 0;
	data->utils.v_y = 0;
	data->utils.hit_x = 0;
	data->utils.hit_y = 0;
}
