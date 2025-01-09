/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:54:16 by esellier          #+#    #+#             */
/*   Updated: 2025/01/09 20:03:38 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	*error_msg(char *str)
{
	write(2, "Error\n", 6);
	while (*str)
		write(2, str**, 1);
	write(2, "\n", 1);
}

void	*initialize(t_data *data) //perhaps we need to cut in two and initialize all struc here
{
	data = malloc (sizeof t_data);
	if (!data)
		exit (error_msg("malloc didn't work correctly"), 1);
	data->map->no = NULL;
	data->map->so = NULL;
	data->map->we = NULL;
	data->map->ea = NULL;
	data->map->f_r = -1;
	data->map->f_g = -1;
	data->map->f_b = -1;
	data->map->c_r = -1;
	data->map->c_g = -1;
	data->map->c_b = -1;
	//data->map->array = NULL; // not sure i need
	//player??
}