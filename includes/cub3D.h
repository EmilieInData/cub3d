/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:39 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/14 11:09:00 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

typedef struct s_game
{
	void *mlx;
	void *mlx_win;
	size_t width;
	size_t height;
}		t_game;

int		main(int argc, char **argv);
int		is_cub(char *argv);
void	ft_exit(int ex_stat, char *message);
void mlx_functions(t_game *game);

#endif
