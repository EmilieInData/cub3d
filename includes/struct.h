/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:26:57 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/20 14:13:14 by ineimatu         ###   ########.fr       */
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

/*typedef struct s_img //if it's in pixels we will need that structure
{
	void			*img_add;
	char			*pix_add;
	int				bit_pix;
	int				length_line;
	int				endian;
}				t_img;*/

typedef struct s_player
{
	int				position_x;
	int				position_y;
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
	double dist_t_wall[1200];
}				t_ray;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_window;
	t_map			*map;
	t_player		player;
	t_ray			ray;
	//t_img			*image;
}			   t_data;

#endif