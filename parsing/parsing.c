/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/14 19:06:03 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_line(char *str, t_data *data)
{
	int		i;
	char	*dst;

	i = 0;
	while (str[i] && ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
		i++; //rajouter le retour de ligne "\n" ?
	if (!str[i] && data->map->flag == -1)
		return ;
	if (!str[i] && data->map->flag == 1)
		exit (error_msg("map element is not appropriate", data), 1);
	//str = &str[i];
	if ((str[i] == 'F' || str[i] == 'C') && data->map->flag == -1)
		return (fc_check(&str[i], data));
	if ((str[i] == 'E' || str[i] == 'N' || str[i] == 'S' || str[i] == 'W')
		&& data->map->flag == -1)
		return (news_check(&str[i], data));
	if (str[i] == '1' || str[i] == '0')
	{
		if (data->map->flag == -1)
			check_map_info(data, data->map, str);
		else
			copy_line(data, str, data->map->matrix);
	}
	else
		exit (error_msg("scene element is not appropriate", data), 1);
}

void	check_map_info(t_data *data, t_map *map, char *str)
{
	if (map->no && map->so && map->we && map->ea && map->floor->red != -1
		&& map->floor->green != -1 && map->floor->blue != -1
		&& map->ceiling->red != -1 && map->ceiling->green != -1
		&& map->ceiling->blue != -1)
	{
		map->flag = 1;
		map->matrix = malloc (sizeof (char *));
		if (!map->matrix)
			exit (error_msg("malloc didn't work correctly", data), 1);
		map->matrix[0] = NULL; //peut etre pas necessaire
		copy_line(data, str, map->matrix);
	}
	else
		exit (error_msg("identifier arguments are missing", data), 1);
}

void	copy_line(t_data *data, char *str, char **matrix)
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
		exit (error_msg("malloc didn't work correctly", data), 1);
	ft_strcpy(matrix[j], str);
	matrix[j + 1] = NULL;
}

void	check_cub_file(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		//if (!line)
		//	return (0);
		check_line(line, data);
		free(line);
	}
	close(fd);
}
