/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:37:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/03/03 19:40:37 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	create_struct_files(t_data *data, char *path, t_files *files)
{
	files->img = mlx_xpm_file_to_image(data->mlx, path,
			&files->width, &files->height);
	if (!files->img)
		exit (error_msg("image not loaded", data));
	files->addr = mlx_get_data_addr(files->img, &files->bpp, &files->line_len,
			&files->endian);
	if (!files->addr)
		exit (error_msg("mlx_get_data_addr failed", data));
}

void	get_wall_texture(t_data *data)
{
	create_struct_files(data, data->map->no, &data->texture_north);
	create_struct_files(data, data->map->so, &data->texture_south);
	create_struct_files(data, data->map->we, &data->texture_west);
	create_struct_files(data, data->map->ea, &data->texture_east);
	return ;
}

t_files	*choose_wall_direction(t_data *data, double angle)
{
	t_files	*files;

	files = NULL;
	if ((ray_projected_left(angle) == 0) && (data->ray.wall_hit == 'v'))
		files = &data->texture_west; //west
	if ((ray_projected_left(angle) == 1) && (data->ray.wall_hit == 'v'))
		files = &data->texture_east; //east;
	if ((ray_projected_up(angle) == 1) && (data->ray.wall_hit == 'h'))
		files = &data->texture_south; // south
	if ((ray_projected_up(angle) == 0) && (data->ray.wall_hit == 'h'))
		files = &data->texture_north; // north
	if (!files)
		ft_putstr_fd("Failed to load textures\n", 2); //exit & free?
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
	if (data->ray.type == 'w')
		files = choose_wall_direction(data, data->ray.angle_start);
	else
		files = &data->texture_door;
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
				tex[0], tex[1]));
		texture[1] += y_step;
		(*y)++;
		(*i)--;
	}
}
