/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:39 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/13 20:12:11 by esellier         ###   ########.fr       */
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
# include "./struct.h"
# include <X11/Xlib.h> // I had it in Fractol I don't know for the moment if we need it

//main
void	initialize(t_data *data);
int		main(int argc, char **argv);
int		is_cub(char *argv);
void	ft_exit(int ex_stat, char *message);

//parsing
void	fc_color_struc(t_data *data, t_color *fc, int *color, char *tmp);
char	*fc_quite_space(char *str, t_data *data, char *tmp);
char	*fc_clean_line(char *str, t_data *data);
void	fc_control_args(char *str, t_data *data);
char	**fc_check(char *str, t_data *data, t_color *fc);
char	*news_args_check(char *str, t_data *data, char *news);
int		news_check(char *str, t_data *data);
void	*check_line(char *str, t_data *data);

//utils
void	error_msg(char *str);
void	free_array(char **array);
void	free_data(t_data *data);

#endif