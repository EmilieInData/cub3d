/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:14:45 by esellier          #+#    #+#             */
/*   Updated: 2025/01/30 19:25:25 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	do_mini_map(t_data *data, char **matrix)
{
	int	i;
	int	j;

	j = 0;
	while (matrix[j])
	{
		i = 0;
		while (matrix[j][i])
		{
			//if (matrix[j][i] == ' ') // for transparency, we put nothing
			//	put_scaled_image(data->image, i * 30, j * 30, BLACK);
			if (matrix[j][i] == 'D')
				put_scaled_image(data->image, i * 30, j * 30, DARK_PINK);
			else if (matrix[j][i] == '0')
				put_scaled_image(data->image, i * 30, j * 30, PASTEL_PURPLE);
			else if (matrix[j][i] == '1')
				put_scaled_image(data->image, i * 30, j * 30, DARK_PURPLE);
			else if (matrix[j][i] == 'N' || matrix[j][i] == 'E'
				|| matrix[j][i] == 'W' || matrix[j][i] == 'S')
				put_scaled_image(data->image, i * 30, j * 30, BRIGHT_BLUE);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->image->img_add,
		0, 0);
}

void	put_scaled_image(t_image *image, int x, int y, int color)
{
	int	tmp;
	int	i;
	int	j;
	int	scale;

	scale = 30;
	j = 0;
	while (j < scale)
	{
		i = 0;
		while (i < scale)
		{
			tmp = ((y + j) * image->length_line) + ((x + i) * (image->bit_pix / 8));
			*(unsigned int *)(image->pix_add + tmp) = color;
			i++;
		}
		j++;
	}
}

/*void    put_pixel_image(t_image *image, int x, int y, int color)
{
	int	tmp;

	tmp = (y * image->length_line) + (x * (image->bit_pix / 8));
	*(unsigned int *)(image->pix_add + tmp) = color;
}*/
