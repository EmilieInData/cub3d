/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:45:15 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/20 14:06:13 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int find_distance_v(t_data *data, double x, double y)
{
	double dist;

	printf("angle %f\n", data->ray.angle_start);
	//printf("rad %f\n", 94.35 * (M_PI / 180.0));
	//printf("x %f, y %f\n", x, y);
	x = data->ray.player_x - x;
	y = data->ray.player_y - y;
	y *= y;
	x *= x;
	dist = x + y;
	dist = sqrt(dist);
	printf("distance : %f\n", dist);
	return (dist);
}

int find_distance_h(t_data *data, double x, double y)
{
	double dist;



	y = data->ray.player_y - y;
	y *= y;
	x = data->ray.player_x - x;
	x *= x;
	dist = x + y;
	dist = sqrt(dist);
	printf("distance : %f\n", dist);
	return(dist);
}

void	find_shortest_distance(t_data *data)
{
	if (data->ray.dist_h > data->ray.dist_v)
		data->ray.dist_t_wall = data->ray.dist_v;
	else
		data->ray.dist_t_wall = data->ray.dist_h;
	printf("shortest distance %f\n", data->ray.dist_t_wall);
}

void wall_height(t_data *data, int x)
{
	double dist_t_proj_plane;
	int middle_of_screen;
	int middle_of_wall;
	int i;
	int y;
	double	angle;

	i = HEIGHT;
	y = 0;
	
	angle = tan(30.0 * (M_PI / 180.0));
	//printf("angle = %f\n", angle);
	dist_t_proj_plane = (LENGTH / 2) / angle;
	printf("Distance to projection plane = %d\n", (int)dist_t_proj_plane);
	data->ray.wall_height  = (TILE / data->ray.dist_t_wall) * dist_t_proj_plane;
	printf("Wall height = %f\n", data->ray.wall_height);
	middle_of_screen = HEIGHT / 2;
	middle_of_wall = data->ray.wall_height / 2;
	printf("middle of the wall = %i\n", middle_of_wall);
	data->ray.ceiling_floor = middle_of_screen - middle_of_wall;
	printf("ceiling  = %i\n", data->ray.ceiling_floor);
	printf("ceiling height = %i\n", data->ray.ceiling_floor + (int)data->ray.wall_height);
	printf("wall height = %i\n", (int)data->ray.wall_height);
	printf("floor height = %d\n", data->ray.ceiling_floor);
	while(y <= HEIGHT)
	{
		if(i >= (HEIGHT - ((int)data->ray.wall_height + (int)data->ray.ceiling_floor)))
			mlx_pixel_put(data->mlx, data->mlx_window, x, y,  0x87d3f8);
		if (i >= (int)data->ray.ceiling_floor && i <= ((int)data->ray.wall_height + (int)data->ray.ceiling_floor))
			mlx_pixel_put(data->mlx, data->mlx_window, x, y, 0xc8509b);	
		if(i <= (int)data->ray.ceiling_floor && i >= 0)
			mlx_pixel_put(data->mlx, data->mlx_window, x, y, 0x1e434e);
		i--;
		y++;
	}
}