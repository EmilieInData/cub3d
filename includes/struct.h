/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:26:57 by esellier          #+#    #+#             */
/*   Updated: 2025/02/07 19:09:37 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_files
{
	void			*img;
	int				width;
	int				height;
}			   t_files;

typedef	struct s_door
{
	int				x;
	int				y;
	int				flag;
	int				count;
	t_files			sprite[PICS];
}			   t_door;

typedef struct s_color
{
	int				red;
	int				green;
	int				blue;
}			   t_color;

typedef struct s_map
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	t_color			floor;
	t_color			ceiling;
	char			**matrix;
	int				flag;
}			   t_map;

typedef struct s_player
{
	char			news;
	int				angle;
	int				position_x;
	int				position_y;
}              t_player;

typedef struct s_image
{
	void			*img_add;
	char			*pix_add;
	int				bit_pix;
	int				length_line;
	int				endian;
}			   t_image;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_window;
	t_map			*map;
	t_player		player;
	t_image			*image;
	struct timeval	timer;
	t_files			texture[4];
	t_door			doors;
}			   t_data;
