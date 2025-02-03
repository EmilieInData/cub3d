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

int find_distance_v(t_data *data, int x, int y)
{
	int dist;

	if ((data->ray.angle_start >= 270 && data->ray.angle_start <= 360) || (data->ray.angle_start > 0 && data->ray.angle_start <= 90))
		x = data->ray.player_x - x;
	else
		x = x - data->ray.player_x;
	y *= y;
	x *= x;
	dist = x + y;
	dist *= dist;
	return (dist);
}

int find_distance_h(int x, int y)
{
	int dist;

	y *= y;
	x *= x;
	dist = x + y;
	dist *= dist;

	return(dist);
}

void	find_shortest_distance(t_ray ray, int i)
{
	if (ray.dist_h > ray.dist_v)
		ray.dist_t_wall[i] = ray.dist_v;
	else
		ray.dist_t_wall[i] = ray.dist_h;
}