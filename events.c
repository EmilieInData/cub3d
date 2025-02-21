/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:05 by esellier          #+#    #+#             */
/*   Updated: 2025/02/21 14:12:54 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	do_key(int keysym, t_data *data)
{
	/*if (!data->texture_north)
		get_wall_texture(data);*/
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
	/*if (keysym == XK_space)
		do_door(data, data->player.position_x, data->player.position_y);*/	
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
	int		x;
	int		y;

	radian = (data->player.angle * M_PI) / (double)180.0;
	if (keysym == XK_w)
	{
		tmp_y -= 0.1 * sin(radian);
		tmp_x += 0.1 * cos(radian);
	}
	else if (keysym == XK_s)
	{
		tmp_y += 0.1 * sin(radian);
		tmp_x -= 0.1 * cos(radian);
	}
	else if (keysym == XK_a)
	{
		tmp_y -= 0.1 * cos(radian);
		tmp_x -= 0.1 * sin(radian);
	}
	else if (keysym == XK_d)
	{
		tmp_y += 0.1 * cos(radian);
		tmp_x += 0.1 * sin(radian);
	}
	else
		return ;
	x = (int)ceil(tmp_x);
	y = (int)ceil(tmp_y);
	//printf("TEST2_position_y = %f\n position_x = %f \n matrix = %c\n", data->player.position_y, data->player.position_x, data->map->matrix[y][x]);
	if (data->map->matrix[y][x] == '1' || (data->map->matrix[y][x] == 'D'
		&& data->doors.flag == -1))
		return ;
	data->player.position_y = tmp_y;
	data->player.position_x = tmp_x;
	//printf("TEST_3position_y = %f\n position_x = %f \n matrix = %c\n", data->player.position_y, data->player.position_x, data->map->matrix[y][x]);
}


void	init_events(t_data *data)
{
	mlx_hook(data->mlx_window, 2, (1L<<0), do_key, data);
	mlx_hook(data->mlx_window, 17, (1L << 5), close_escape, data);
	mlx_hook(data->mlx_window, 6, 1L << 6, do_mouse, data); //PointerMotionMask
}

int	close_escape(t_data *data)
{
	free_data(data);
	exit (EXIT_SUCCESS);
}

int do_mouse(int x, int y, t_data *data)
{
	int	movement;

	(void)y;
	movement = 0;
	if (data->mouse_position)
	{
		data->mouse_position = 0;
		return (0);
	}
	movement = x - (LENGTH / 2);
	if (movement)
	{
		data->player.angle -= movement * ROTATION;
		data->player.angle = fmod(data->player.angle, 360);
		if (data->player.angle < 0)
			data->player.angle += 360;
		find_wall(data);
	}
	data->mouse_position = 1;
	mlx_mouse_move(data->mlx, data->mlx_window,
		LENGTH / 2, HEIGHT / 2);
	return (0);
}