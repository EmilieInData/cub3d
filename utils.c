/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:54:16 by esellier          #+#    #+#             */
/*   Updated: 2025/02/04 19:04:47 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	error_msg(char *str, t_data *data)
{
	write(2, "Error\n", 6);
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
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
}

/*void	free_data_texture(t_data *data)
{
	if (data->texture->no)
		free (data->texture->no);
	if (data->texture->so)
		free (data->texture->so);
	if (data->texture->we)
		free (data->texture->we);
	if (data->texture->ea)
		free (data->texture->ea);
	free (data->texture);
}*/

void	free_data(t_data *data)
{
	//if (mlx_init)
		//destroy mlx_init
	//if (mlx_window)
		//destroy mlx_window
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
	if (data->image) //image general, I use minimap for my test
		free_image(data->image, data); // destroy_windows and mlx too
	//if (data->texture)
	//	free_data_texture(data);
	if (data->mlx)
		free (data->mlx);
	//if (data->sprite)
	//	free_array(data->sprite);
	free (data);
}

/*void    put_pixel_image(t_image *image, int x, int y, int color)
{
	int	tmp;

	tmp = (y * image->length_line) + (x * (image->bit_pix / 8));
	*(unsigned int *)(image->pix_add + tmp) = color;
}*/
