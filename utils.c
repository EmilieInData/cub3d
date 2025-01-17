/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:54:16 by esellier          #+#    #+#             */
/*   Updated: 2025/01/17 16:52:43 by esellier         ###   ########.fr       */
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
	//if (data->player)
	//{
		//all lines to free
	//	free(data->player);
	//}
	free (data);
}
