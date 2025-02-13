/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:32:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/02/12 15:18:01 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

//here I created functions which are checking where the ray casted by our plyer first interact with the wall on the horizontal and vertical plane

void next_vertical(t_data * data, double x_a, double b_y, double b_x, double radians)
{
	double a_y;

	a_y = fabs(TILE * tan(radians));
	if (ray_projected_up(data->ray.angle_start) == 1)
		a_y *= -1;
	while (1)
	{
		b_x += x_a;
		b_y += a_y;
		if ((int)b_y / TILE >= 0 && (int)b_x / TILE >= 0 && data->ray.map_x > (int)b_x / TILE && data->ray.map_y > (int)b_y / TILE && data->map->matrix[(int)b_y / TILE][(int)b_x / TILE])
		{
			if (data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == '1')
			{
				data->ray.dist_v = find_distance_v(data, b_x, b_y);
				break;
			}
		}
		else
		{
			data->ray.dist_v = DBL_MAX;
			break;
		}
	}
}

void vertical_check(t_data *data, double radians)
{
	double b_x;
	double b_y;
	double x_a;

	b_x = data->player.position_x * TILE;
	x_a = TILE;
	if (ray_projected_right(data->ray.angle_start) == 0)
		b_x += TILE;
	else
	{
		b_x -= 0.000000000001;
		x_a *= -1;
	}
	b_y = data->ray.player_y + (data->ray.player_x - b_x)  * tan(radians);
	if ((int)b_y / TILE >= 0 && (int)b_x / TILE >= 0)
	{
		if (data->ray.map_x > (int)b_x / TILE && data->ray.map_y > (int)b_y / TILE && data->map->matrix[(int)b_y / TILE][(int)b_x / TILE])
		{
			if (data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == '1')
			{	
				data->ray.dist_v = find_distance_v(data, b_x, b_y);
			}
			else
				next_vertical(data, x_a, b_y, b_x, radians);
		}
		else
			data->ray.dist_v = DBL_MAX;
	}
}


void	next_checks(t_data *data, double a_x, double a_y, double radians)
{
	double y_a;
	double x_a;
	double c_x;
	double c_y;

	y_a = TILE;
	if (ray_projected_up(data->ray.angle_start) == 1)
		y_a *= -1;
	x_a = fabs(TILE/tan(radians));
	if (ray_projected_right(data->ray.angle_start) == 1)
		x_a *= -1;
	while (1)
	{
		c_x = a_x + x_a;
		c_y = a_y + y_a;
		if ((int)c_y / TILE >= 0 && (int)c_x / TILE >= 0 && data->ray.map_x > (int)c_x / TILE && data->ray.map_y > (int)c_y / TILE && data->map->matrix[(int)c_y / TILE][(int)c_x / TILE])
		{
			if (data->map->matrix[(int)c_y / TILE][(int)c_x / TILE] == '1')
			{
				data->ray.dist_h = find_distance_h(data, c_x, c_y);
				break;
			}
			a_x = c_x;
			a_y = c_y;
		}
		else
		{
			data->ray.dist_h = DBL_MAX;
			break;
		}
	}
}

void horizontal_check(t_data *data, double radians)
{
	int a;
	int b;
	double a_y;
	double a_x;

	a_y = data->player.position_y * TILE;
	if (ray_projected_up(data->ray.angle_start) == 1)
		a_y -= 0.000000000001;
	else
		a_y += TILE;
	a_x = data->ray.player_x + (data->ray.player_y - a_y) / tan(radians);
	a = (int)a_x / TILE;
	b = (int)a_y / TILE;
	if (a_y / TILE >= 0 && a_x / TILE >= 0 && data->ray.map_x > a_x / TILE && data->ray.map_y > a_y / TILE && data->map->matrix[(int)a_y / TILE][(int)a_x / TILE])
	{
		if (data->map->matrix[(int)a_y / TILE][(int)a_x / TILE] == '1')
				data->ray.dist_h = find_distance_h(data, a_x, a_y);
		else
			next_checks(data, a_x, a_y, radians);
	}
	else
		data->ray.dist_h = DBL_MAX;
}

void	init_ray(t_data *data)
{
	data->ray.player_x = ((double)data->player.position_x * 64) + 32;
	data->ray.player_y = ((double)data->player.position_y * 64) + 32;
	data->ray.angle_start = (double)data->player.angle + 30;
	if (data->ray.angle_start > 360)
		data->ray.angle_start -= 360;
	data->ray.angle_end = (double)data->player.angle - 30;
	if (data->ray.angle_end < 0)
		data->ray.angle_end = 360 + data->ray.angle_end;
	data->ray.FOV = 60;
}

/*void	print_ray(t_ray ray)
{
	printf("%f\n", ray.player_x);
	printf("%f\n", ray.player_y);
	printf("%f\n", ray.angle_start);
	printf("%f\n", ray.angle_end);
	printf("%i\n", ray.FOV);
}*/

void	find_wall(t_data *data)
{ 
	int x;
	double increment;
	double radians;
		
	x = 0;
	increment = 0;
	init_ray(data);
	if (data->ray.angle_start < data->ray.angle_end)
	{
		while (data->ray.angle_start >= 0)
		{	
			radians = data->ray.angle_start * (M_PI / 180.0);
			horizontal_check(data, radians);
			vertical_check(data, radians);
			find_shortest_distance(data);
			wall_height(data, x);
			increment = (double)data->ray.FOV / LENGTH;
			data->ray.angle_start -= increment;
			x++;
		}
		data->ray.angle_start = 360;
	}
	while ((data->ray.angle_start >= data->ray.angle_end))
	{	
		radians = data->ray.angle_start * (M_PI / 180.0);
		horizontal_check(data, radians);
		vertical_check(data, radians);
		find_shortest_distance(data);
		wall_height(data, x);
		increment = (double)data->ray.FOV / LENGTH;
		data->ray.angle_start -= increment;
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->image->img_add, 0, 0);
}


void map_size(t_data *data)
{
	int i;
	int a;

	i = 0;
	if (data->map->matrix)
	{
		while (data->map->matrix[i])
		{
			a = 0;
			while (data->map->matrix[0][a])
				a++;
			i++;
		}
		data->ray.map_x = a;
		data->ray.map_y = i;
	}
}
	
