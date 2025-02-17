/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:45:15 by ineimatu          #+#    #+#             */
/*   Updated: 2025/02/13 15:46:18 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int find_distance_v(t_data *data, double x, double y)
{
	double dist;

	x = data->ray.player_x - x;
	y = data->ray.player_y - y;
	y *= y;
	x *= x;
	dist = x + y;
	dist = sqrt(dist);
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
	return(dist);
}

void	find_shortest_distance(t_data *data)
{
	double radians;

	radians = (data->ray.angle_start - data->player.angle) * (M_PI / 180.0);
	if (data->ray.dist_h > data->ray.dist_v)
		data->ray.dist_t_wall = data->ray.dist_v;
	else
		data->ray.dist_t_wall = data->ray.dist_h;
	data->ray.dist_t_wall *= cos(radians);
}


/*void	my_mlx_pixel_put(t_vars vars, int x, int y, int color)
{
	char	*dst;

	dst = vars.data.addr + (y * vars.data.line_length + x
			* (vars.data.bpp / 8));
	*(unsigned int *)dst = color;
}*/

void    put_pixel_image(t_image *image, int x, int y, int color)
{
	int	tmp;

	tmp = (y * image->length_line) + (x * (image->bit_pix / 8));
	*(unsigned int *)(image->pix_add + tmp) = color;
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
	dist_t_proj_plane = (LENGTH / 2) / angle;
	data->ray.wall_height  = (TILE / data->ray.dist_t_wall) * dist_t_proj_plane;
	data->ray.wall_height  = ceil(data->ray.wall_height);
	middle_of_screen = HEIGHT / 2;
	middle_of_wall = data->ray.wall_height / 2;
	data->ray.ceiling_floor = middle_of_screen - middle_of_wall;
	while(y <= HEIGHT)
	{
		if(i >= (HEIGHT - ((int)data->ray.wall_height + (int)data->ray.ceiling_floor)))
			put_pixel_image(data->image, x, y,  0x87d3f8);
		if (i >= (int)data->ray.ceiling_floor && i <= ((int)data->ray.wall_height + (int)data->ray.ceiling_floor))
			put_pixel_image(data->image, x, y, 0xc8509b);	
		if(i <= (int)data->ray.ceiling_floor && i >= 0)
			put_pixel_image(data->image, x, y, 0x1e434e);
		i--;
		y++;
		//printf("x = %i, y = %i\n", x, y);
	}
	//:printf("x = %i, y = %i\n", x, y);
}
