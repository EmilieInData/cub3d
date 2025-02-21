/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:25:23 by ineimatu          #+#    #+#             */
/*   Updated: 2025/02/21 14:21:25 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int	get_pixel_texture(t_files *files, int x, int y)
{
	char	*pixel;
	int		color;

	if (x < 0 || y < 0 || !files || x >= files->width || y >= files->height)
		return (0x0);
	pixel = files->addr + ((y * files->line_len) + (x * (files->bpp / 8)));
	color = *(int *)pixel;
	return (color);
}

void	print_pixel(t_data *data, int x, int y, int color)
{
	int	pixel;

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

// void	free_textures_end(t_data *data)
// {
// 	if (data->texture_north)
// 	{
// 		if (data->texture_north->addr)
// 			mlx_destroy_image(data->mlx, data->texture_north->addr);
// 		free(data->texture_north);
// 	}
// 	if (data->texture_south)
// 	{
// 		if (data->texture_south->addr)
// 			mlx_destroy_image(data->mlx, data->texture_south->addr);
// 		free(data->texture_south);
// 	}
// 	if (data->texture_west)
// 	{
// 		if (data->texture_west->addr)
// 			mlx_destroy_image(data->mlx, data->texture_west->addr);
// 		free(data->texture_west);
// 	}
// 	 if (data->texture_east)
// 	{
// 		 if (data->texture_east->addr)
// 			 mlx_destroy_image(data->mlx, data->texture_east->addr);
// 		free(data->texture_east);
// 	}
// }

void	free_textures(t_data *data)
{
	if (data->texture_north)
		free(data->texture_north);
	if (data->texture_south)
		free(data->texture_south);
	if (data->texture_west)
		free(data->texture_west);
	 if (data->texture_east)
		free(data->texture_east);
}
