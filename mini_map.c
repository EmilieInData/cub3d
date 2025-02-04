/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:14:45 by esellier          #+#    #+#             */
/*   Updated: 2025/02/04 19:14:03 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	do_mini_map(t_data *data, char **matrix)
{
	int	i;
	int	j;
	int	scale;

	scale = 20;
	j = 0;
	while (matrix[j])
	{
		i = 0;
		while (matrix[j][i])
		{
			//if (matrix[j][i] == ' ') // for transparency, we put nothing
			//	put_scaled_image(data->image, i * scale, j * scale, BLACK);
			if (matrix[j][i] == 'D')
				put_scaled_image(data->image, i * scale, j * scale, DARK_PINK);
			else if (matrix[j][i] == '0')
				put_scaled_image(data->image, i * scale, j * scale, PASTEL_PURPLE);
			else if (matrix[j][i] == '1')
				put_scaled_image(data->image, i * scale, j * scale, DARK_PURPLE);
			i++;
		}
		j++;
	}
	put_scaled_image(data->image, data->player.position_x * scale,
		data->player.position_y * scale, BRIGHT_BLUE);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->image->img_add,
		0, 0);
}

void	put_scaled_image(t_image *image, int x, int y, int color)
{
	int	tmp;
	int	i;
	int	j;
	int	scale;

	scale = 20;
	j = 0;
	while (j < scale)
	{
		i = 0;
		while (i < scale)
		{
			tmp = ((y + j) * image->length_line)
				+ ((x + i) * (image->bit_pix / 8));
			*(unsigned int *)(image->pix_add + tmp) = color;
			i++;
		}
		j++;
	}
}

//scale la mini-map en fonction de la taille de la map (pb si map super grande)
//ou devrait faire toujours a peu pres la mm taille, mettre un cadre max de taille ?
//mais tester sans scale le joueur
// faire avec un pourcentage plutot ?
// mettre des touches pour regler la taille de la map manuellement de la fenetre?

void	init_sprite_neon(t_data *data)
{
	data->sprite[0] = create_struct_files(data, FILES_NAME);
	data->sprite[1] = create_struct_files(data, FILES_NAME);
	data->sprite[2] = create_struct_files(data, FILES_NAME);
	data->sprite[3] = create_struct_files(data, FILES_NAME);
	data->sprite[4] = create_struct_files(data, FILES_NAME);
	data->sprite[5] = create_struct_files(data, FILES_NAME);
	data->sprite[6] = create_struct_files(data, FILES_NAME);
	data->sprite[7] = create_struct_files(data, FILES_NAME);
	data->sprite[8] = create_struct_files(data, FILES_NAME);
	data->sprite[9] = create_struct_files(data, FILES_NAME);
}

void	do_sprite_neon(t_data *data)
{
	
}

void	init_sprite_door(t_data *data)
{
	data->sprite[0] = create_struct_files(data, FILES_NAME);
	data->sprite[1] = create_struct_files(data, FILES_NAME);
	data->sprite[2] = create_struct_files(data, FILES_NAME);
	data->sprite[3] = create_struct_files(data, FILES_NAME);
	data->sprite[4] = create_struct_files(data, FILES_NAME);
	data->sprite[5] = create_struct_files(data, FILES_NAME);
	data->sprite[6] = create_struct_files(data, FILES_NAME);
	data->sprite[7] = create_struct_files(data, FILES_NAME);
	data->sprite[8] = create_struct_files(data, FILES_NAME);
	data->sprite[9] = create_struct_files(data, FILES_NAME);
}

void	do_sprite_door(t_data *data)
{
	
}