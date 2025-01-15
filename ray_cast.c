/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:32:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/15 16:08:21 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/struct.h"
#include "includes/cub3D.h"

void next_vertical(t_data * data, int x_a, int b_y, int b_x)
{
	int a_y;
	int a_x;

	a_y = x_a * tan(data.player.player_x); 
	while (1)
	{
		if (data.player.angle >= 0 && data.player.angle <= 180)
			a_y += (b_y * 64);
		else
			a_y -= (b_y * 64);
		a_x = b_x * 64 + TILE;
		b_x = a_x;
		b_y = a_y;
		a_x = a_x / 64;
		a_y = a_y / 64;
		if (data.map->matrix[a_x, a_y] == 1)
		{
			data.ray.dist_v = find_distance_v(player, b_x, b_y);
			break;
		}
}

void vertical_check(t_data *data)
{
	int b_x;
	int b_y;
	int x_a;
	int x;
	int y;

	b_x = data.player.player_x / 64;
	b_x *= 64;
	if (data.player.angle >= 270 && data.player.angle <=90)
	{
		b_x += 64;
		x_a = TILE;
	}
	else
	{
		b_x--;
		x_a = TILE * -1;
	}
	b_y = 32 * tan(data.player.angle);
	if (data.player.angle >= 0 && data.player.angle <= 180)
		b_y = data.player.player_y - b_y;
	else
		b_y = data.player.player_y + b_y;
	y = b_y / 64;
	x = b_x / 64;	
	if (data.map->matrix[x, y] == 1)
	{	
		data.ray.dist_v = find_distance_v(b_x, b_y);
	}
	else
		next_vertical(data, x_a, b_y, b_x);
}


void	next_checks(t_data *data, int a_x, int a_y)
{
	int y_a;
	int x_a;
	int c_x;
	int c_y;

	if (data.player.angle >= 0 && data.player.angle <= 180)
		y_a -= TILE;
	if (data.player.angle >= 181 && data.player.angle <= 359)
		y_a = TILE;
	x_a = TILE/tan(60);
	while (1)
		{
		c_x = a_x + x_a;
		c_y = a_y + y_a;
		c_x = c_x / TILE;
		c_y = c_y / TILE;
		if (data.map->matrix[c_x, c_y] == 1)
		{
			data.player.wall_h_x = c_x;
			data.player.wall_h_y = c_y;
			find_distance();
			break;
		}
		a_x = c_x;
		a_y = c_y;
	}
}

void horizontal_check(t_data *data)
{
	int a_y;
	int a_x;

	a_y = data.player.player_y / TILE;
	a_y *= TILE;
	if (data.player.angle >= 0 && data.player.angle <= 180)
		a_y--;
	if (data.player.angle >= 181 && data.player.angle <= 359)
		a_y += 64;
	a_x = data.player.player_x + (data.player.player_y - a_y) / tan(data.player.player_angle);
	a_x = a_x / TILE;
	a_y = a_y / TILE;
	if (data.map->matrix[a_x, a_y] == 1)
	{
		data.player.wall_h_x = a_x;
		data.player.wall_h_y = a_y;
		find_disance();
	}
	else
		next_checks(data, a_x, a_y)
}	

void	find_wall(t_data *data)
{ 
	horizontal_check(data);
	vertical_check(data);
	find_distance();
}
	
