/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:16:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/13 15:27:00 by esellier         ###   ########.fr       */
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
	data->map->height = -1;
	data->map->lenght = -1;
	data->map->matrix = NULL;
	/*data->player = malloc (sizeof t_player);
	if (!data->player)
		exit (error_msg("malloc didn't work correctly", data), 1);*/ //pas besoin d'alloquer de la memoire si seulement int 
	data->player->position_x = -1;
	data->player->position_y = -1;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 2)
		ft_exit(1, "Error, wrong number of arguments\n");
	if (argc == 2 && (is_cub(argv[1]) == 0))
		ft_printf("Good job\n");
	initialize(data);
	return (0);
}

void	ft_exit(int ex_stat, char *message)
{
	ft_printf(message);
	exit(ex_stat);
}

int	is_cub(char *argv)
{
	int		i;

	i = ft_strlen(argv) - 1;
	if (!(argv[i - 3] == '.' && argv[i - 2] == 'c' && argv[i - 1] == 'u'
			&& argv[i] == 'b'))
		ft_exit(1, "Map format is incorrect\n"); // i think we need to put "error" + this message as indicated in the subject
	else
		return (0);
}
