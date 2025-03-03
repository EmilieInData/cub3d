/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:54:16 by esellier          #+#    #+#             */
/*   Updated: 2025/03/03 17:25:50 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	error_msg(char *str, t_data *data)
{
	printf("Error\n%s\n", str);
	if (data)
		free_data(data);
	return (1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
}

void	free_image(t_image *image, t_data *data)
{
	if (image->img_add)
		mlx_destroy_image(data->mlx, image->img_add);
	if (data->mlx_window)
		mlx_destroy_window(data->mlx, data->mlx_window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (image)
		free (image);
	if (data->mlx)
		free (data->mlx);
}

void	free_data(t_data *data)
{
	if (data->map)
	{
		if (data->map->no)
			free (data->map->no);
		if (data->map->so)
			free (data->map->so);
		if (data->map->we)
			free (data->map->we);
		if (data->map->ea)
			free (data->map->ea);
		if (data->map->matrix)
			free_array(data->map->matrix);
		free(data->map);
	}
	if (data->doors)
		free_doors(data, data->doors);
	free_textures(data);
	if (data->image)
		free_image(data->image, data);
	free (data);
}

void	free_doors(t_data *data, t_door *doors)
{
	int	count;

	(void)data;
	count = 0;
	if (doors->sprite)
	{
		while (count < (PICS - 1) && &doors->sprite[count].img)
		{
			mlx_destroy_image(data->mlx, data->doors->sprite[count].img);
			count++;
		}
		free(doors);
	}
}
