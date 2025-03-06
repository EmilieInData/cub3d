/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:45:15 by ineimatu          #+#    #+#             */
/*   Updated: 2025/03/06 12:28:30 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

double	find_distance_v(t_data *data, double x, double y)
{
	double	dist;

	data->utils.v_x = x;
	data->utils.v_y = y;
	dist = sqrt((pow((data->ray.player_x - x), 2)) \
		+ (pow((data->ray.player_y - y), 2)));
	return (dist);
}

double	find_distance_h(t_data *data, double x, double y)
{
	double	dist;

	data->utils.h_x = x;
	data->utils.h_y = y;
	dist = sqrt((pow((data->ray.player_x - x), 2)) \
		+ (pow((data->ray.player_y - y), 2)));
	return (dist);
}

void	find_shortest_distance(t_data *data)
{
	double	radians;

	radians = (data->ray.angle_start - data->player.angle) * (M_PI / 180.0);
	if (data->ray.dist_h > data->ray.dist_v)
	{
		data->ray.dist_t_wall = data->ray.dist_v;
		data->utils.wall_hit = 'v';
		data->utils.hit_x = data->utils.v_x;
		data->utils.hit_y = data->utils.v_y;
	}
	else
	{
		data->ray.dist_t_wall = data->ray.dist_h;
		data->utils.wall_hit = 'h';
		data->utils.hit_x = data->utils.h_x;
		data->utils.hit_y = data->utils.h_y;
	}
	data->ray.dist_t_wall *= cos(radians);
}

void	put_pixel_image(t_image *image, int x, int y, int color)
{
	int	tmp;

	tmp = (y * image->length_line) + (x * (image->bit_pix / 8));
	*(unsigned int *)(image->pix_add + tmp) = color;
}

void	wall_height(t_data *data, int x)
{
	double	dist_t_proj_plane;
	int		i;
	int		y;

	i = HEIGHT;
	y = 0;
	dist_t_proj_plane = (LENGTH / 2) / tan((data->ray.fov / 2) \
		* (M_PI / 180.0));
	data->ray.wall_height = ceil((TILE / data->ray.dist_t_wall) \
		* dist_t_proj_plane);
	data->ray.first_wall_pxl = HEIGHT / 2 - (data->ray.wall_height / 2);
	data->ray.last_wall_pxl = data->ray.first_wall_pxl - data->ray.wall_height;
	data->ray.c_f = (HEIGHT / 2) - (data->ray.wall_height / 2);
	while (y <= HEIGHT)
	{
		if (i >= HEIGHT - (int)(data->ray.wall_height + data->ray.c_f))
			put_pixel_image(data->image, x, y, rgb_to_int_ceil(data));
		if (i >= (int)data->ray.c_f && i <= (int)(data->ray.wall_height \
					+ data->ray.c_f))
			render_wall(x, &y, data, &i);
		if (i <= (int)data->ray.c_f && i >= 0)
			put_pixel_image(data->image, x, y, rgb_to_int_floor(data));
		i--;
		y++;
	}
}
