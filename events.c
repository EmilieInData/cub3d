/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:05 by esellier          #+#    #+#             */
/*   Updated: 2025/03/03 19:26:35 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	do_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_escape(data);
	if (keysym == XK_Left || keysym == XK_Right)
	{
		do_view(data, keysym);
		find_wall(data);
	}
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
	{
		do_move(data, keysym, data->player.position_x, data->player.position_y);
		find_wall(data);
	}
	if (keysym == XK_space)
		do_door(data);
	return (0);
}

void	do_view(t_data *data, int keysym)
{
	if (keysym == XK_Left)
	{
		data->player.angle = data->player.angle + 5;
		if (data->player.angle >= 360)
			data->player.angle = data->player.angle - 360;
	}
	if (keysym == XK_Right)
	{
		data->player.angle = data->player.angle - 5;
		if (data->player.angle <= 0)
			data->player.angle = data->player.angle + 360;
	}
}

void	do_move(t_data *data, int keysym, double tmp_x, double tmp_y)
{
	double	radian;
	double tmp_YY;
	double tmp_XX;

	tmp_YY = tmp_y;
	tmp_XX = tmp_x;
	radian = (data->player.angle * M_PI) / (double)180.00;
	if (keysym == XK_w)
	{
		tmp_y -= 0.1001 * sin(radian);
		if (!check_wall_distance(tmp_XX, tmp_y, data))
			data->player.position_y = tmp_y;
		tmp_x += 0.1001 * cos(radian);
		if (!check_wall_distance(tmp_x, tmp_YY, data))
			data->player.position_x = tmp_x;
	}
	else if (keysym == XK_s)
	{
		tmp_y += 0.1001 * sin(radian);
		if (!check_wall_distance(tmp_XX, tmp_y, data))
			data->player.position_y = tmp_y;
		tmp_x -= 0.1001 * cos(radian);
		if (!check_wall_distance(tmp_x, tmp_YY, data))
			data->player.position_x = tmp_x;
	}
	else if (keysym == XK_a)
	{
		tmp_y -= 0.1001 * cos(radian);
		if (!check_wall_distance(tmp_XX, tmp_y, data))
			data->player.position_y = tmp_y;
		tmp_x -= 0.1001 * sin(radian);
		if (!check_wall_distance(tmp_x, tmp_YY, data))
			data->player.position_x = tmp_x;
	}
	else if (keysym == XK_d)
	{
		tmp_y += 0.1001 * cos(radian);
		if (!check_wall_distance(tmp_XX, tmp_y, data))
			data->player.position_y = tmp_y;
		tmp_x += 0.1001 * sin(radian);
		if (!check_wall_distance(tmp_x, tmp_YY, data))
			data->player.position_x = tmp_x;
	}
}

int	check_wall_distance(double tmp_x, double tmp_y, t_data *data)
{
	// int	i;
	// int	j;
	int	x;
	int	y;

	// j = -1;
	// while (j < 2)
	// {
	// 	i = -1;
	// 	while (i < 2)
	// 	{
			x = (int)floor(tmp_x); //+i
			y = (int)floor(tmp_y); // + j
			if ((y < 0 || x < 0) || ((data->map->matrix[y][x] == '1'
					|| (data->map->matrix[y][x] == 'D'
					&& data->doors->flag == -1))))
				//&& wall_distance_calcul(x, y, tmp_x, tmp_y)))
				return (1);
	// 		i++;
	// 	}
	// 	j++;
	// }
	return (0);
}

// int	wall_distance_calcul(int x, int y, double tmp_x, double tmp_y)
// {
// 	double	dx;
// 	double	dy;

// 	dx = fabs(tmp_x - floor(x + 0.5));
// 	dy = fabs(tmp_y - floor(y + 0.5));
// 	if (sqrt(dx * dx + dy * dy) < 0.7)
// 		return (1);
// 	return (0);
// }

	// x = (int)round(tmp_x);
	// y = (int)round(tmp_y);
	// printf("tmp_x = %f, tmp_y= %f\n", tmp_x, tmp_y);
	// printf("X = %d, Y = %d\n", x, y);
	// printf("data->map->matrix[y][x] = %c \n", data->map->matrix[y][x]);
	// if (data->map->matrix[y][x] == '1' || (data->map->matrix[y][x] == 'D'
	// 	&& data->doors->flag == -1))
	// 	return ;

// if (radian >= 0 && radian <= M_PI / 2)
	// {
	// 	x = (int)ceil(tmp_x + 1);
	// 	y = (int)floor(tmp_y + 1);
	// }
	// if (radian > M_PI / 2 && radian <= M_PI)
	// {
	// 	x = (int)floor(tmp_x + 1);
	// 	y = (int)floor(tmp_y + 1);
	// }
	// if (radian > M_PI && radian <= (3 * M_PI) / 2)
	// {
	// 	x = (int)floor(tmp_x + 1);
	// 	y = (int)ceil(tmp_y - 1);
	// }
	// else
	// //if (radian > (3 * M_PI) / 2 && radian <= 2 * M_PI)
	// {
	// 	x = (int)ceil(tmp_x - 1);
	// 	y = (int)ceil(tmp_y - 1);
	// }
	
	// if (cos(radian) >= 0) // Vers la droite
    // 	x = (int)ceil(tmp_x - 1);
	// else // Vers la gauche
    // 	x = (int)floor(tmp_x + 1);
	// if (sin(radian) >= 0) // Vers le bas
    // 	y = (int)ceil(tmp_y - 1);
	// else // Vers le haut
    // 	y = (int)floor(tmp_y + 1);
	
	// if (data->map->matrix[y + 1][x] == '1' || data->map->matrix[y][x + 1] == '1'
	// || data->map->matrix[y - 1][x] == '1' || data->map->matrix[y][x - 1] == '1'
	// || data->map->matrix[y + 1][x] == 'D' || data->map->matrix[y][x + 1] == 'D'
	// || data->map->matrix[y - 1][x] == 'D' || data->map->matrix[y][x - 1] == 'D')
	// 	return ;
