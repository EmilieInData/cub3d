/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:26:57 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/09 19:59:33 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

X//struct of map 
X//struct of player or have everything in one struct.
//we basically need *mlx
//*mlx_win
//*player - for connecting with img
//*wall -same
X//size_t of position of player in x and y 
//**matrix of game to save map inside of our game
X//we would also need height, length of the map. 
//and i think we woulld have to use flood_fill function to check if the map is valid to play and the player is not stuck. lets see how we are handeling this 

typedef struct s_map
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_r;
	int				c_g;
	int				c_b;
	char			**array;
	unsigned int	s_height; // to_define ?
	unsigned int	s_length; // to_define ?
}			   t_map;

typedef struct s_player
{
	int				position_x;
	int				position_y;
}			   t_player;

typedef struct s_data
{
	t_map		map;
	t_player	player;
}			   t_data;



my fractol structs : 
/*
# define WIDTH	800
# define HEIGHT	800
# define ITERATIONS	40

typedef struct s_num
{
	double	x; //real
	double	y; // imaginary
}				t_num;

typedef struct s_img
{
	void	*img_add;
	char	*pix_add;
	int		bit_pix;
	int		length_line;
	int		endian;
}				t_img;

typedef struct s_data
{
	char	*name;
	int		range;
	void	*init;
	void	*window;
	t_img	*image;
	double	move_x;
	double	move_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_data;
*/