/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:39 by ineimatu          #+#    #+#             */
/*   Updated: 2025/02/28 14:14:57 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TILE 			64
# define HEIGHT 		800
# define LENGTH 		1240
# define PICS			5
# define SPRITE_TIME    10

//Libraries
# include "../gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <math.h>
# include <X11/Xlib.h>
# include <sys/time.h>
# include <limits.h>
# include <float.h>
# include "struct.h"

//# define WHITE			0xFFFFFF
//# define BLACK			0x0000
# define PASTEL_PURPLE  0xC3B1E1
# define DARK_PURPLE	0x4B2C58
# define DARK_PINK		0x9B1B30
# define BRIGHT_BLUE	0x1ABC9C

//sprite
int 	do_sprite(t_data *data);
int     do_hook(t_data *data);

//door
int 	door_distance_check(double door, t_data *data);
double	door_distance_calcul(int x, int y, double tmp_x, double tmp_y);
void	do_door(t_data *data);
int     close_door(t_data *data);
int     double_to_int(int door, double player);

//mini_map
void	do_mini_map(t_data *data, char **matrix);
void	put_scaled_image(t_data *data, int x, int y, int color);
int		height_map(char **matrix);
int		width_map(char **matrix);

//events
int		do_key(int keysym, t_data *data);
void	do_view(t_data *data, int keysym);
void	do_move(t_data *data, int keysym, double tmp_x, double tmp_y);
int	    check_wall_distance(double tmp_x, double tmp_y, t_data *data);
int     wall_distance_calcul(int x, int y, double tmp_x, double tmp_y);

//parsing_map
void	map_check(t_data *data, char **matrix);
void	map_check_door(t_data *data, int i, int j, char **matrix); //bonus
void	map_check_first_last_line(t_data *data, int i, int j);
void	map_check_middle_line(t_data *data, int i, int j);
void	map_check_border(t_data *data, char **matrix);

//parsing_colors
char	*fc_clean_args(char *str, t_data *data);
char	*fc_check_args(char *str, t_data *data, int *color);
void	*fc_check(char *str, t_data *data, t_color *fc);

//parsing_textures
void	*news_args_check(char *str, t_data *data, char **news);
void	*news_check(char *str, t_data *data);

//parsing
void	*check_line(char *str, t_data *data);
void	*check_map_info(t_data *data, t_map *map, char *str);
char	**ft_realloc(char **array, char *new_line, t_data *data);
void	check_cub_file(t_data *data, char *file);
void	map_check_player(t_data *data, int i, int j, char **matrix);

//utils
int		error_msg(char *str, t_data *data);
void	free_array(char **array);
void	free_image(t_image *image, t_data *data);
void	free_data(t_data *data);
void	free_doors(t_data *data, t_door *doors);

//initialize
void	initialize_map(t_map *map);
void	initialize_textures(t_files *texture);
void	initialize_door(t_data *data);
void	*initialize(t_data *data);

//main
void	print_data(t_data *data); //to borrow
int		close_escape(t_data *data);
int		is_cub(char *argv);
void	implementation_mlx(t_data *data, char *name);
int		main(int argc, char **argv);

//textures
int     rgb_to_int_floor(t_data *data);
int	    rgb_to_int_ceil(t_data *data);
void	create_struct_files(t_data *data, char *path, t_files *files);
void	get_wall_texture(t_data *data);
t_files *choose_wall_direction(t_data *data, double angle);
void	render_wall(int x, int *y, t_data *data, int *i);
int 	get_pixel_texture(t_files *files, int x, int y);
void	print_pixel(t_data *data, int x, int y, int color);
void    put_pixel_image(t_image *image, int x, int y, int color);
void    free_textures(t_data *data);

//ray cast
void	init_ray(t_data *data);
void    next_vertical(t_data *data, double x_a, double b_y, double b_x, double radians);
void    vertical_check(t_data *data, double radians);
void	next_checks(t_data *data, double a_x, double a_y, double radians);
void    horizontal_check(t_data *data, double radians);
void	find_wall(t_data *data);
int     find_distance_v(t_data *data, double x, double y);
int     find_distance_h(t_data *data, double x, double y);
void	find_shortest_distance(t_data *data);
void	print_ray(t_ray ray);
void    map_size(t_data *data);
void    wall_height(t_data *data, int x);
int     ray_projected_up(int angle);
int     ray_projected_left(int angle);
int     check_diagonal(char **matrix, t_data *data, int x, int y);
int     wall_in_ascending_diagonal(char **matrix, t_data *data, int x, int y);
int     wall_in_descending_diagonal(char **matrix, t_data *data, int x, int y);

#endif
