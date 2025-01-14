/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:33:29 by esellier          #+#    #+#             */
/*   Updated: 2025/01/14 18:02:04 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*news_args_check(char *str, t_data *data, char *news)
{
	int		i;
	char	*tmp;

	i = 0;
	if (news) // checker si pas doublons
		exit (error_msg("duplicate texture element ", data), 1);
	while (str[i])
	{
		while (str[i] && str[i] == ' ' || str[i] == '	')
			i++;
		if (!str[i])
			exit (error_msg("texture path is missing", data), 1);
		str = &str[i];
		i = 0;
		while (str[i] && str[i] != ' ' && str[i] != '	')
			i++;
		if (str[i])//checker si plusieurs arg ou finit par autre chose qu'un caractere(pas ok espace apres)
			exit (error_msg("texture argument is not appropriate", data), 1);
		tmp = malloc(i + 1 * sizeof(char));
		if (!tmp)
			exit (error_msg("malloc didn't work correctly", data), 1);
		ft_strlcpy(tmp, str, i); // A FAIRE: verifier la taille
		//checker si le chemin d'acces est ok? ici ou plus tard?
	}
	news = tmp; // A FAIRE = checker si change bien la structure
}

int	news_check(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (str[i] == 'N' && str[i + 1] && str[i + 1] == 'O' && str[i + 2]
		&& (str[i + 2] == ' ' || str[i + 2] == '	'))
		return (news_args_check(&str[i + 2], data, data->map->no), 0);
	else if (str[i] == 'S' && str[i + 1] && str[i + 1] == 'O' && str[i + 2]
		&& (str[i + 2] == ' ' || str[i + 2] == '	'))
		return (news_args_check(&str[i + 2], data, data->map->so), 0);
	else if (str[i] == 'W' && str[i + 1] && str[i + 1] == 'E' && str[i + 2]
		&& (str[i + 2] == ' ' || str[i + 2] == '	'))
		return (news_args_check(&str[i + 2], data, data->map->we), 0);
	else if (str[i] == 'E' && str[i + 1] && str[i + 1] == 'A' && str[i + 2]
		&& (str[i + 2] == ' ' || str[i + 2] == '	'))
		return (news_args_check(&str[i + 2], data, data->map->ea), 0);
	exit (error_msg("identifier argument is not appropriate", data), 1);
}

void	*check_line(char *str, t_data *data)
{
	int		i;
	char	*dst;

	i = 0;
	while (str[i] && ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!str[i])
		return ;
	//str = &str[i]; //virer ce qu'il y a avant les characteres seulement si pas la map, checker pour le mec dans l'arg de la fonction
	if (str[i] == 'F' || str[i] == 'C')
		return (fc_check(&str[i], data));
	if (str[i] == 'E' || str[i] == 'N' || str[i] == 'S' || str[i] == 'W')
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
