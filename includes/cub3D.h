/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:39 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/30 12:23:44 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//Libraries
# include "struct.h"
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

# define TILE 64
# define HEIGHT 800
# define LENGTH 1280

//events
int		do_key(int keysym, t_data *data);
void	init_events(t_data *data);
int		close_escape(t_data *data);

//parsing_player
void	map_check_player(t_data *data, int i, int j, char **matrix);

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

//utils
int		error_msg(char *str, t_data *data);
void	free_array(char **array);
void	free_data(t_data *data);

//main
void	print_data(t_data *data);
void	*initialize(t_data *data);
int		main(int argc, char **argv);
int		is_cub(char *argv);

void next_vertical(t_data *data, int x_a, int b_y, int b_x);
void vertical_check(t_data *data);
void	next_checks(t_data *data, int a_x, int a_y);
void horizontal_check(t_data *data);
void	find_wall(t_data *data);
int find_distance_v(t_player player, int x, int y);
int find_distance_h(int x, int y);


#endif