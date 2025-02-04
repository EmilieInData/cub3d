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

void	find_shortest_distance(t_ray ray, int i)
{
	i++;
	if (ray.dist_h > ray.dist_v)
		ray.dist_t_wall = ray.dist_v;
	else
		ray.dist_t_wall = ray.dist_h;
	printf("shortest distance %f\n", ray.dist_t_wall);
}