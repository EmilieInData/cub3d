/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:16:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/03/05 14:33:43 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_cub(char *argv)
{
	int	i;
	int	fd;

	fd = -1;
	i = ft_strlen(argv) - 1;
	if (!(argv[i - 3] == '.' && argv[i - 2] == 'c' && argv[i - 1] == 'u'
			&& argv[i] == 'b'))
		exit (error_msg("map file is incorrect", NULL));
	else
	{
		if (access(argv, F_OK) == 0 && access(argv, R_OK) == 0)
			fd = open(argv, O_RDONLY);
		if (fd == -1 || access(argv, F_OK) != 0 || access(argv, R_OK) != 0)
			exit (error_msg("map file is not open", NULL));
	}
	return (0);
}

void	implementation_mlx(t_data *data, char *name)
{
	data->image = malloc(sizeof(t_image));
	if (!data->image)
		exit (error_msg("malloc didn't work correctly", data));
	data->mlx = mlx_init();
	if (!data->mlx)
		exit (error_msg("mlx_init didn't works properly", data));
	data->mlx_window = mlx_new_window(data->mlx, LENGTH, HEIGHT, name);
	if (!data->mlx_window)
		exit (error_msg("mlx_new_window didn't works properly", data));
	data->image->img_add = mlx_new_image(data->mlx, LENGTH, HEIGHT);
	if (!data->image->img_add)
		exit (error_msg("mlx_new_image didn't works properly", data));
	data->image->pix_add = mlx_get_data_addr(data->image->img_add,
			&data->image->bit_pix, &data->image->length_line,
			&data->image->endian);
	get_wall_texture(data);
	initialize_door(data);
	if (&data->doors->sprite[3])
		data->texture_door = data->doors->sprite[3];
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 2)
		exit (error_msg("wrong number of arguments", NULL));
	is_cub(argv[1]);
	data = initialize(data);
	check_cub_file(data, argv[1]);
	map_check(data, data->map->matrix);
	implementation_mlx(data, "cub3D_map");
	find_wall(data);
	mlx_loop_hook(data->mlx, do_hook, data);
	mlx_hook(data->mlx_window, 2, (1L << 0), do_key, data);
	mlx_hook(data->mlx_window, 17, (1L << 5), close_escape, data);
	//mlx_mouse_hook(data->mlx_window, do_mouse, data);
	mlx_loop(data->mlx);
	free_data(data);
	return (0);
}
