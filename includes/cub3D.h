/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:39 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/20 14:13:48 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
# include "struct.h"


# define TILE 64
# define HEIGHT 800
# define LENGTH 1280

int		main(int argc, char **argv);
int		is_cub(char *argv);
void	ft_exit(int ex_stat, char *message);
//void mlx_functions(t_game *game);
void next_vertical(t_data * data, int x_a, int b_y, int b_x);
void vertical_check(t_data *data);
void	next_checks(t_data *data, int a_x, int a_y);
void horizontal_check(t_data *data);
void	find_wall(t_data *data);
int find_distance_v(t_player player, int x, int y);
int find_distance_h(int x, int y);
void init_map(t_data *data);
int	error_msg(char *str, t_data *data);

#endif
