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

void next_vertical(t_data * data, double x_a, double b_y, double b_x, double radians)
{
	double a_y;
	double a_x;
	int i;

	i = 2;
	a_y = x_a * tan(radians);
	//printf("a_y %f\n", a_y);
	//if (data->player.angle >= 0 && data->player.angle <= 180)
	//	a_y += b_y;
	//else
	//	a_y -= b_y;
	while (1)
	{
		a_x = b_x + TILE;
		b_x = a_x;
		b_y = a_y;
		a_x = (int)a_x / TILE;
		a_y = (int)a_y / TILE;
		printf("%i hit x = %f\n", i, b_x);
		printf("%i hit y = %f\n", i,  b_y);
		printf("Coordinates [%i], [%i]\n", (int)a_x, (int)a_y);
		if ((int)a_y >= 0 && (int)a_x >= 0 && data->ray.map_x > (int)a_x && data->ray.map_y > (int)a_y && data->map->matrix[(int)a_y][(int)a_x])
		{
			if (data->map->matrix[(int)a_y][(int)a_x] == '1')
			{
				printf("\nOn the %i times it hit the wall\n", i);
				data->ray.dist_v = find_distance_v(data, b_x, b_y);
				break;
			}
		}
		else
		{
			printf("Error in next_vertical\n");
			break;
		}
		i++;
	}
}

void vertical_check(t_data *data, double radians)
{
	double b_x;
	double b_y;
	double x_a;
	int x;
	int y;

	b_x = data->player.position_x * TILE;
	//printf("%f\n", b_x);
	if ((data->ray.angle_start >= 270 && data->ray.angle_start <= 360 ) || (data->ray.angle_start > 0 && data->ray.angle_start <=90))
	{
		b_x += TILE;
		x_a = TILE;
	}
	else
	{
		b_x -= 0.001;
		x_a = TILE * -1;
	}
	b_y = data->ray.player_y + (data->ray.player_x - b_x)  * tan(radians);
	//printf("Its b_y %f\n", b_y);
	//if (data->ray.angle_start >= 0 && data->ray.angle_start <= 180)
	//	if (b_y < 0)
	//		b_y = data->ray.player_y + b_y;
	//	else
	//		b_y = data->ray.player_y - b_y;
	//else
	//	b_y = data->ray.player_y + b_y;
	y = (int)b_y / TILE;
	//printf("b_y - %i\n and b_x - %f\n", y, b_x);
	x = (int)b_x / TILE;
	//printf("y - %i\n and x - %i\n", y, x);
	//printf("inside %c\n", data->map->matrix[y][x]);
	printf("\n\n\nVERTICAL CHECK\n\n\n");
	printf("First hit x = %f\n", b_x);
	printf("First hit y = %f\n", b_y);
	printf("Coordinates [%i], [%i]\n", y, x);
	if (y >= 0 && x >= 0 && data->ray.map_x > (int)x && data->ray.map_y > (int)y && data->map->matrix[y][x])
	{
		if (data->map->matrix[y][x] == '1')
		{	
			printf("\n Find wall on firt hit \n");
			data->ray.dist_v = find_distance_v(data, b_x, b_y);
		}
		else
			next_vertical(data, x_a, b_y, b_x, radians);
	}
	else
	{
		printf("Error in vertical check\n");
	}
}


void	next_checks(t_data *data, double a_x, double a_y, double radians)
{
	double y_a;
	double x_a;
	double c_x;
	double c_y;
	int i;

	i = 2;
	y_a = TILE;
	if (data->ray.angle_start >= 0 && data->ray.angle_start <= 180)
		y_a *= -1;
	x_a = TILE/tan(radians);
	while (1)
	{
		c_x = a_x + x_a;
		//printf("%f\n", c_x);
		c_y = a_y + y_a;
		//printf("%f\n", c_y);
		//printf("%c\n", data->map->matrix[(int)c_y / TILE][(int)c_x / TILE]);
			//if (data->map->matrix[(int)c_y / TILE][(int)c_x / TILE])
		printf("%i hit x = %f\n", i, c_x);
		printf("%i hit y = %f\n", i,  c_y);
		printf("Coordinates [%i], [%i]\n", (int)c_y / TILE, (int)c_x / TILE);
		if ((int)c_y / TILE >= 0 && (int)c_x / TILE >= 0 && data->ray.map_x > (int)c_x / TILE && data->ray.map_y > (int)c_y / TILE && data->map->matrix[(int)c_y / TILE][(int)c_x / TILE])
		{
			if (data->map->matrix[(int)c_y / TILE][(int)c_x / TILE] == '1')
			{
				//if (data->ray.angle_start >= 0 && data->ray.angle_start <= 180)
				//	c_y += a_y;
				printf("\nOn the %i times it hit the wall\n", i);
				data->ray.dist_h = find_distance_h(data, c_x, c_y);
				break;
			}
			//if (x_a < 0)
			a_x = c_x;
			a_y = c_y;
		}
		else
		{
			printf("Error next_check\n");
			break;
		}
		i++;
	}
}

void horizontal_check(t_data *data, double radians)
{
	int a;
	int b;
	double a_y;
	double a_x;

	a_y = data->player.position_y * TILE;
	if (data->ray.angle_start >= 0 && data->ray.angle_start <= 180)
		a_y -= 0.001;
	if (data->ray.angle_start >= 181 && data->ray.angle_start <= 359)
		a_y += TILE;
	//printf("%f\n", a_y);
	a_x = data->ray.player_x + (data->ray.player_y - a_y) / tan(radians);
	//if (adj_side < 0)
	//	adj_side *= -1;
	//printf("%f\n", adj_side);
	//a_x = data->ray.player_x + adj_side;
	//printf("%f\n", a_x);
	a = (int)a_x / TILE;
	//printf("%i\n", a);
	b = (int)a_y / TILE;
	printf("\n\nHORIZONTAL CHECK\n\n\n");
	printf("First hit x = %f\n", a_x);
	printf("First hit y = %f\n", a_y);
	printf("Coordinates [%i], [%i]\n", b, a);
	if (b >= 0 && a >= 0 && data->ray.map_x > a && data->ray.map_y > b && data->map->matrix[b][a])
	{
		if (data->map->matrix[b][a] == '1')
			{
				printf("\n Find wall on firt hit \n");
				data->ray.dist_h = find_distance_h(data, a_x, (double)TILE/2);
			}
		else
			next_checks(data, a_x, a_y, radians);
	}
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
	printf("%f\n", ray.player_x);
	printf("%f\n", ray.player_y);
	printf("%f\n", ray.angle_start);
	printf("%f\n", ray.angle_end);
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
		//find_shortest_distance(data->ray, i);
		increment = (double)data->ray.FOV / LENGTH;
		data->ray.angle_start -= increment;
		i++;
	}
	/*while (i > 0)
	{
		printf("%f\n ,", data->ray.dist_t_wall[i]);
	}*/
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
	
