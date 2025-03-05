/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:05 by esellier          #+#    #+#             */
/*   Updated: 2025/03/05 12:32:08 by esellier         ###   ########.fr       */
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

	radian = (data->player.angle * M_PI) / (double)180.00;
	if (keysym == XK_w)
		do_move_up(data, tmp_x, tmp_y, radian);
	else if (keysym == XK_s)
		do_move_down(data, tmp_x, tmp_y, radian);
	else if (keysym == XK_a)
		do_move_left(data, tmp_x, tmp_y, radian);
	else if (keysym == XK_d)
		do_move_right(data, tmp_x, tmp_y, radian);
}

int	check_wall_distance(double tmp_x, double tmp_y, t_data *data)
{
	int	x;
	int	y;

	x = (int)floor(tmp_x);
	y = (int)floor(tmp_y);
	if ((y < 0 || x < 0) || ((data->map->matrix[y][x] == '1'
			|| (data->map->matrix[y][x] == 'D' && data->doors->flag == -1))))
		return (1);
	return (0);
}

int	close_escape(t_data *data)
{
	free_data(data);
	exit (EXIT_SUCCESS);
}
