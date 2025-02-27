/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/02/27 13:50:42 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	map_check_player(t_data *data, int i, int j, char **matrix)
{
	char	*m;

	m = "player is bad positioned, can't be on a border or surrounded by walls";
	if (data->player.news != '0')
		exit (error_msg("there is more than one player", data));
	if (matrix[j + 1][i] != '0' && matrix[j - 1][i] != '0'
		&& matrix[j][i + 1] != '0' && matrix[j][i - 1] != '0'
		&& matrix[j + 1][i] != 'D' && matrix[j - 1][i] != 'D'
		&& matrix[j][i + 1] != 'D' && matrix[j][i - 1] != 'D')
		exit (error_msg(m, data));
	data->player.news = matrix[j][i];
	data->player.position_x = i;// with 0,5 ?
	data->player.position_y = j;// with 0,5 ?
	if (matrix[j][i] == 'E')
		data->player.angle = 0;
	else if (matrix[j][i] == 'N')
		data->player.angle = 90;
	else if (matrix[j][i] == 'W')
		data->player.angle = 180;
	else if (matrix[j][i] == 'S')
		data->player.angle = 270;
}

//floodfill pour checker la position du player? pas enferme quelque part
//checker la position du player, lui mettre un objectif a atteindre comme
//une porte de sortie pour checker si la carte est ok ou un truc a recuperer

//format texture xpm ou png

//faire les signaux (terminal) ctrl c etc