/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/23 19:54:01 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	map_check(t_data *data, char **matrix)
{
	int	j;

	j = 1;
	if (!matrix)
		exit (error_msg("map is missing in the file", data));
	map_check_first_last_line(data, 0, 0);
	while (matrix[j] && matrix[j + 1])
	{
		map_check_middle_line(data, 0, j);
		j++;
	}
	if (j < 2)
		exit (error_msg("map shape is incorrect, not big enough", data));
	map_check_first_last_line(data, 0, j);
	map_check_border(data, data->map->matrix);
	if (data->player.news == '0')
		exit (error_msg("map is incorrect, miss a player", data));
}

void	map_check_door(t_data *data, int i, int j, char **matrix) //bonus
{
	char	*m;

	m = "door is bad implanted, can't be on a border or surrounded by walls";
	if ((matrix[j + 1][i] == '0' && matrix[j - 1][i] == '0'
		&& matrix[j][i + 1] == '1' && matrix[j][i - 1] == '1')
		|| (matrix[j + 1][i] == '1' && matrix[j - 1][i] == '1'
		&& matrix[j][i + 1] == '0' && matrix[j][i - 1] == '0'))
		return ;
	else
		exit (error_msg(m, data));
}

void	map_check_first_last_line(t_data *data, int i, int j)
{
	while (data->map->matrix[j][i] && data->map->matrix[j][i] == ' ') //+ char 9 a 12 ?
		i++;
	while (data->map->matrix[j][i])
	{
		if (data->map->matrix[j][i] == 'N' || data->map->matrix[j][i] == 'E'
			|| data->map->matrix[j][i] == 'W' || data->map->matrix[j][i] == 'S')
			exit (error_msg("player can't be in the border", data));
		if (data->map->matrix[j][i] == 'D')
			exit (error_msg("a door can't be in the border", data));
		if (data->map->matrix[j][i] != '1' && data->map->matrix[j][i] != ' ')
			exit (error_msg("map border is incorrect", data));
		i++;
	}
}

void	map_check_middle_line(t_data *data, int i, int j)
{
	while (data->map->matrix[j][i] && data->map->matrix[j][i] == ' ')
		i++;
	if (data->map->matrix[j][i] != '1')
		exit (error_msg("map border is incorrect", data));
	while (data->map->matrix[j][i])
	{
		if (data->map->matrix[j][i] == 'N' || data->map->matrix[j][i] == 'E'
		|| data->map->matrix[j][i] == 'W' || data->map->matrix[j][i] == 'S')
			map_check_player(data, i, j, data->map->matrix);
		else if (data->map->matrix[j][i] == 'D')
			map_check_door(data, i, j, data->map->matrix);
		else if (data->map->matrix[j][i] != ' '
			&& data->map->matrix[j][i] != '1' && data->map->matrix[j][i] != '0')
			exit (error_msg("map is incorrect, unrecognized character", data));
		i++;
	}
	i--;
	while (data->map->matrix[j][i] == ' ')
		i--;
	if (data->map->matrix[j][i] != '1')
		exit (error_msg("map border is incorrect", data));
}

void	map_check_border(t_data *data, char **matrix)
{
	int					j;
	unsigned long int	i;

	j = 0;
	while (matrix[j])
	{
		i = 0;
		while (matrix[j][i])
		{
			if (matrix[j][i] == '0')
			{
				if (ft_strlen(matrix[j + 1]) < i || ft_strlen(matrix[j - 1]) < i
					|| !matrix[j + 1][i] || matrix[j + 1][i] == ' '
					|| !matrix[j - 1][i] || matrix[j - 1][i] == ' '
					|| !matrix[j][i + 1] || matrix[j][i + 1] == ' '
					|| !matrix[j][i + 1] || matrix[j][i - 1] == ' ')
					exit (error_msg("border not well closed", data));
			}
			i++;
		}
		j++;
	}
}

//quoi faire des espaces dans la map, erreur ou 
//convertit en zero ou un effet special?

//checker si ok parsing color&texture, peut etre doit on pouvoir mettre des 
//couleurs a la place des textures et inversement, ce serait galere dans la struc

//printf("char = %c & i = %d\n", data->map->matrix[j][i], i);
