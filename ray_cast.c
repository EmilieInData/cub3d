/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:32:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/02/17 16:54:24 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int length(t_data * data, int y, int x)
{
	int i;

	//printf("line y = %i\n", y);
	//printf("line x = %i\n", x);
	if (y < data->ray.map_y)
	{
		i = 0;
		while (data->map->matrix[y][i])
			i++;
		//printf("line length = %i\n", i - 1);
		return (i - 1);
	}
	else
		return (x - 1);
}

int height(t_data *data, int x, int y)
{
	int i;

	printf("line y = %i\n", y);
	printf("line x = %i\n", x);
	if (x < data->ray.map_x)
	{
		i = 0;
		while (data->map->matrix[i][x])
			i++;
		printf("line length = %i\n", i);	
		return (i);
	}
	else
		return (y - 1);
}

void next_vertical(t_data * data, double x_a, double b_y, double b_x, double radians)
{
	double a_y;
	int i;

	i = 0;
	a_y = fabs(TILE * tan(radians));
	if (ray_projected_up(data->ray.angle_start) == 1)
		a_y *= -1;
	//printf("%i vertical x increment = %f\n", i, x_a);
	//printf("%i vertical y increment = %f\n", i,  a_y); 
	//printf("Angle %f\n", data->ray.angle_start);
	while (1)
	{
		b_x += x_a;
		b_y += a_y;
		//printf("%i hit x = %f\n", i, b_x);
		//printf("%i hit y = %f\n", i,  b_y);
		///printf("Coordinates [%i], [%i]\n", (int)b_y / TILE, (int)b_x / TILE);
		if ((int)b_y / TILE >= 0 && (int)b_x / TILE >= 0 && data->ray.map_x > (int)b_x / TILE && data->ray.map_y > (int)b_y / TILE)
		{
			if (data->map->matrix[(int)b_y / TILE][(int)b_x / TILE])
			{
				if (data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == '1')
				{
					//printf("\nOn the %i times it hit the wall\n", i);
					data->ray.dist_v = find_distance_v(data, b_x, b_y);
					break;
				}
			}
			i++;
		}
		else
		{
			//printf("Error in next_vertical, out of the map\n");
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

	b_x = floor(data->ray.player_x / TILE);
	b_x *= TILE;
	x_a = TILE;
	if (ray_projected_left(data->ray.angle_start) == 1)
	{
		b_x -= 0.000000000001;
		x_a *= -1;
	}
	else
	{
		b_x += TILE;
	}
	b_y = data->ray.player_y + (data->ray.player_x - b_x)  * tan(radians);
	//printf("\n\n\nVERTICAL CHECK\n\n\n");
	//printf("First hit x = %f\n", b_x);
	//printf("First hit y = %f\n", b_y);
	//printf("Coordinates [%i], [%i]\n", (int)b_y / TILE, (int)b_x / TILE);
	if ((int)b_y / TILE >= 0 && (int)b_x / TILE >= 0)
	{
		//printf("%i\n", height(data, fabs(b_x / TILE), b_y / TILE));
		if ((double)length(data, ceil(b_y / TILE), ceil(b_x / TILE)) >= b_x / TILE /*&& data->ray.map_y > (int)b_y / TILE */&& data->map->matrix[(int)b_y / TILE][(int)b_x / TILE])
		{
			if (data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == '1')
			{	
				//printf("\n Find wall on firt hit \n");
				data->ray.dist_v = find_distance_v(data, b_x, b_y);
			}
			else
				next_vertical(data, x_a, b_y, b_x, radians);
		}
		else
		{
			//printf("Out of map on vertical check\n");
			data->ray.dist_v = DBL_MAX;
		}
	}
}


void	next_checks(t_data *data, double a_x, double a_y, double radians)
{
	double y_a;
	double x_a;
	double c_x;
	double c_y;
	int i;

	i = 0;
	y_a = TILE;
	if (ray_projected_up(data->ray.angle_start) == 1)
		y_a *= -1;
	x_a = fabs(TILE/tan(radians));
	if (ray_projected_left(data->ray.angle_start) == 1)
		x_a *= -1;
	//printf("%i horizontal x increment = %f\n", i, x_a);
	//printf("%i horizontal y increment = %f\n", i,  y_a); 
	//printf("Angle %f\n", data->ray.angle_start);
	while (1)
	{
		c_x = a_x + x_a;
		c_y = a_y + y_a;
		//printf("%i hit x = %f\n", i, c_x);
		//printf("%i hit y = %f\n", i,  c_y);
		//printf("Coordinates [%i], [%i]\n", (int)c_y / TILE, (int)c_x / TILE);
		if ((int)c_y / TILE >= 0 && (int)c_x / TILE >= 0 && (double)length(data, ceil(c_y / TILE), ceil(c_x / TILE)) >= c_x / TILE /*&& data->ray.map_y >= (int)c_y / TILE)*/)
		{
			if (data->map->matrix[(int)(c_y / TILE)][(int)(c_x / TILE)])
			{
				if (data->map->matrix[(int)(c_y / TILE)][(int)(c_x / TILE)] == '1')
				{
					//printf("\nOn the %i times it hit the wall\n", i);
					data->ray.dist_h = find_distance_h(data, c_x, c_y);
					break;
				}
				a_x = c_x;
				a_y = c_y;
				i++;
			}
			else
			{
				break;
			}

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
	
	double a_y;
	double a_x;

	a_y = floor(data->ray.player_y / TILE); 
	a_y *= TILE;
	if (ray_projected_up(data->ray.angle_start) == 1)
		a_y -= 0.000000000001;
	else
		a_y += TILE;
	a_x = data->ray.player_x + (data->ray.player_y - a_y) / tan(radians);	
	//printf("\n\nHORIZONTAL CHECK\n\n\n");
	//printf("First hit x = %f\n", a_x);
	//printf("First hit y = %f\n", a_y);
	//printf("Coordinates [%i], [%i]\n", (int)a_y / TILE, (int)a_x / TILE);
	if ((int)a_y / TILE >= 0 && (int)a_x / TILE >= 0 && (double)length(data, ceil(a_y / TILE), ceil(a_x / TILE)) > a_x / TILE/*data->ray.map_y > (int)a_y / TILE &&*/)
	{
		if (data->map->matrix[(int)a_y / TILE][(int)a_x / TILE])
		{
			if (data->map->matrix[(int)fabs(a_y / TILE)][(int)fabs(a_x / TILE)] == '1')
			{
					//printf("\n Find wall on first hit \n");
					data->ray.dist_h = find_distance_h(data, a_x, a_y);
			}
			else
				next_checks(data, a_x, a_y, radians);
		}
	}
	else
	{
		//printf("Out of map\n");
		data->ray.dist_h = DBL_MAX;
	}
}

void	init_ray(t_data *data)
{
	data->ray.FOV = 60;
	data->ray.player_x = ((double)data->player.position_x * 64) + 32;
	data->ray.player_y = ((double)data->player.position_y * 64) + 32;
	data->ray.angle_start = (double)data->player.angle + (data->ray.FOV / 2);
	if (data->ray.angle_start > 360)
		data->ray.angle_start -= 360;
	data->ray.angle_end = (double)data->player.angle - (data->ray.FOV / 2);
	if (data->ray.angle_end < 0)
		data->ray.angle_end = 360 + data->ray.angle_end;
}

void	ray_trace(t_data *data, int x, double increment)
{
	double radians;

	radians = data->ray.angle_start * (M_PI / 180.0);
	horizontal_check(data, radians);
	vertical_check(data, radians);
	find_shortest_distance(data);
	wall_height(data, x);
	increment = (double)data->ray.FOV / LENGTH;
	data->ray.angle_start -= increment;
}

void	find_wall(t_data *data)
{ 
	int x;
	double increment;
		
	x = 0;
	increment = (double)data->ray.FOV / LENGTH;
	init_ray(data);
	if (data->ray.angle_start < data->ray.angle_end)
	{
		while (data->ray.angle_start >= 0)
		{	
			ray_trace(data, x, increment);
			x++;
		}
		data->ray.angle_start = 360;
	}
	else
	{
		while ((data->ray.angle_start >= data->ray.angle_end))
		{	
			ray_trace(data, x, increment);
			x++;
		}
	}
	do_mini_map(data, data->map->matrix);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->image->img_add, 0, 0);
}


void map_size(t_data *data)
{
	int i;
	int a;
	int max_length;

	i = 0;
	max_length = 0;
	if (data->map->matrix)
	{
		while (data->map->matrix[i])
		{
			a = 0;
			while (data->map->matrix[0][a])
				a++;
			if (max_length < a)
				max_length = a;
			i++;
		}
		data->ray.map_x = max_length;
		data->ray.map_y = i;
	}
}
	
