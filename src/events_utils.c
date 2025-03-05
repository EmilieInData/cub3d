/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:05 by esellier          #+#    #+#             */
/*   Updated: 2025/03/05 14:33:31 by esellier         ###   ########.fr       */
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
