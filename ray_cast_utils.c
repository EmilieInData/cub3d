/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:35:51 by ineimatu          #+#    #+#             */
/*   Updated: 2025/02/18 12:10:07 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ray_projected_up(int angle)
{
    if (angle >= 0 && angle <= 180)
        return (1);
    else
        return (0);
}

int ray_projected_left(int angle)
{
    if (angle >= 90 && angle <= 270)
        return (1);
    else
        return (0);
}

int check_diagonal(char **matrix, t_data *data, int x, int y)
{
    if (wall_in_ascending_diagonal(matrix, data, x, y) == 1 
            && wall_in_descending_diagonal(matrix, data, x, y) == 1)
            return (1);
    else
        return (0);
}

int wall_in_ascending_diagonal(char **matrix, t_data *data, int x, int y)
{
    if (ray_projected_up(data->ray.angle_start) == 0
		&& ray_projected_left(data->ray.angle_start) == 1)
	{
        if (y < 0 && x < 0 )
        {
		    if (y < data->ray.map_y
		    	&& x < data->ray.map_x
		    	&& (matrix[y][x] == '0')
		    	&& matrix[y - 1][x] == '1'
		    	&& matrix[y][x + 1] == '1'
		    	&& (matrix[y - 1][x + 1] == '0'))
		    	return (1);
        }
    }
    if (ray_projected_up(data->ray.angle_start) == 1
		&& ray_projected_left(data->ray.angle_start) == 0)
    {
        printf("Hello\n");
		if (y < 0 && x < 0 )
        {
            if (y < data->ray.map_y
			    && x < data->ray.map_x
			    && (matrix[y][x] == '0')
			    && matrix[y + 1][x] == '1'
			    && matrix[y][x - 1] == '1'
			    && (matrix[y + 1][x - 1] == '0'))
			    return (1);
        }
    }
    return (0);
}

int wall_in_descending_diagonal(char **matrix, t_data *data, int x, int y)
{
    if (ray_projected_up(data->ray.angle_start) == 0
		&& ray_projected_left(data->ray.angle_start) == 1)
	{
        if (y < 0 && x < 0 )
        {
		    if (y < data->ray.map_y
		    	&& x < data->ray.map_x
		    	&& (matrix[y][x] == '0')
		    	&& matrix[y + 1][x] == '1'
		    	&& matrix[y][x + 1] == '1'
		    	&& (matrix[y + 1][x + 1] == '0'))
		    	return (1);
        }
    }
    if (ray_projected_up(data->ray.angle_start) == 1
		&& ray_projected_left(data->ray.angle_start) == 0)
    {
        if (y < 0 && x < 0 )
        {
		    if (y < data->ray.map_y
		    	&& x < data->ray.map_x
		    	&& (matrix[y][x] == '0')
		    	&& matrix[y - 1][x] == '1'
		    	&& matrix[y][x - 1] == '1'
		    	&& (matrix[y - 1][x - 1] == '0'))
		    	return (1);
        }
    }
    return (0);
}