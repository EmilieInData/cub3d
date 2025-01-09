/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:39 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/09 19:56:07 by esellier         ###   ########.fr       */
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

int		main(int argc, char **argv);
int		is_cub(char *argv);
void	ft_exit(int ex_stat, char *message);

//parsing

//utils
void	*error_msg(char *str);
void	*initialize(t_data *data);

#endif