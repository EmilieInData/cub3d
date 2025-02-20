/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:37:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/02/20 13:43:11 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	create_struct_files(t_data *data, char *path, t_files *files)
{
	files->img = mlx_xpm_file_to_image(data->mlx, path,
			&files->width, &files->height);
	if (!files->img)
		exit (error_msg("image not loaded", data));
	files->addr = mlx_get_data_addr(files->img, &files->bpp, &files->line_len, &files->endian);
	if (!files->addr)
		exit (error_msg("Error mlx_get_data_addr failed", data));
}

void	get_wall_texture(t_data *data)
{
	data->texture_north = malloc(sizeof(t_files) * 1);
	if (!data->texture_north)
		exit (error_msg("Malloc error", data));
	data->texture_south = malloc(sizeof(t_files) * 1);
	if (!data->texture_south)
		exit (error_msg("Malloc error", data));
	data->texture_west = malloc(sizeof(t_files) * 1);
	if (!data->texture_west)
		exit (error_msg("Malloc error", data));
	data->texture_east = malloc(sizeof(t_files) * 1);
	if (!data->texture_east)
		exit (error_msg("Malloc error", data));
	
	create_struct_files(data, data->map->no, data->texture_north);
	create_struct_files(data, data->map->so, data->texture_south);
	create_struct_files(data, data->map->we, data->texture_west);
	create_struct_files(data, data->map->ea, data->texture_east);
	return ;
}

t_files *choose_wall_direction(t_data *data, double angle)
{
    t_files	*files;
    
	files = NULL;
	if ((ray_projected_left(angle) == 0) && (data->ray.wall_hit == 'v'))
		files = data->texture_west; //west
	if ((ray_projected_left(angle) == 1) && (data->ray.wall_hit == 'v'))
		files = data->texture_east; //east;
	if ((ray_projected_up(angle) == 1) && (data->ray.wall_hit == 'h'))
		files = data->texture_south; // south
	if ((ray_projected_up(angle) == 0) && (data->ray.wall_hit == 'h'))
		files = data->texture_north; // north
	if (!files)
		ft_putstr_fd("Failed to load textures\n", 2);
	return (files);
}

void	render_wall(int x, int *y, t_data *data, int *i)
{
	int			tex[2];
	float		texture[2];
	float		y_step;
	t_files		*files;

	if (data->ray.wall_hit == 'h')
		texture[0] = fmod(data->ray.hit_x, TILE);
	else
		texture[0] = fmod(data->ray.hit_y, TILE);	
	files = choose_wall_direction(data, data->ray.angle_start);
	texture[0] = (texture[0] / TILE) * files->width;
	texture[1] = 0.0f;
	y_step = (float)files->height / data->ray.wall_height;
	texture[1] = (data->ray.first_wall_pxl - HEIGHT / 2 + data->ray.wall_height / 2) * y_step;
	if (data->ray.wall_height >= HEIGHT)
		texture[1] = ((data->ray.wall_height - HEIGHT) / 2) * y_step;
	while (*y >= data->ray.first_wall_pxl
		&& *y <= data->ray.first_wall_pxl + data->ray.wall_height && *y < HEIGHT)
	{
		tex[1] = (int)texture[1] % files->height;
		tex[0] = fmod(texture[0], files->width);
		print_pixel(data, x, *y, get_pixel_texture(files,
				tex[1], tex[0]));
		texture[1] += y_step;
		(*y)++;
		(*i)--;
	}
}

int 	get_pixel_texture(t_files *files, int x, int y)
{
	char *pixel;
	int color;

	if (x < 0 || y < 0 || !files || x >= files->width || y >= files->height)
		return (0x0);
	pixel = files->addr + ((y * files->line_len) + (x * (files->bpp / 8)));
	color = *(int *)pixel;
	return (color);
}

void	print_pixel(t_data *data, int x, int y, int color)
{
	int pixel;
	
	if (x < 0 || y < 0 || x >= LENGTH || y >= HEIGHT)
		return ;
	pixel = (y * data->image->length_line) + (x * (data->image->bit_pix / 8));
	data->image->pix_add[pixel] = color & 0xFF;
	data->image->pix_add[pixel + 1] = (color >> 8) & 0xFF;
	data->image->pix_add[pixel + 2] = (color >> 16) & 0xFF;
	if (data->image->bit_pix == 32)
		data->image->pix_add[pixel + 3] = (color >> 24);
}

int	rgb_to_int_floor(t_data *data)
{
	return ((data->map->floor.red << 24) | (data->map->floor.green << 16) | (data->map->floor.blue << 8) | 255);
}

int	rgb_to_int_ceil(t_data *data)
{
	return ((data->map->ceiling.red << 24) | (data->map->ceiling.green << 16) | (data->map->ceiling.blue << 8) | 255);
}

void free_textures(t_data *data)
{
	free(data->texture_north); 
	free(data->texture_south);
	free(data->texture_west);
	free(data->texture_east); 
}