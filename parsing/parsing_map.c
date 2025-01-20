/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/20 19:00:32 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	map_check(t_data *data, char **matrix)
{
	int	j;

	j = 1;
	map_check_first_last_line(data, 0, 0);
	while (matrix[j + 1])
	{
		map_check_middle_line(data, 0, j);
		j++;
	}
	map_check_first_last_line(data, 0, j);
}

void	map_check_player(t_data *data, char c, int i, int j)
{
	char	*m;

	m = "player is bad positioned, can't be on a border or surrounded by walls";
	if (data->player.news != '0')
		exit (error_msg("there is more than one player", data)); //without 'D' for no bonus part
	if (data->map->matrix[j + 1][i] != '0' && data->map->matrix[j - 1][i] != '0'
		&& data->map->matrix[j][i + 1] != '0' && data->map->matrix[j][i - 1] != '0'
		&& data->map->matrix[j + 1][i] != 'D' && data->map->matrix[j - 1][i] != 'D'
		&& data->map->matrix[j][i + 1] != 'D' && data->map->matrix[j][i - 1] != 'D')
		exit (error_msg(m, data));
	data->player.news = c;
	data->player.position_x = i;
	data->player.position_y = j;
	if (c == 'E')
		data->player.angle = 0;
	else if (c == 'N')
		data->player.angle = 90;
	else if (c == 'W')
		data->player.angle = 180;
	else if (c == 'S')
		data->player.angle = 270;
}

void	map_check_door(t_data *data, int i, int j) //bonus
{
	char	*m;

	m = "door is bad implanted, can't be on a border or surrounded by walls";
	if ((data->map->matrix[j + 1][i] == '0' && data->map->matrix[j - 1][i] == '0'
		&& data->map->matrix[j][i + 1] == '1' && data->map->matrix[j][i - 1] == '1')
		|| (data->map->matrix[j + 1][i] == '1' && data->map->matrix[j - 1][i] == '1'
		&& data->map->matrix[j][i + 1] == '0' && data->map->matrix[j][i - 1] == '0'))
		return ;
	else
		exit (error_msg(m, data));
}

void	map_check_first_last_line(t_data *data, int i, int j)
{
	while (data->map->matrix[j][i] && data->map->matrix[j][i] == ' ') //+ char 9 a 12 ?
		i++;
	//if (!data->map->matrix[j][i])
	//	exit (error_msg("map cannot finish by empty line", data));
	while (data->map->matrix[j][i])
	{
		if (data->map->matrix[j][i] == 'N' || data->map->matrix[j][i] == 'E'
			|| data->map->matrix[j][i] == 'W' || data->map->matrix[j][i] == 'S')
			exit (error_msg("player can't be in the border", data));
		else if (data->map->matrix[j][i] == 'D')
			exit (error_msg("a door can't be in the border", data));
		else if (data->map->matrix[j][i] != '1' && data->map->matrix[j][i] != ' ')
			exit (error_msg("map border is incorrect", data));
		i++;
	}
}

void	map_check_middle_line(t_data *data, int i, int j)
{
	while (data->map->matrix[j][i] && data->map->matrix[j][i] == ' ')
		i++;
	//if (!data->map->matrix[j][i])
	//	exit (error_msg("map cannot have empty line", data));
	if (data->map->matrix[j][i] != '1')
		exit (error_msg("map border is incorrect", data));
	while (data->map->matrix[j][i])
	{
		if (data->map->matrix[j][i] == 'N' || data->map->matrix[j][i] == 'E'
		|| data->map->matrix[j][i] == 'W' || data->map->matrix[j][i] == 'S')
			map_check_player(data, data->map->matrix[j][i], i, j);
		else if (data->map->matrix[j][i] == 'D')
			map_check_door(data, i, j);
		else if (data->map->matrix[j][i] != ' ' && data->map->matrix[j][i] != '1'
			&& data->map->matrix[j][i] != '0')
			exit (error_msg("map incorrect, not filled correctly", data));
		i++;
	}
	while (data->map->matrix[j][i--] == ' ') //checker pk ne fonctionne pas avec un espace
		i--;
	printf("char = %c & i = %d\n", data->map->matrix[j][i], i);
	if (data->map->matrix[j][i] != '1')
		exit (error_msg("map border is incorrect", data));
}

//quoi faire des espaces dans la map, erreur ou 
//convertit en zero ou un effet special?

//checker que murs sont bien fermes par leur position dans l'array
//floodfill pour checker la position du player? pas enferme quelque part

//checker la position du player, lui mettre un objectif a atteindre comme
//une porte de sortie pour checker si la carte est ok ou un truc a recuperer

//checker si ok parsing color et texture, peut etre doit on pouvoir mettre des 
//couleurs a la place des textures et inversement, ce serait galere dans la structure

//printf("char = %c & i = %d\n", data->map->matrix[j][i], i);

//quand seulement une ligne vide apres la map l'erreur ne fonctionne pas
//si pas vide ou deuxieme ligne et plus fonctionne