/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:37:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/02/18 16:32:16 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

t_files	create_struct_files(t_data *data, char *path)
{
	t_files	files;

	files.img = mlx_xpm_file_to_image(data->mlx, path,
			&files.width, &files.height);
	if (!files.img)
		exit (error_msg("image not loaded", data));
	return (files);
}

mlx_texture_t	*get_wall_texture(t_data *data)
{
	data->texture[0] = create_struct_files(data, data->map->no);
	data->texture[1] = create_struct_files(data, data->map->so);
	data->texture[2] = create_struct_files(data, data->map->we);
	data->texture[3] = create_struct_files(data, data->map->ea);
}

void save_wall_direction(t_data *data, double angle)
{
    t_files	*files;
    
	files = NULL;
	if ((ray_projected_left(angle) == 0) && (data->ray.wall_hit == 'v'))
		files = data->texture[2]; //west
	else if ((ray_projected_left(angle) == 1) && (data->ray.wall_hit == 'v'))
		files = data->texture[3]; //east;
	if ((ray_projected_up(angle) == 0) && (data->ray.wall_hit == 'h'))
		files = data->texture[1]; // south
	if ((ray_projected_up(angle) == 0) && (data->ray.wall_hit == 'h'))
		files = data->texture[0]; // north
	if (!files)
		ft_putstr_fd("Failed to load textures\n", 2);
	return (files);
}
/*
void	render_wall(int x, int *y, t_data *data)
{
	int			tex[2];
	float		texture_vtx[2];
	float		y_step;
	t_files		*files;

	if (ray_data->vtx_hit == HORZ)
		texture_vtx[X] = fmod(ray_data->horz_hit[X], TILE_SIZE);
	else
		texture_vtx[X] = fmod(ray_data->vert_hit[Y], TILE_SIZE);
	files = save_wall_direction(data, data->ray.angle_start);
	texture_vtx[X] = (texture_vtx[X] / TILE_SIZE) * texture->width;
	texture_vtx[Y] = 0.0f;
	y_step = (float)texture->height / ray_data->wall_height;
	if (ray_data->wall_height >= HEIGHT)
		texture_vtx[Y] = ((ray_data->wall_height - HEIGHT) / 2) * y_step;
	while (*y >= ray_data->wall_y
		&& *y <= ray_data->wall_y + ray_data->wall_height && *y < HEIGHT)
	{
		tex[Y] = (int)texture_vtx[Y] % texture->height;
		tex[X] = fmod(texture_vtx[X], texture->width);
		print_pixel_render(x, *y, get_texture_pixel(texture,
				tex[X], tex[Y]), data);
		texture_vtx[Y] += y_step;
		(*y)++;
	}
}*/