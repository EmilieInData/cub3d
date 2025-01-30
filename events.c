/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:05 by esellier          #+#    #+#             */
/*   Updated: 2025/01/21 17:52:21 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	do_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_escape(data);
	if (keysym == XK_Left)
	
	if (keysym == XK_Right)
	
	if (keysym == XK_w)
	
	if (keysym == XK_a)
	
	if (keysym == XK_s)

	if (keysym == XK_d)
	
	//recreat the image;
	return (0);
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

void	init_events(t_data *data)
{
	mlx_key_hook(data->window, do_key, data);
	mlx_hook(data->window, 17, (1L << 5), close_escape, data);
	mlx_mouse_hook(data->window, do_mouse, data);
}

int	close_escape(t_data *data)
{
	mlx_destroy_image(data->mlx, data->image->img_add);//changer le deuxieme arg
	mlx_destroy_window(data->mlx, data->mlx_window);
	mlx_destroy_display(data->mlx);
	free (data);
	exit (EXIT_SUCCESS);
}

◦ The left and right arrow keys of the keyboard must allow you to look left and
right in the maze.
◦ The W, A, S, and D keys must allow you to move the point of view through
the maze. //player movement