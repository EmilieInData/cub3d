/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:05 by esellier          #+#    #+#             */
/*   Updated: 2025/02/07 17:48:44 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	do_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_escape(data);
	if (keysym == XK_Left || keysym == XK_Right)
		do_view(data, keysym);
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
		do_move(data, data->player.position_x, data->player.position_y, keysym);
	if (keysym == XK_space)
		do_door(data, data->player.position_x, data->player.position_y);
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
	//raycasting
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->image->img_add, 0, 0);
}

void	do_move(t_data *data, int x, int y, int keysym)
{
	if (keysym == XK_w && data->map->matrix[y - 1][x] == '0')
		data->player.position_y = y - 1;
	else if (keysym == XK_w && data->map->matrix[y - 1][x] == 'D'
		&& data->doors.flag == 0)
		data->player.position_y = y - 2;
	else if (keysym == XK_s && data->map->matrix[y + 1][x] == '0')
		data->player.position_y = y + 1;
	else if (keysym == XK_a && data->map->matrix[y][x - 1] == '0')
		data->player.position_x = x - 1;
	else if (keysym == XK_d && data->map->matrix[y][x + 1] == '0')
		data->player.position_x = x + 1;
	else
		return ;
	//raycasting + position player sur minimap
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->image->img_add, 0, 0);
	//ou a la fin de la fonction de raycasting.
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

//faire sprite sur la porte avec la couleur des neons qui change et porte qui s'ouvre