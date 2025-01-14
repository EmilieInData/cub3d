/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:16:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/14 18:24:17 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	initialize(t_data *data)
{
	data = malloc (sizeof t_data);
	if (!data)
		exit (error_msg("malloc didn't work correctly", NULL), 1);
	data->map = malloc (sizeof t_map);
	if (!data->map)
		exit (error_msg("malloc didn't work correctly", data), 1);
	//mlx
	//mlx_window
	data->map->no = NULL;
	data->map->so = NULL;
	data->map->we = NULL;
	data->map->ea = NULL;
	data->map->floor->red = -1;
	data->map->floor->green = -1;
	data->map->floor->blue = -1;
	data->map->ceiling->red = -1;
	data->map->ceiling->green = -1;
	data->map->ceiling->blue = -1;
	data->map->matrix = NULL;
	data->map->flag = -1;
	/*data->player = malloc (sizeof t_player);
	if (!data->player)
		exit (error_msg("malloc didn't work correctly", data), 1);*/ //pas besoin d'alloquer de la memoire si seulement int 
	data->player->news = '0';
	data->player->position_x = -1;
	data->player->position_y = -1;
	data->player->orientation = -1;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 2)
		exit (error_msg("wrong number of arguments", NULL), 1);
	if (argc == 2 && (is_cub(argv[1]) == 0))
		ft_printf("Good job\n"); // need to erase before evaluation
	initialize(data);
	check_cub_file(data, argv[1]);
	return (0);
}

int	is_cub(char *argv)
{
	int		i;

	i = ft_strlen(argv) - 1;
	if (!(argv[i - 3] == '.' && argv[i - 2] == 'c' && argv[i - 1] == 'u'
			&& argv[i] == 'b'))
		exit (error_msg("map format is incorrect", NULL), 1);
	else
		return (0);
}
