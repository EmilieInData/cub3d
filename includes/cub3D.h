/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:39 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/14 18:20:38 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//Libraries
# include "struct.h"

# include "../gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../ft_printf/ft_printf.h"
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

//parsing_map

//parsing_colors
char	*fc_clean_args(char *str, t_data *data);
void	fc_check_args(char *str, t_data *data, t_color *fc, int *color);
char	**fc_check(char *str, t_data *data, t_color *fc);

//parsing_textures
char	*news_args_check(char *str, t_data *data, char *news);
int		news_check(char *str, t_data *data);

//parsing
void	check_line(char *str, t_data *data);
void	check_map_info(t_data *data, t_map *map, char *str);
void	copy_line(t_data *data, char *str, char **matrix);
void	check_cub_file(t_data *data, char *file);

//utils
void	error_msg(char *str);
void	free_array(char **array);
void	free_data(t_data *data);

//main
void	initialize(t_data *data);
int		main(int argc, char **argv);
int		is_cub(char *argv);

#endif