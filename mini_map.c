/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:14:45 by esellier          #+#    #+#             */
/*   Updated: 2025/03/05 13:23:27 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	do_mini_map(t_data *data, char **matrix)
{
	int	i;
	int	j;
	int	scale;

	scale = fmin(400 / height_map(matrix), 400 / width_map(matrix));
	j = 0;
	while (matrix[j])
	{
		i = 0;
		while (matrix[j][i])
		{
			if (matrix[j][i] == 'D')
				put_scaled_image(data, i * scale, j * scale, DARK_PINK);
			else if (matrix[j][i] == '1')
				put_scaled_image(data, i * scale, j * scale, DARK_PURPLE);
			else if (matrix[j][i] != ' ')
				put_scaled_image(data, i * scale, j * scale, PASTEL_PURPLE);
			i++;
		}
		j++;
	}
	put_scaled_image(data, (data->player.position_x - 0.5) * scale,
		(data->player.position_y - 0.5) * scale, BRIGHT_BLUE);
}

void	put_scaled_image(t_data *data, int x, int y, int color)
{
	int	tmp;
	int	i;
	int	j;
	int	scale;

	scale = fmin(400 / height_map(data->map->matrix),
			400 / width_map(data->map->matrix));
	j = 0;
	while (j < scale)
	{
		i = 0;
		while (i < scale)
		{
			tmp = ((y + j) * data->image->length_line)
				+ ((x + i) * (data->image->bit_pix / 8));
			*(unsigned int *)(data->image->pix_add + tmp) = color;
			i++;
		}
		j++;
	}
}

int	height_map(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	width_map(char **matrix)
{
	int	i;
	int	j;
	int	w;

	j = 0;
	w = 0;
	while (matrix[j])
	{
		i = 0;
		while (matrix[j][i])
			i++;
		if (i > w)
			w = i;
		j++;
	}
	return (w);
}
