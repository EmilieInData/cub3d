/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:37:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/02/18 16:08:07 by ineimatu         ###   ########.fr       */
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

void render_wall(int x, int y, t_data *data)
{
    
    
}