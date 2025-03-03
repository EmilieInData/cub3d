/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:45:15 by ineimatu          #+#    #+#             */
/*   Updated: 2025/03/03 15:09:41 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

double find_distance_v(t_data *data, double x, double y)
{
	double dist;

	data->ray->v_x = x; // TILE;
	data->ray->v_y = y; // TILE;
	if (data->ray->angle_start > 260 && data->ray->angle_start < 280)
	{
		printf("last x hit vertical = %f,  last y hit vertical = %f\n,", data->ray->v_x, data->ray->v_y);
	}
	dist = sqrt((pow((data->ray->player_x - x), 2)) + (pow((data->ray->player_y - y), 2)));
	
	return (dist);
}

double find_distance_h(t_data *data, double x, double y)
{
	double dist;

	data->ray->h_x = x; // TILE;
	data->ray->h_y = y; // TILE;
	if (data->ray->angle_start > 260 && data->ray->angle_start < 280)
	{
		printf("\n\n ANGLE = %f\n\n last x hit horizontal = %f,  last y hit horizontal = %f\n,", data->ray->angle_start, data->ray->h_x, data->ray->h_y);
	}
	dist = sqrt((pow((data->ray->player_x - x), 2)) + (pow((data->ray->player_y - y), 2)));

	return(dist);
}

void	find_shortest_distance(t_data *data)
{
	double radians;

	radians = (data->ray->angle_start - data->player.angle) * (M_PI / 180.0);
	if (data->ray->angle_start > 260 && data->ray->angle_start < 280)
	{
		printf("distance h = %f\n, distance v = %f\n", data->ray->dist_h, data->ray->dist_v);
	}
	if (data->ray->dist_h > data->ray->dist_v)
	{
		if (data->ray->angle_start > 260 && data->ray->angle_start < 280)
		{	
			printf("Entered vertical hit\n");
		}
		data->ray->dist_t_wall = data->ray->dist_v;
		data->ray->wall_hit = 'v';
		data->ray->hit_x = data->ray->v_x;
		data->ray->hit_y = data->ray->v_y;
	}
	else
	{
		if (data->ray->angle_start > 260 && data->ray->angle_start < 280)
		{	
			printf("Entered horizontal hit\n");
		}
		data->ray->dist_t_wall = data->ray->dist_h;
		data->ray->wall_hit = 'h';
		data->ray->hit_x = data->ray->h_x;
		data->ray->hit_y = data->ray->h_y;
	}
	data->ray->dist_t_wall *= cos(radians);
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
	double middle_of_screen;
	double middle_of_wall;
	int i;
	int y;
	double	angle;

	i = HEIGHT;
	y = 0;
	angle = tan((data->ray->FOV / 2) * (M_PI / 180.0));
	dist_t_proj_plane = (LENGTH / 2) / angle;
	data->ray->wall_height  = (TILE / data->ray->dist_t_wall) * dist_t_proj_plane;
	data->ray->wall_height  = ceil(data->ray->wall_height);
	if (fabs(data->ray->old_distance_v - data->ray->wall_height) > 50)
		printf("PROBLEME\n");
	data->ray->old_distance_v = data->ray->wall_height;
	printf("\nWall height = %f\n", data->ray->wall_height);
	middle_of_screen = HEIGHT / 2;
	data->ray->first_wall_pxl = middle_of_screen - (data->ray->wall_height / 2);
	data->ray->last_wall_pxl = data->ray->first_wall_pxl - data->ray->wall_height;
	middle_of_wall = data->ray->wall_height / 2;
	data->ray->ceiling_floor = middle_of_screen - middle_of_wall;
	while(y <= HEIGHT)
	{
		if (i >= (HEIGHT - ((int)data->ray->wall_height + (int)data->ray->ceiling_floor)))
			put_pixel_image(data->image, x, y,  rgb_to_int_ceil(data));
		if (i >= (int)data->ray->ceiling_floor && i <= ((int)data->ray->wall_height + (int)data->ray->ceiling_floor))
			render_wall(x, &y, data, &i);//put_pixel_image(data->image, x, y,  0xff5733 );render_wall(x, &y, data, &i);
		if (i <= (int)data->ray->ceiling_floor && i >= 0)
			put_pixel_image(data->image, x, y, rgb_to_int_floor(data));	
		i--;
		y++;
	}
}
