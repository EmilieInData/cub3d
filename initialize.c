/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:06:09 by esellier          #+#    #+#             */
/*   Updated: 2025/02/27 14:32:38 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	initialize_map(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->floor.red = -1;
	map->floor.green = -1;
	map->floor.blue = -1;
	map->ceiling.red = -1;
	map->ceiling.green = -1;
	map->ceiling.blue = -1;
	map->matrix = NULL;
	map->flag = -1;
}

void	initialize_textures(t_files *texture)
{
	texture->img = NULL;
	texture->addr = NULL;
	texture->bpp = -1;
	texture->line_len = -1;
	texture->endian = -1;
	texture->width = -1;
	texture->height = -1;
}

void	initialize_door(t_data *data)
{
    data->doors = malloc(sizeof (t_door));
    if (!data->doors)
	{
        exit (error_msg("malloc didn't work correctly", data));
	}
    data->doors->x = -1;
	data->doors->y = -1;
	data->doors->flag = -1;
	data->doors->count = 0;
	//struct tinemal timer?
    create_struct_files(data, "./Doors/door_4.xpm", &data->doors->sprite[0]);
	create_struct_files(data, "./Doors/door_3.xpm", &data->doors->sprite[1]);
	create_struct_files(data, "./Doors/door_2.xpm", &data->doors->sprite[2]);
	create_struct_files(data, "./Doors/door_1.xpm", &data->doors->sprite[3]);
}

void	*initialize(t_data *data)
{
	data = malloc (sizeof (t_data));
	if (!data)
		exit (error_msg("malloc didn't work correctly", NULL));
	data->map = malloc (sizeof (t_map));
	if (!data->map)
		exit (error_msg("malloc didn't work correctly", data));
	initialize_map(data->map);
	data->player.news = '0';
	data->player.position_x = -1;
	data->player.position_y = -1;
	data->player.angle = -1;
	//ray
	//image
	gettimeofday(&data->timer, NULL);
	initialize_textures(&data->texture_door);
	initialize_textures(&data->texture_north);
	initialize_textures(&data->texture_south);
	initialize_textures(&data->texture_west);
	initialize_textures(&data->texture_east);
	return (data);
}
