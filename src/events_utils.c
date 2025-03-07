/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:05 by esellier          #+#    #+#             */
/*   Updated: 2025/03/07 16:07:19 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	do_move_up(t_data *data, double tmp_x, double tmp_y, double radian)
{
	double	tmp_yy;
	double	tmp_xx;

	tmp_yy = tmp_y;
	tmp_xx = tmp_x;
	tmp_y -= 0.1001 * sin(radian);
	if (!check_wall_distance(tmp_xx, tmp_y, data))
		data->player.position_y = tmp_y;
	tmp_x += 0.1001 * cos(radian);
	if (!check_wall_distance(tmp_x, tmp_yy, data))
		data->player.position_x = tmp_x;
}

void	do_move_down(t_data *data, double tmp_x, double tmp_y, double radian)
{
	double	tmp_yy;
	double	tmp_xx;

	tmp_yy = tmp_y;
	tmp_xx = tmp_x;
	tmp_y += 0.1001 * sin(radian);
	if (!check_wall_distance(tmp_xx, tmp_y, data))
		data->player.position_y = tmp_y;
	tmp_x -= 0.1001 * cos(radian);
	if (!check_wall_distance(tmp_x, tmp_yy, data))
		data->player.position_x = tmp_x;
}

void	do_move_left(t_data *data, double tmp_x, double tmp_y, double radian)
{
	double	tmp_yy;
	double	tmp_xx;

	tmp_yy = tmp_y;
	tmp_xx = tmp_x;
	tmp_y -= 0.1001 * cos(radian);
	if (!check_wall_distance(tmp_xx, tmp_y, data))
		data->player.position_y = tmp_y;
	tmp_x -= 0.1001 * sin(radian);
	if (!check_wall_distance(tmp_x, tmp_yy, data))
		data->player.position_x = tmp_x;
}

void	do_move_right(t_data *data, double tmp_x, double tmp_y, double radian)
{
	double	tmp_yy;
	double	tmp_xx;

	tmp_yy = tmp_y;
	tmp_xx = tmp_x;
	tmp_y += 0.1001 * cos(radian);
	if (!check_wall_distance(tmp_xx, tmp_y, data))
		data->player.position_y = tmp_y;
	tmp_x += 0.1001 * sin(radian);
	if (!check_wall_distance(tmp_x, tmp_yy, data))
		data->player.position_x = tmp_x;
}

int	do_mouse(int x, int y, t_data *data)
{
	int	tmp_x;

	(void)y;
	tmp_x = x - data->mouse;
	if ((abs(tmp_x)) > 2)
	{
		if (tmp_x >= 0)
			data->player.angle = data->player.angle - (tmp_x * 0.05);
		if (tmp_x < 0)
			data->player.angle = (ceil)(data->player.angle - (tmp_x * 0.05));
		if (data->player.angle > 360)
			data->player.angle = data->player.angle - 360;
		else if (data->player.angle < 0)
			data->player.angle = data->player.angle + 360;
		find_wall(data);
	}
	return (data->mouse = x, 0);
}
