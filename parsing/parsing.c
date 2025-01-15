/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/15 17:31:52 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*check_line(char *str, t_data *data)
{
	int		i;

	i = 0;
	while (str[i] && ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
		i++; //rajouter le retour de ligne "\n" ?
	if (!str[i] && data->map->flag == -1)
		return (NULL);
	if (!str[i] && data->map->flag == 1)
		exit (error_msg("map element is not appropriate", data));
	//str = &str[i];
	if (str[i] == 'F' && data->map->flag == -1)
		return (fc_check(&str[i], data, data->map->floor));
	if (str[i] == 'C' && data->map->flag == -1)
		return (fc_check(&str[i], data, data->map->ceiling));
	if ((str[i] == 'E' || str[i] == 'N' || str[i] == 'S' || str[i] == 'W')
		&& data->map->flag == -1)
		return (news_check(&str[i], data));
	if (str[i] == '1' || str[i] == '0')
	{
		if (data->map->flag == -1)
			return (check_map_info(data, data->map, str));
		else
			return (copy_line(data, str, data->map->matrix));
	}
	else
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
		map->matrix = malloc (sizeof (char *));
		if (!map->matrix)
			exit (error_msg("malloc didn't work correctly", data));
		map->matrix[0] = NULL; //peut etre pas necessaire
		copy_line(data, str, map->matrix);
	}
	else
		exit (error_msg("identifier arguments are missing", data));
	return (NULL);
}

void	*copy_line(t_data *data, char *str, char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (matrix[j])
		j++;
	matrix[j] = malloc (i + 1 * sizeof (char));
	if (!matrix[j])
		exit (error_msg("malloc didn't work correctly", data));
	ft_strcpy(matrix[j], str);
	matrix[j + 1] = NULL;
	return (NULL);
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
