/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:32:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/03/06 12:12:45 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	next_vertical(t_data *data, double increment_x, double b_y, double b_x)
{
	double	increment_y;

	increment_y = fabs(TILE * tan(data->utils.radians));
	if (ray_projected_up(data->ray.angle_start) == 1)
		increment_y *= -1;
	while (1)
	{
		b_x += increment_x;
		b_y += increment_y;
		if ((int)b_y / TILE >= 0 && (int)b_x / TILE >= 0 && \
			b_x / TILE < check_length(data->map->matrix, (int)(b_y / TILE)))
		{
			if (data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == '1' || \
				data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == 'D')
			{
				data->ray.dist_v = find_distance_v(data, b_x, b_y);
				break ;
			}
		}
		else
		{
			data->ray.dist_v = find_distance_v(data, b_x, b_y);
			break ;
		}
	}
}

void	vertical_check(t_data *data, t_ray ray)
{
	double	b_x;
	double	b_y;
	double	increment_x;

	increment_x = TILE;
	if (ray_projected_left(ray.angle_start) == 1)
	{
		b_x = floor(ray.player_x / TILE) * TILE - 0.00001;
		increment_x *= -1;
	}
	else
		b_x = floor(ray.player_x / TILE) * TILE + TILE;
	b_y = ray.player_y + (ray.player_x - b_x) * tan(data->utils.radians);
	if ((int)b_y / TILE > 0 && (int)b_x / TILE >= 0 && \
		b_x / TILE < check_length(data->map->matrix, (int)(b_y / TILE)))
	{
		if (data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == '1' \
			|| data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == 'D')
			data->ray.dist_v = find_distance_v(data, b_x, b_y);
		else
			next_vertical(data, increment_x, b_y, b_x);
	}
	else
		data->ray.dist_v = find_distance_v(data, b_x, b_y);
}

void	next_checks(t_data *data, double c_x, double c_y, double increment_y)
{
	double	increment_x;

	increment_x = fabs(TILE / tan(data->utils.radians));
	if (ray_projected_left(data->ray.angle_start) == 1)
		increment_x *= -1;
	while (1)
	{
		c_x += increment_x;
		c_y += increment_y;
		if ((int)c_y / TILE >= 0 && (int)c_x / TILE >= 0 && \
		c_x / TILE < check_length(data->map->matrix, (int)(c_y / TILE)))
		{
			if (data->map->matrix[(int)(c_y / TILE)][(int)(c_x / TILE)] == '1' \
			|| data->map->matrix[(int)(c_y / TILE)][(int)(c_x / TILE)] == 'D')
			{
				data->ray.dist_h = find_distance_h(data, c_x, c_y);
				break ;
			}
		}
		else
		{
			data->ray.dist_h = find_distance_h(data, c_x, c_y);
			break ;
		}
	}
}

void	horizontal_check(t_data *data, t_ray ray)
{
	double	a_y;
	double	a_x;
	double	increment_y;

	increment_y = TILE;
	if (ray_projected_up(ray.angle_start) == 1)
	{
		a_y = floor(ray.player_y / TILE) * TILE - 0.001;
		increment_y *= -1;
	}
	else
		a_y = floor(ray.player_y / TILE) * TILE + TILE;
	a_x = ray.player_x + (ray.player_y - a_y) / tan(data->utils.radians);
	if ((int)a_y / TILE >= 0 && (int)a_x / TILE >= 0 && \
		a_x / TILE < check_length(data->map->matrix, (int)(a_y / TILE)))
	{
		if (data->map->matrix[(int)(a_y / TILE)][(int)(a_x / TILE)] == '1' \
			|| data->map->matrix[(int)(a_y / TILE)][(int)(a_x / TILE)] == 'D')
			data->ray.dist_h = find_distance_h(data, a_x, a_y);
		else
			next_checks(data, a_x, a_y, increment_y);
	}
	else
		data->ray.dist_h = find_distance_h(data, a_x, a_y);
}
