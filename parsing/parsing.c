/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/03/05 12:39:11 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*check_line(char *str, t_data *data)
{
	int		i;

	i = 0;
	while (str[i] && ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!str[i] && data->map->flag == -1)
		return (NULL);
	if (!str[i] && data->map->flag == 1)
		exit (error_msg("map cannot have empty line", data));
	if (str[i] == 'F' && data->map->flag == -1)
		return (fc_check(&str[i], data, &data->map->floor));
	if (str[i] == 'C' && data->map->flag == -1)
		return (fc_check(&str[i], data, &data->map->ceiling));
	if ((str[i] == 'E' || str[i] == 'N' || str[i] == 'S' || str[i] == 'W')
		&& data->map->flag == -1)
		return (news_check(&str[i], data));
	if (str[i] == '1' || str[i] == '0')
	{
		if (data->map->flag == -1)
			return (check_map_info(data, data->map, str));
		return (data->map->matrix = ft_realloc(data->map->matrix, str, data));
	}
	if (data->map->flag == 1)
		exit (error_msg("map border is incorrect", data));
	exit (error_msg("scene element is not appropriate", data));
}

void	*check_map_info(t_data *data, t_map *map, char *str)
{
	if (map->no && map->so && map->we && map->ea && map->floor.red != -1
		&& map->floor.green != -1 && map->floor.blue != -1
		&& map->ceiling.red != -1 && map->ceiling.green != -1
		&& map->ceiling.blue != -1)
	{
		map->flag = 1;
		map->matrix = malloc (2 * sizeof(char *));
		if (!map->matrix)
			exit (error_msg("malloc didn't work correctly", data));
		map->matrix[0] = strdup(str);
		if (!map->matrix[0])
			exit (error_msg("malloc didn't work correctly", data));
		map->matrix[1] = NULL;
	}
	else
		exit (error_msg("it miss identifier arguments before the map", data));
	return (NULL);
}

char	**ft_realloc(char **array, char *str, t_data *data)
{
	int		i;
	char	**tmp;

	i = 0;
	while (array[i])
		i++;
	tmp = malloc ((i + 2) * sizeof(char *));
	if (!tmp)
		exit (error_msg("malloc didn't work correctly", data));
	i = 0;
	while (array[i])
	{
		tmp[i] = ft_strdup(array[i]);
		if (!tmp[i])
			exit (error_msg("malloc didn't work correctly", data));
		i++;
	}
	tmp[i] = ft_strdup(str);
	if (!tmp[i])
		exit (error_msg("malloc didn't work correctly", data));
	tmp[i + 1] = NULL;
	free_array (array);
	return (tmp);
}

void	check_cub_file(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_line(line, data);
		free(line);
	}
	close(fd);
}

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
	data->player.position_x = i + 0.5;
	data->player.position_y = j + 0.5;
	if (matrix[j][i] == 'E')
		data->player.angle = 0;
	else if (matrix[j][i] == 'N')
		data->player.angle = 90;
	else if (matrix[j][i] == 'W')
		data->player.angle = 180;
	else if (matrix[j][i] == 'S')
		data->player.angle = 270;
}
