/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:22:59 by ineimatu          #+#    #+#             */
/*   Updated: 2025/01/14 11:41:10 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	mlx_functions(t_game *game)
{
	game->mlx= mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width, game->height, "cub3D");
	mlx_pixel_put(game->mlx, game->mlx_win, 8, 12, 0x0000FF00);	
	mlx_hook(game->mlx_win, 17, (1L << 0), (void *)exit, 0);
	mlx_loop(game->mlx);
}

