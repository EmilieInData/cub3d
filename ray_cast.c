/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:32:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/21 17:08:23 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

//here I created functions which are checking where the ray casted by our plyer first interact with the wall on the horizontal and vertical plane

void next_vertical(t_data * data, int x_a, int b_y, int b_x, double radians)
{
	int a_y;
	int a_x;

	a_y = x_a * tan(radians); 
	while (1)
	{
		if (data->player.angle >= 0 && data->player.angle <= 180)
			a_y += b_y;
		else
			a_y -= b_y;
		a_x = b_x + TILE;
		b_x = a_x;
		b_y = a_y;
		a_x = a_x / 64;
		a_y = a_y / 64;
		if (data->map->matrix[a_x][a_y] == '1')
		{
			data->ray.dist_v = find_distance_v(data, b_x, b_y);
			break;
		}
	}
}

void vertical_check(t_data *data, double radians)
{
	int b_x;
	int b_y;
	int x_a;
	int x;
	int y;

	b_x = data->player.position_x * 64;
	if ((data->ray.angle_start >= 270 && data->ray.angle_start <= 360 ) || (data->ray.angle_start > 0 && data->ray.angle_start <=90))
	{
		b_x += 64;
		x_a = TILE;
	}
	else
	{
		b_x--;
		x_a = TILE * -1;
	}
	b_y = 32 * tan(radians);
	if (data->ray.angle_start >= 0 && data->ray.angle_start <= 180)
		b_y = data->ray.player_y - b_y;
	else
		b_y = data->ray.player_y + b_y;
	y = b_y / 64;
	x = b_x / 64;	
	if (data->map->matrix[x][y] == '1')
	{	
		data->ray.dist_v = find_distance_v(data, b_x, b_y);
	}
	else
		next_vertical(data, x_a, b_y, b_x, radians);
}


void	next_checks(t_data *data, int a_x, int a_y, double radians)
{
	int y_a;
	int x_a;
	int c_x;
	int c_y;

	if (data->ray.angle_start >= 0 && data->ray.angle_start <= 180)
		y_a = TILE * -1;
	if (data->ray.angle_start >= 181 && data->ray.angle_start <= 359)
		y_a = TILE;
	printf("%i\n", y_a);
	x_a = TILE/tan(radians);
	printf("%i\n", x_a);
	while (1)
	{
		c_x = a_x + x_a;
		c_y = a_y + y_a;
		if (data->map->matrix[(int)c_x / TILE][(int)c_y / TILE])
			if (data->map->matrix[(int)c_x / TILE][(int)c_y / TILE] == '1')
			{
				if (data->ray.angle_start >= 0 && data->ray.angle_start <= 180)
					c_y += a_y;
				data->ray.dist_h = find_distance_h(c_x, c_y);
				break;
			}
			x_a = c_x;
			y_a = c_y;
		else
			printf("Error next_check\n")
	}
}

void horizontal_check(t_data *data, double radians)
{
	double a_y;
	double a_x;
	double adj_side;

	a_y = data->player.position_y * TILE;
	//printf("%i\n", TILE);
	//printf("%i\n", data->player.position_y);
	//printf("%i\n", a_y);
	//a_y *= TILE;
	//printf("%i\n", a_y);
	if (data->ray.angle_start >= 0 && data->ray.angle_start <= 180)
		a_y -= 0.001
	if (data->ray.angle_start >= 181 && data->ray.angle_start <= 359)
		a_y += 64;
	printf("%i\n", data->ray.player_y);
	printf("%i\n", a_y);
	printf("%i\n", data->ray.angle_start);
	printf("%f\n", tan(data->ray.angle_start));
	adj_side = (data->ray.player_y - a_y) / tan(radians);
	if (adj_side < 0)
		adj_side *= -1;
	printf("%i\n", adj_side);
	a_x = data->ray.player_x + adj_side;
	printf("%i\n", a_x);
	printf("%i\n", TILE);

	if (data->map->matrix[(int)a_x / TILE][(int)a_y / TILE])
		if (data->map->matrix[(int)a_x / TILE][(int)a_y / TILE] == '1')
			{
				printf("Check");
				data->ray.dist_h = find_distance_h(adj_side, TILE/2);
			}
		else
			next_checks(data, a_x, a_y, radians);
	else
		printf("Out of map");
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
		data->ray.angle_end = 360 - data->ray.angle_end;
	data->ray.FOV = 60;
}

void	print_ray(t_ray ray)
{
	printf("%i\n", ray.player_x);
	printf("%i\n", ray.player_y);
	printf("%i\n", ray.angle_start);
	printf("%i\n", ray.angle_end);
	printf("%i\n", ray.FOV);
}

void	find_wall(t_data *data)
{ 
	int i;
	double increment;
	double radians;
		
	i = 0;
	increment = 0;
	init_ray(data);
	print_ray(data->ray);
	while (data->ray.angle_start >= data->ray.angle_end)
	{	
		radians = data->ray.angle_start * (M_PI / 180.0);
		horizontal_check(data, radians);
		vertical_check(data, radians);
		//printf("%i", data->ray.dist_h);
		//printf("%i", data->ray.dist_v);
		find_shortest_distance(data->ray, i);
		increment = (double)data->ray.FOV / LENGTH;
		data->ray.angle_start -= increment;
		i++;
	}
	while (i > 0)
	{
		printf("%i ,", data->ray.dist_t_wall[i]);
	}
}
	
