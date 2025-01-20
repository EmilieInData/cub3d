/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:50:23 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/20 14:15:55 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/struct.h"
#include "includes/cub3D.h"


void init_map(t_data *data)
{
	data = malloc (sizeof (t_data));
	if (!data)
		exit (error_msg("malloc didn't work correctly", NULL));
	data->map = malloc (sizeof (t_map));
	if (!data->map)
		exit(error_msg("malloc didn't work correctly", data));
	//mlx_window
	data->map->no = NULL;
	data->map->so = NULL;
	data->map->we = NULL;
	data->map->ea = NULL;
	data->map->floor.red = -1;
	data->map->floor.green = -1;
	data->map->floor.blue = -1;
	data->map->ceiling.red = -1;
	data->map->ceiling.green = -1;
	data->map->ceiling.blue = -1;
	data->map->matrix[] = {1,1,1,1,1,1,1,
		1,0,1,0,1,1,1,
		1,0,0,0,0,1,1,
		1,0,P,0,0,0,1,
		1,0,0,0,0,0,1,
		1,1,1,1,1,1,1};
	data->map->flag = -1;
	/*data->player = malloc (sizeof (t_player));
	if (!data->player)
		exit (error_msg("malloc didn't work correctly", data), 1);*/ //pas besoin d'alloquer de la memoire si seulement int
	data.player.news = '0';
	data.player.position_x = 2;
	data.player.position_y = 3;
	data.player.angle = 60;
	data.ray.dist_h = 0;
	data.ray.dist_v = 0;
	return (data);
}

int	error_msg(char *str, t_data *data)
{
	write(2, "Error\n", 6);
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
	if (data)
		free_data(data);
	return (1);
}
