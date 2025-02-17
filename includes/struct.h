/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <ineimatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:26:57 by ineimatu          #+#    #+#             */
/*   Updated: 2025/02/17 16:21:25 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//struct of map 
//struct of player or have everything in one struct.
//we basically need *mlx
//*mlx_win
//*player - for connecting with img
//*wall -same
//size_t of position of player in x and y 
//**matrix of game to save map inside of our game
//we would also need height, length of the map. 
//and i think we woulld have to use flood_fill function to check if the map is valid to play and the player is not stuck. lets see how we are handeling this 

#ifndef STRUCT_H
#define STRUCT_H


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
	t_files			sprite[10];
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

typedef struct s_image 
{
	void			*img_add;
	char			*pix_add;
	int				bit_pix;
	int				length_line;
	int				endian;
}				t_image;

typedef struct s_player
{
	double				position_x;
	double				position_y;
	int				angle;
	char			news;
}              t_player;

typedef struct s_ray
{
	double	player_x;
	double	player_y;
	double	angle_start;
	double	angle_end;
	int FOV;
	double dist_h;
	double dist_v;
	double dist_t_wall;
	int		map_x;
	int		map_y;
	double	wall_height;
	int		ceiling_floor;
}				t_ray;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_window;
	t_map			*map;
	t_player		player;
	t_ray			ray;
	t_image			*image;
	//struct timeval	timer;
	t_files			texture[4];
	t_door			doors;
}			   t_data;

#endif