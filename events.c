/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:05 by esellier          #+#    #+#             */
/*   Updated: 2025/02/13 19:34:05 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	do_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_escape(data);
	else if (keysym == XK_Left || keysym == XK_Right)
		do_view(data, keysym);
	else if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
		do_move(data, keysym, data->player.position_x, data->player.position_y);
	/*else if (keysym == XK_space)
		do_door(data, data->player.position_x, data->player.position_y);*/
	find_wall(data);
	return (0);
}

void	do_view(t_data *data, int keysym)
{
	if (keysym == XK_Left)
	{
		data->player.angle = data->player.angle + 20;
		if (data->player.angle >= 360)
			data->player.angle = data->player.angle - 360;
	}
	if (keysym == XK_Right)
	{
		data->player.angle = data->player.angle - 20;
		if (data->player.angle <= 0)
			data->player.angle = data->player.angle + 360;
	}
}

void	do_move(t_data *data, int keysym, double tmp_x, double tmp_y)
{
	double	radian;
	int		x;
	int		y;

	radian = (data->player.angle * M_PI) / (double)180.0;
	if (keysym == XK_w)
	{
		tmp_y -= 0.25 * sin(radian);
		tmp_x += 0.25 * cos(radian);
	}
	else if (keysym == XK_s)
	{
		tmp_y += 0.25 * sin(radian);
		tmp_x -= 0.25 * cos(radian);
	}
	else if (keysym == XK_a)
	{
		tmp_y -= 0.25 * cos(radian);
		tmp_x -= 0.25 * sin(radian);
	}
	else if (keysym == XK_d)
	{
		tmp_y += 0.25 * cos(radian);
		tmp_x += 0.25 * sin(radian);
	}
	else
		return ;
	x = (int)floor(tmp_x);
	y = (int)floor(tmp_y);
	if (data->map->matrix[y][x] == '1' || (data->map->matrix[y][x] == 'D'
		&& data->doors.flag == -1))
		return ;
	data->player.position_y = tmp_y;
	data->player.position_x = tmp_x;
}

void	init_events(t_data *data)
{
	mlx_key_hook(data->mlx_window, do_key, data);
	mlx_hook(data->mlx_window, 17, (1L << 5), close_escape, data);
	//mlx_mouse_hook(data->mlx_window, do_mouse, data);
}

int	close_escape(t_data *data)
{
	free_data(data);
	exit (EXIT_SUCCESS);
}
// zoom with the mouse:
/*int	do_mouse(int button, int x, int y, t_data *data)
{
	double	d_x;
	double	d_y;
	double	zoom;

	d_x = ((double)x * 4 / WIDTH - 2) * data->zoom + data->move_x;
	d_y = ((double)y * 4 / HEIGHT - 2) * data->zoom + data->move_y;
	if (button == Button5)
		zoom = 1.10;
	if (button == Button4)
		zoom = 0.90;
	data->move_x = data->move_x + (d_x - data->move_x) * (1 - zoom);
	data->move_y = data->move_y + (d_y - data->move_y) * (1 - zoom);
	data->zoom = data->zoom * zoom;
	create_fractal(data);
	return (0);
}*/
